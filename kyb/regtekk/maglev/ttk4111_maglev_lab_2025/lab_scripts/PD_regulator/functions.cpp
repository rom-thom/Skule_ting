#include "functions.h"

extern TLx493D_A1B6 Sensor;
// Solenoid-related functions

float getSolenoidCurrent(uint16_t pin) {
  uint16_t data = analogRead(pin);
  float voltage = (data*3.3)/1023.0;     // ADC to voltage
  float voltage_diff = voltage - 1.65;       // Centered around 1.65V (no current)
  float current = voltage_diff/(100.0*0.015); // Gain = 100 (INA214), Rshunt = 0.015Ω
  return current;
}

void setSolenoidInput(int pwm, int pin1, int pin2) {
  if (pwm > 0) {
    analogWrite(pin1, 255 - abs(pwm));
    analogWrite(pin2, 255);
  } else if (pwm < 0) {
    analogWrite(pin1, 255);
    analogWrite(pin2, 255 - abs(pwm));
  } else {
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
  }
}

void applyControlSignals(float pwmInputX, float pwmInputY) {
  setSolenoidInput(pwmInputX, MD2_IN1, MD2_IN2);
  setSolenoidInput(-pwmInputX, MD3_IN1, MD3_IN2);
  setSolenoidInput(pwmInputY, MD4_IN1, MD4_IN2);
  setSolenoidInput(-pwmInputY, MD1_IN1, MD1_IN2);
}

// Setup-related functions
void initializeSerial() {
  Serial.begin(115200);
}

// Robust initialization with bus clearing and retries
void initializeSensors() {
  // Clear the I2C bus first for reliability
  clearI2CBus();
  delay(50);
  
  // Initialize I2C communication
  Wire.begin();
  Wire.setClock(I2C_FREQUENCY);
  delay(50);
  
  delay(10);
  // Initialize each sensor on its respective channel
  // Attempt sensor initialization with retries
  const int maxRetries = 5;
  bool initialized = false;
  for (int retry = 0; retry < maxRetries && !initialized; ++retry)
  {
    initialized =  Sensor.begin() && Sensor.isFunctional();
    // Sensors[i].setPowerMode(TLx493D_FAST_MODE_e); // Fast mode will be more noisy, but can sample faster. Requires 1Mhz wire speed. This is not supported by the MUX.
    // Sensors[i].setSensitivity(TLx493D_FULL_RANGE_e);

    if (!initialized)
    {
      Serial.printf("Retrying sensor ... attempt %d\n",
                    retry + 1);
      delay(20);
    }
  }
  if (!initialized) {
    Serial.println("Failed to initialize sensor.");
  } else {
    Serial.println("Sensor initialized successfully.");
  }
  
  // Reinitialize I2C after sensor setup to ensure stable communication
  Wire.begin();
  Wire.setClock(I2C_FREQUENCY);
  delay(50);
}

void clearI2CBus() {
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);

  digitalWrite(SDA, HIGH);
  digitalWrite(SCL, HIGH);
  delay(10);

  for (int i = 0; i < 9; i++) {
    digitalWrite(SCL, LOW);
    delayMicroseconds(10);
    digitalWrite(SCL, HIGH);
    delayMicroseconds(10);
  }

  // Generate STOP condition
  digitalWrite(SDA, LOW);
  delayMicroseconds(10);
  digitalWrite(SCL, HIGH);
  delayMicroseconds(10);
  digitalWrite(SDA, HIGH);
  delayMicroseconds(10);
}


void initializeSolenoids() {
  // Defining bit-size on read/write operations
  analogWriteResolution(8);
  analogReadResolution(10);

  // Set pin modes
  pinMode(MD1_IN1, OUTPUT);
  pinMode(MD1_IN2, OUTPUT);
  pinMode(MD2_IN1, OUTPUT);
  pinMode(MD2_IN2, OUTPUT);
  pinMode(MD3_IN1, OUTPUT);
  pinMode(MD3_IN2, OUTPUT);
  pinMode(MD4_IN1, OUTPUT);
  pinMode(MD4_IN2, OUTPUT);

  pinMode(CURRENT_Y_POS, INPUT);
  pinMode(CURRENT_X_NEG, INPUT);
  pinMode(CURRENT_X_POS, INPUT);
  pinMode(CURRENT_Y_NEG, INPUT);

  // Defining PWM frequency - using standard 31250 Hz
  analogWriteFrequency(MD1_IN1, 31250);
  analogWriteFrequency(MD1_IN2, 31250);
  analogWriteFrequency(MD2_IN1, 31250);
  analogWriteFrequency(MD2_IN2, 31250);
  analogWriteFrequency(MD3_IN1, 31250);
  analogWriteFrequency(MD3_IN2, 31250);
  analogWriteFrequency(MD4_IN1, 31250);
  analogWriteFrequency(MD4_IN2, 31250);

  // Setting initial state to 0
  digitalWrite(MD1_IN1, LOW);
  digitalWrite(MD1_IN2, LOW);
  digitalWrite(MD2_IN1, LOW);
  digitalWrite(MD2_IN2, LOW);
  digitalWrite(MD3_IN1, LOW);
  digitalWrite(MD3_IN2, LOW);
  digitalWrite(MD4_IN1, LOW);
  digitalWrite(MD4_IN2, LOW);
}

