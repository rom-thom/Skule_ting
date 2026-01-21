/*******************************************************************************
 * Maggy V4.x - Magnetic Levitation System - PD Controller Implementation
 * 
 * This sketch implements a digital control system for magnetic levitation using
 * multiple hall effect sensors (TLV493D) and solenoid actuators. The system:
 * 
 * - Uses multiple hall effect sensors to detect magnet position
 * - Applies a PD (Proportional-Derivative) control algorithm
 * - Compensates for feedthrough effects from solenoid actuation
 * - Includes automatic sensor calibration and fault recovery
 * 
 * ADJUSTABLE PARAMETERS:
 * 
 * Control Parameters:
 * - Kp: Proportional gain. Increase for stiffer control, reduce for softer.
 * - Kd: Derivative gain. Increase to reduce oscillation, but too high 
 *       can cause instability.
 * 
 * Filtering Parameters:
 * - ALPHA: Magnetic field reading filter constant (0-1).
 *          Lower values = more filtering, higher = faster response.
 * - DALPHA: Derivative filter constant (0-1).
 *           Lower values = smoother derivative, higher = faster response.
 * 
 * Timing Parameters:
 * - sensorFrequency: How often sensors are read (Hz)
 * - controlFrequency: How often control updates are applied (Hz)
 * 
 * Hardware Configuration:
 * - SENSOR_CHANNELS array: Maps sensors to multiplexer channels
 * - PRIMARY_SENSOR_INDEX (in definitions.h): Index of primary sensor used for control
 * 
 * TUNING GUIDELINES:
 * 
 * If the system exhibits oscillations:
 * - Increase Kd or decrease Kp
 * - Decrease ALPHA and DALPHA for more filtering
 * 
 * If the system responds sluggishly:
 * - Increase Kp or decrease Kd
 * - Increase ALPHA and DALPHA for less filtering
 * 
 * KNOWN ISSUES:
 * 
 * Sensor Dropouts:
 * - The hall effect sensors occasionally experience communication failures
 *   when the solenoids are actuated, especially during rapid changes in current.
 * - This is likely due to electromagnetic interference or power supply fluctuations
 *   from the solenoids affecting the I2C communication with the sensors.
 * - It also seems to be something with the multiplexer
 * - The system includes automatic detection and recovery from these dropouts.
 * - To minimize dropouts:
 *   - Reduce the I2C speed in the initializeSensors function
 *   - Consider reducing the control frequency
 *   - Might need updates to the circuit (capacitors, isolation, ferrite rings)
 *******************************************************************************/

// Main sketch file for magnetic levitation PD controller
#include "definitions.h"    
#include "functions.h"

// Control parameters
constexpr float Kp = COIL_POL * 0;
constexpr float Kd = COIL_POL * 0;
constexpr float ALPHA = 0.3;
constexpr float DALPHA = 0.2;

// Calibration values
const double DIRECT_FEEDTHROUGH_SLOPE_X_POSITIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_X_NEGATIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_Y_POSITIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_Y_NEGATIVE = 0;

const double DIRECT_FEEDTHROUGH_SLOPE_ZX_POSITIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_ZX_NEGATIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_ZY_POSITIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_ZY_NEGATIVE = 0;

const double MEAN_BX = 0;
const double MEAN_BY = 0;
const double MEAN_BZ = 0;

// Sensor object, requires the specified library
TLx493D_A1B6 Sensor = TLx493D_A1B6(Wire, TLx493D_IIC_ADDR_A0_e);

// Timing parameters
constexpr float sensorFrequency = SENS_FREQUENCY; //default 5k, possibly incompatible with 100k I2C
constexpr int sensorInterval = round(1e6 / sensorFrequency);
constexpr float controlFrequency = CTRL_FREQUENCY; //default 5k
constexpr int controlInterval = round(1e6 / controlFrequency);

// Timing variables
unsigned long prevSensorTime = 0;
unsigned long prevControlTime = 0;
float realSamplingFreq = 0;
int controlLoopCounter = 0;

// Control variables
float magFieldX = 0, magFieldY = 0, magFieldZ = 0;
float prevMagFieldX = 0, prevMagFieldY = 0, prevMagFieldZ = 0;
float dMagFieldX = 0, dMagFieldY = 0;
float currentXPos = 0, currentXNeg = 0, currentYPos = 0, currentYNeg = 0;
float pwmInputX = 0, pwmInputY = 0;
float prevPwmInputX = 0, prevPwmInputY = 0;

float rawMagField[3] = {0};
float calibratedMagField[3] = {0}; // Detrended measurements

// Sensor management functions
void readSensor()
{

  delayMicroseconds(50);          // let the bus lines settle

  double x, y, z;
  if (Sensor.getMagneticField(&x, &y, &z))
  {
    rawMagField[0] = static_cast<float>(x);
    rawMagField[1] = static_cast<float>(y);
    rawMagField[2] = static_cast<float>(z);
  }
    
}


