#include <TLx493D_inc.hpp>
#include <Wire.h>

using namespace ifx::tlx493d;

// Sample timer
const double f_s = 5000; // Hz
const int T = round(1e6 / f_s);
unsigned long prev_time = 0;

// Sensors
TLx493D_A1B6 Sensor = TLx493D_A1B6(Wire, TLx493D_IIC_ADDR_A0_e);

// Motor driver pins
#define MD1_IN1 4
#define MD1_IN2 5
#define MD2_IN1 2
#define MD2_IN2 3
#define MD3_IN1 6
#define MD3_IN2 7
#define MD4_IN1 8
#define MD4_IN2 9

// Current sensor pins
#define CURRENT_Y_POS 20
#define CURRENT_X_NEG 21
#define CURRENT_X_POS 22
#define CURRENT_Y_NEG 23

//Virkning av elektromagnetene på sensoren
double DIRECT_FEEDTHROUGH_SLOPE_X_POSITIVE = 0;
double DIRECT_FEEDTHROUGH_SLOPE_X_NEGATIVE = 0;
double DIRECT_FEEDTHROUGH_SLOPE_Y_POSITIVE = 0;
double DIRECT_FEEDTHROUGH_SLOPE_Y_NEGATIVE = 0;
double DIRECT_FEEDTHROUGH_SLOPE_ZX_POSITIVE = 0;
double DIRECT_FEEDTHROUGH_SLOPE_ZX_NEGATIVE = 0;
double DIRECT_FEEDTHROUGH_SLOPE_ZY_POSITIVE = 0;
double DIRECT_FEEDTHROUGH_SLOPE_ZY_NEGATIVE = 0;

float meanMagField[3] = {0}; //Virkning av permanentmagneter

