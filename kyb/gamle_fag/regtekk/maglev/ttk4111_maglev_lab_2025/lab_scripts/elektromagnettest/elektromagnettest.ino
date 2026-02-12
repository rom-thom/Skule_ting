#include <TLx493D_inc.hpp>
#include <Wire.h>

using namespace ifx::tlx493d;



// ############# TO BE MODIFIED ###########
const double DIRECT_FEEDTHROUGH_SLOPE_X_POSITIVE = -0.2;
const double DIRECT_FEEDTHROUGH_SLOPE_X_NEGATIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_Y_POSITIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_Y_NEGATIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_ZX_POSITIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_ZX_NEGATIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_ZY_POSITIVE = 0;
const double DIRECT_FEEDTHROUGH_SLOPE_ZY_NEGATIVE = 0;


// Mean of measurements
float meanBx = 0;
float meanBy = 0;
float meanBz = 0;

const bool REMOVE_MEAN = true;
const bool REMOVE_DIRECT_FEEDTHROUGH = true;
// ########################################

// Sample timer
const int f_s = 50; // Sampling frequency in Hz
const unsigned long T_sample = round(1e6 / f_s); // Sampling interval in microseconds
const unsigned long T_switch = 1000000; // Switching interval in microseconds (1 Hz = 1000000)
unsigned long prev_time = 0;
unsigned long prev_time_switch = 0;

// Counters
int solenoid_index = 0;
int magnetization_index = 0;

// Sensors
TLx493D_A1B6 Sensor = TLx493D_A1B6(Wire, TLx493D_IIC_ADDR_A0_e);


// Four motor drivers - IN1 and IN2 are PWM inputs. Polarity of the output is set based on which one of them is active.
//// Motor driver 1 Y-
#define MD1_IN1 4//3
#define MD1_IN2 5//2

//// Motor driver 2 X+
#define MD2_IN1 2//5
#define MD2_IN2 3//4

//// Motor driver 3 X-
#define MD3_IN1 6//7
#define MD3_IN2 7//6

//// Motor driver 4 Y+
#define MD4_IN1 8//9
#define MD4_IN2 9//8

//(electric) Current sensor pins
#define CURRENT_Y_POS 20
#define CURRENT_X_NEG 21
#define CURRENT_X_POS 22
#define CURRENT_Y_NEG 23


// Inputs
int control_value = 0;

// Measurements
double bx = 0, by = 0, bz = 0;

void setup() {
  // Initialize serial
  Serial.begin(115200);
  Serial.println("Initialization...");

  // Set I2C frequency to 400kHz
  Wire.begin();
  Wire.setClock(400000);
  delay(20);

  // Initialize sensor
  bool initialized = false;
  initialized = Sensor.begin() && Sensor.isFunctional();
  if(!initialized)
  {
    Serial.println("Failed to initialize sensor, restart Teensy");
  }
  else
  {
    Serial.println("Sensor initialized successfully");
  }
  delay(500);

  // Initialize motor drivers
  analogWriteResolution(8);

  //// Set pin mode
  pinMode(MD1_IN1, OUTPUT);
  pinMode(MD1_IN2, OUTPUT);

  pinMode(MD2_IN1, OUTPUT);
  pinMode(MD2_IN2, OUTPUT);
  
  pinMode(MD3_IN1, OUTPUT);
  pinMode(MD3_IN2, OUTPUT);
  
  pinMode(MD4_IN1, OUTPUT);
  pinMode(MD4_IN2, OUTPUT);

  // Set PWM frequency to avoid audible tones
  analogWriteFrequency(MD1_IN1, 32258);
  analogWriteFrequency(MD1_IN2, 32258);

  analogWriteFrequency(MD2_IN1, 32258);
  analogWriteFrequency(MD2_IN2, 32258);

  analogWriteFrequency(MD3_IN1, 32258);
  analogWriteFrequency(MD3_IN2, 32258);

  analogWriteFrequency(MD4_IN1, 32258);
  analogWriteFrequency(MD4_IN2, 32258);

  //// Start with motor drivers off
  digitalWrite(MD1_IN1, LOW);
  digitalWrite(MD1_IN2, LOW);
  
  digitalWrite(MD2_IN1, LOW);
  digitalWrite(MD2_IN2, LOW);
  
  digitalWrite(MD3_IN1, LOW);
  digitalWrite(MD3_IN2, LOW);

  digitalWrite(MD4_IN1, LOW);
  digitalWrite(MD4_IN2, LOW);

  // Initialize previous time variables
  prev_time = micros();
  prev_time_switch = micros();

}


float getSolenoidCurrent(uint16_t pin) {
  uint16_t data = analogRead(pin);
  float voltage = (data*3.3)/1023.0;    
  float voltage_diff = voltage - 1.65;  
  float current = voltage_diff/(100.0*0.015);
  return current;
}