void processSensorData(float currentXPos, float currentXNeg, float currentYPos, float currentYNeg) {
  // Process all sensor data

  // Apply feedthrough compensation for each axis by subtracting linear values
  //found in the calibration phases
  calibratedMagField[0] = rawMagField[0] 
                          - MEAN_BX 
                          - DIRECT_FEEDTHROUGH_SLOPE_X_POSITIVE * currentXPos 
                          - DIRECT_FEEDTHROUGH_SLOPE_X_NEGATIVE * currentXNeg;
  
  calibratedMagField[1] = rawMagField[1] 
                          - MEAN_BY 
                          - DIRECT_FEEDTHROUGH_SLOPE_Y_POSITIVE * currentYPos 
                          - DIRECT_FEEDTHROUGH_SLOPE_Y_NEGATIVE * currentYNeg;
  
  calibratedMagField[2] = rawMagField[2] 
                          - MEAN_BZ 
                          - DIRECT_FEEDTHROUGH_SLOPE_ZX_POSITIVE * currentXPos 
                          - DIRECT_FEEDTHROUGH_SLOPE_ZX_NEGATIVE * currentXNeg 
                          - DIRECT_FEEDTHROUGH_SLOPE_ZY_POSITIVE * currentYPos 
                          - DIRECT_FEEDTHROUGH_SLOPE_ZY_NEGATIVE * currentYNeg;
}

void setup(){
  Serial.begin(115200);
  delay(50);

  initializeSensors();
  delay(50);

  initializeSolenoids();
  delay(50);

}

void loop(){
  unsigned long timeNow = micros();

  // Sensor reading and processing loop
  if(timeNow - prevSensorTime >= (unsigned long)sensorInterval){
    unsigned long dt = timeNow - prevSensorTime;
    if(dt > 0) realSamplingFreq = 1e6 / (float)dt;

    //Electric current draw for each direction in the X and Y axes,
    //not "the current position in the X axis" or some such
    currentXPos = getSolenoidCurrent(CURRENT_X_POS);
    currentXNeg = getSolenoidCurrent(CURRENT_X_NEG);
    currentYPos = getSolenoidCurrent(CURRENT_Y_POS);
    currentYNeg = getSolenoidCurrent(CURRENT_Y_NEG);

    // Read sensor and process data
    readSensor();
    processSensorData(currentXPos, currentXNeg, currentYPos, currentYNeg);

    //Supress spikes by averaging with the previous measurement
    magFieldX = ALPHA * calibratedMagField[0] + (1.0 - ALPHA) * prevMagFieldX;
    magFieldY = ALPHA * calibratedMagField[1] + (1.0 - ALPHA) * prevMagFieldY;
    magFieldZ = calibratedMagField[2];

    //Spike supression is even more important for the derivative. (Why?)
    if(dt > 0){
      dMagFieldX = DALPHA * ((magFieldX - prevMagFieldX) / (float)dt * 1e6) + (1.0 - DALPHA) * dMagFieldX;
      dMagFieldY = DALPHA * ((magFieldY - prevMagFieldY) / (float)dt * 1e6) + (1.0 - DALPHA) * dMagFieldY;
    }

    //Finally, update previous values
    prevMagFieldX = magFieldX;
    prevMagFieldY = magFieldY;
    prevMagFieldZ = magFieldZ;
    prevSensorTime = timeNow;
  }

  // Control loop
  if(timeNow - prevControlTime >= (unsigned long)controlInterval){
    if(fabs(magFieldZ) > 5){
      // Calculate and apply control signals directly
      pwmInputX = constrain(Kp * magFieldX + Kd * dMagFieldX, -150, 150);
      pwmInputY = constrain(Kp * magFieldY + Kd * dMagFieldY, -150, 150);
    } else {
      // When magnet is too far, set control signals to zero
      pwmInputX = 0;
      pwmInputY = 0;
    }

    applyControlSignals(pwmInputX, pwmInputY);

    prevPwmInputX = pwmInputX;
    prevPwmInputY = pwmInputY;

    controlLoopCounter++;
    prevControlTime = timeNow;

  }

  //Write information to the serial plotter and/or monitor
  if(controlLoopCounter % 100 == 0){
    Serial.print("ux:");
    Serial.print(pwmInputX);
    Serial.print(",uy:");
    Serial.print(pwmInputY);
    Serial.print(",top:");
    Serial.print(160);
    Serial.print(",bottom:");
    Serial.print(-160);
    Serial.print(',');
    Serial.print("Ix_plus:");
    Serial.print(currentXPos, 6);
    Serial.print(",Ix_minus:");
    Serial.print(currentXNeg, 6);
    Serial.print(",Iy_plus:");
    Serial.print(currentYPos, 6);
    Serial.print(",Iy_minus:");
    Serial.print(currentYNeg, 6);
    
    // Dynamically log data from all active sensors
    Serial.print(",bx:");
    Serial.print(calibratedMagField[0], 6);
    
    Serial.print(",by:");
    Serial.print(calibratedMagField[1], 6);
    
    Serial.print(",bz:");
    
    // Add newline only after the last value
    Serial.println(calibratedMagField[2], 6);
  }
} 