void control_solenoid(int solenoid_num, int u) {
  int IN1, IN2;
  switch (solenoid_num) {
    case 0: //X+
      IN1 = MD2_IN1;
      IN2 = MD2_IN2;
      break;
    case 1: //X-
      IN1 = MD3_IN1;
      IN2 = MD3_IN2;
      break;
    case 2: //Y+
      IN1 = MD4_IN1;
      IN2 = MD4_IN2;
      break;
    case 3: //Y-
      IN1 = MD1_IN1;
      IN2 = MD1_IN2;
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

float get_solenoid_input(uint16_t pin) {
  uint16_t data = analogRead(pin);
  float voltage = (data*3.3)/1023.0;     // ADC to voltage
  float voltage_diff = voltage - 1.65;       // Centered around 1.65V (no current)
  float current = voltage_diff/(100.0*0.015); // Gain = 100 (INA214), Rshunt = 0.015Ω
  return current;
}

void calibrate_sensors(){
  Serial.println("Finner gjennomsnittsverdier av magfelt...");

  int SAMPLES = 1000;
  //Gjør SAMPLES avlesninger av sensoren for hver akse
  for (int n = 0; n < SAMPLES; ++n)
  {
    double x, y, z;
    if (Sensor.getMagneticField(&x, &y, &z))
    {
      meanMagField[0] += static_cast<float>(x);
      meanMagField[1] += static_cast<float>(y);
      meanMagField[2] += static_cast<float>(z);

      //Fun fact: godt skrevne funksjoner inneholder sikringer
      //mot at feil returdata kræsjer programmet. Her vil
      //getMagneticField returnere 0 dersom målingene var
      //mislykket, som gjør det praktisk å kalle funksjonen
      //fra en if-setning. Den kan da tolkes som "utfør klausulen
      //dersom funksjonen returnerer noe annet enn 0".
    }

    delay(1);
  }

  //Ta gjennomsnitt av avlesningene fra hver akse ved å
  //dele summen på antallet avlesninger
  meanMagField[0] /= SAMPLES;
  meanMagField[1] /= SAMPLES;
  meanMagField[2] /= SAMPLES;

  Serial.print("Funnet gjennomsnittsverdier: X = ");
  Serial.print(meanMagField[0]);
  Serial.print(", Y = ");
  Serial.print(meanMagField[1]);
  Serial.print(", Z = ");
  Serial.println(meanMagField[2]);
}

void calibrate_direct_feedthrough(){
  Serial.println("Kalibrerer foroverkobling av magnetfelt");

  //Kalibreringsparametre
  const int segTime = 100;
  const int settleDelay = 50;
  const int numLevels = 3;
  float currentLevels[numLevels] = {50, 100, 150};

  //Beskrivelse av solenoidenes egenskaper
  struct SolenoidConfig{
    uint8_t in1;        //styresignal 1
    uint8_t in2;        //styresignal 2
    int currentChannel; //strømmåling
    bool isPositive;    //polaritet
  };

  //Beskrivelse av solenoidene
  const SolenoidConfig solenoidConfigs[4] = {
    { MD2_IN1, MD2_IN2, CURRENT_X_POS, true  }, // X+
    { MD3_IN1, MD3_IN2, CURRENT_X_NEG, false }, // X-
    { MD4_IN1, MD4_IN2, CURRENT_Y_POS, true  }, // Y+
    { MD1_IN1, MD1_IN2, CURRENT_Y_NEG, false }  // Y-
  };

  //Informasjonsbeholdere for kalibreringen
  float sumSensor[3][4] = {0}; //akser X=0, Y=1, Z=2; Solenoider 0-3
  float sumCurrent[4] = {0};
  int counts[4] = {0};

  ////////////////////////////////////////////////////
  //FASE 1: MÅL STRØM OG MAGNETFELT I HVER SOLENOIDE//
  ////////////////////////////////////////////////////
  for (int solenoid = 0; solenoid < 4; ++solenoid)
  {
    Serial.print("Kalibrerer foroverkobling for solenoide ");
    Serial.println(solenoid);

    for (int level = 0; level < numLevels; ++level)
    {
      const unsigned pwm = currentLevels[level]; //PWM-nivå mellom 0 og 255
      control_solenoid(solenoid, pwm);
      delay(settleDelay); //La solenoiden stabilisere seg (Husk: RL-krets!)

      const unsigned long t0 = millis(); //Marker tidspunkt
      while (millis() - t0 < segTime) //Mål strøm i segTime millisekunder
      {
        //Mål strøm og legg til i måling
        const float I = get_solenoid_input(solenoidConfigs[solenoid].currentChannel);
        sumCurrent[solenoid] += I;

        double x, y, z;
        //Forsøk å måle magnetfelt og lagre i x,y,z        
        if (Sensor.getMagneticField(&x, &y, &z))
        {
          //Summer målingene for hver akse og solenoide
          sumSensor[0][solenoid] += static_cast<float>(x);
          sumSensor[1][solenoid] += static_cast<float>(y);
          sumSensor[2][solenoid] += static_cast<float>(z);
        }

        ++counts[solenoid];
        delay(10); //segTime/delay => ca 10 målinger per solenoide per nivå
      }
      
      //Skru av solenoiden og vent litt før neste målenivå
      control_solenoid(solenoid, 0);
      delay(settleDelay);
    }
  }

  /////////////////////////////////////////////////////////////
  //FASE 2: FINN LINEÆR SAMMENHENG MELLOM STRØM OG MAGNETFELT//
  /////////////////////////////////////////////////////////////
  for (int solenoid = 0; solenoid < 4; ++solenoid)
  {
    Serial.print("Kalibreringsverdier for solenoide nummer ");
    Serial.print(solenoid);

    if (counts[solenoid] == 0)
    {
      Serial.println(": TOMME MÅLINGER");
      continue; //Hopp over denne solenoiden hvis alle målingene er tomme
    }

    //Gjennomsnitsstrøm for solenoiden
    const float Iavg = sumCurrent[solenoid] / counts[solenoid];

    //Påvirkning av strøm på Z-akse
    const float Sz = sumSensor[2][solenoid] / counts[solenoid];
    const float kZ = (Sz - meanMagField[2]) / Iavg;

    
    //For de andre aksene må vi stykke opp beregningene per solenoide
    if(solenoid == 0) //X+
    {
      const float Sx = sumSensor[0][solenoid] / counts[solenoid];
      const float k = (Sx - meanMagField[0]) / Iavg;
      DIRECT_FEEDTHROUGH_SLOPE_X_POSITIVE = -k;
      DIRECT_FEEDTHROUGH_SLOPE_ZX_POSITIVE = -kZ;

      Serial.print(": k = ");
      Serial.print(k);
    }

    

    if(solenoid == 1) //X-
    {
      const float Sx = sumSensor[0][solenoid] / counts[solenoid];
      const float k = (Sx - meanMagField[0]) / Iavg;
      DIRECT_FEEDTHROUGH_SLOPE_X_NEGATIVE = -k;
      DIRECT_FEEDTHROUGH_SLOPE_ZX_NEGATIVE = -kZ;      

      Serial.print(": k = ");
      Serial.print(k);
    }

    if(solenoid == 2) //Y+
    {
      const float Sy = sumSensor[1][solenoid] / counts[solenoid];
      const float k = (Sy - meanMagField[1]) / Iavg;
      DIRECT_FEEDTHROUGH_SLOPE_Y_POSITIVE = -k;
      DIRECT_FEEDTHROUGH_SLOPE_ZY_POSITIVE = -kZ;      

      Serial.print(": k = ");
      Serial.print(k);
    }

    if(solenoid == 3) //Y-
    {
      const float Sy = sumSensor[1][solenoid] / counts[solenoid];
      const float k = (Sy - meanMagField[1]) / Iavg;
      DIRECT_FEEDTHROUGH_SLOPE_Y_NEGATIVE = -k;
      DIRECT_FEEDTHROUGH_SLOPE_ZY_NEGATIVE = -kZ;      

      Serial.print(": k = ");
      Serial.print(k);
    }

    Serial.print(", kZ = ");
    Serial.println(kZ);



  }
}

void setup() {
  // Initialize serial
  Serial.begin(115200);
  Serial.println("Initialization...");

  // Initialize sensor
  Sensor.begin();

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

  // Define current sensor pins
  pinMode(CURRENT_Y_POS, INPUT);
  pinMode(CURRENT_X_NEG, INPUT);
  pinMode(CURRENT_X_POS, INPUT);
  pinMode(CURRENT_Y_NEG, INPUT);

  // Set I2C frequency to 1MHz
  Wire.begin();
  Wire.setClock(1000000); 

}


void loop() {
  unsigned long current_time = micros();
  if (current_time - prev_time >= T) {
    prev_time = current_time;

    calibrate_sensors();

    calibrate_direct_feedthrough();

    Serial.println("#############################################");
  }
}