void control_solenoid(int solenoid_num, int u) {
  int IN1, IN2;
  switch (solenoid_num) {
    case 0:
      IN1 = MD1_IN1;
      IN2 = MD1_IN2;
      break;
    case 1:
      IN1 = MD2_IN1;
      IN2 = MD2_IN2;
      break;
    case 2:
      IN1 = MD3_IN1;
      IN2 = MD3_IN2;
      break;
    case 3:
      IN1 = MD4_IN1;
      IN2 = MD4_IN2;
      break;
    default:
      return;
  }

  if (u > 0){
    analogWrite(IN1, 255 - abs(u));
    analogWrite(IN2, 255);
  } 
  else if(u < 0) {
    analogWrite(IN1, 255);
    analogWrite(IN2, 255 - abs(u));
  }
  else{
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
  }
}

//This loop basically says "iterate through each solenoid,
//and give it a positive or negative magnetization". It also
//prints useful information to the serial plotter.
void loop() {
  unsigned long current_time = micros();

  // Check if sampling interval has passed
  if (current_time - prev_time >= T_sample) {
    prev_time += T_sample; // Reset timer for next interval

    // Update sensor measurements    
    Sensor.getMagneticField(&bx, &by, &bz);

    //Compensates for the permanent magnets
    if (REMOVE_MEAN) {
      bx -= meanBx;
      by -= meanBy;
      bz -= meanBz;
    }

    //Compensates for the solenoids
    if (REMOVE_DIRECT_FEEDTHROUGH) {

      float currentXPos = getSolenoidCurrent(CURRENT_X_POS);
      float currentXNeg = getSolenoidCurrent(CURRENT_X_NEG);
      float currentYPos = getSolenoidCurrent(CURRENT_Y_POS);
      float currentYNeg = getSolenoidCurrent(CURRENT_Y_NEG);

      if (solenoid_index == 0) //Y-
      {
        by -= DIRECT_FEEDTHROUGH_SLOPE_Y_NEGATIVE * currentYNeg;
        bz -= DIRECT_FEEDTHROUGH_SLOPE_ZY_NEGATIVE * currentYNeg;
      }
      else if (solenoid_index == 1) //X+
      {
        bx -= DIRECT_FEEDTHROUGH_SLOPE_X_POSITIVE * currentXPos;
        bz -= DIRECT_FEEDTHROUGH_SLOPE_ZX_POSITIVE * currentXPos;
      }
      else if (solenoid_index == 2) //X-
      {
        bx -= DIRECT_FEEDTHROUGH_SLOPE_X_NEGATIVE * currentXNeg;
        bz -= DIRECT_FEEDTHROUGH_SLOPE_ZX_NEGATIVE * currentXNeg;
      }
      else if (solenoid_index == 3) //Y+
      {
        by -= DIRECT_FEEDTHROUGH_SLOPE_Y_POSITIVE * currentYPos;
        bz -= DIRECT_FEEDTHROUGH_SLOPE_ZY_POSITIVE * currentYPos;
      }
    }

    // Print magnetic field data
    Serial.print("Bx:");
    Serial.print(bx);
    Serial.print(',');
    Serial.print("By:");
    Serial.print(by);
    Serial.print(',');
    Serial.print("Bz:");
    Serial.print(bz);
    Serial.print(',');
    Serial.print("Sol:");
    Serial.print(solenoid_index);
    Serial.print(',');

    //Unfiltered, the Bx and By signals should roughly follow
    //(or mirror!) the Mag signal
    Serial.print("Mag:");
    if (magnetization_index == 0 || magnetization_index == 3) Serial.print(0);
    if (magnetization_index == 1) Serial.print(1);
    if (magnetization_index == 2) Serial.print(-1);
    Serial.print(',');

    //Hacky way to make the plotter stay within
    //an interval on the y axis as a visual aid
    Serial.print("Top:");
    Serial.print(5);
    Serial.print(',');
    Serial.print("Bottom:");
    Serial.println(-5);
  }

  // Check if switching interval has passed
  if (current_time - prev_time_switch >= T_switch) {
    prev_time_switch += T_switch; // Reset timer for next interval

    //Decide which solenoid to control (sol.index), and
    //which control signal to give that solenoid (mag.index)
    magnetization_index += 1;
    if(magnetization_index > 3)
    {
      magnetization_index = 0;
      solenoid_index += 1;
    }

    if(solenoid_index > 3){
      solenoid_index = 0;
    }

    //Set a positive, negative or zero control value based on
    //the magnetization index
    if(magnetization_index == 0 || magnetization_index == 3)
    {
      control_value = 0;
    }
    else if(magnetization_index == 1)
    {
      control_value = 127;
    }
    else if(magnetization_index == 2)
    {
      control_value = -127;
    }

    // Control solenoids based on solenoid_index
    control_solenoid(solenoid_index, control_value);

  }
}
