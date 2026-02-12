#include <Wire.h>
#include <TLx493D_inc.hpp>

using namespace ifx::tlx493d;


// Sample timer
const int f_s = 50; // Hz -> Unødvendig med høyere frekvenser mens sensorene testes
unsigned long prev_time = 0;
const int T = round(1e6 / f_s);

// Sensorer
TLx493D_A1B6 Sensor = TLx493D_A1B6(Wire, TLx493D_IIC_ADDR_A0_e);

// Målinger
double bx = 0, by = 0, bz = 0;

void setup() {
  // Start seriell komunikasjon
  Serial.begin(115200);
  Serial.println("Initialization...");

  // Sett I2C-frekvens til 400kHz
  //I2C er kommunikasjonslinja mellom sensoren og Teensy'en
  Wire.begin();
  Wire.setClock(400000);
  delay(20);

  // Initialiser sensoren
  bool initialized = false;
  initialized = Sensor.begin() && Sensor.isFunctional();
  //I tillegg til å starte sensoren, returnerer disse funksjonene en
  //boolsk verdi vi kan bruke til feilsøking
  if(!initialized)
  {
    Serial.println("Failed to initialize sensor, restart Teensy");
  }
  else
  {
    Serial.println("Sensor initialized successfully");
  }
  delay(500);

  // Initialiser tidsstempelet
  prev_time = micros();
}

void loop() {
  unsigned long time_now = micros();

  // Sjekk om det har gått T mikrosekunder siden sist sensoren ble målt
  if (time_now - prev_time >= T) {
    prev_time = micros(); // Nullstill tidsstempelet

    // Les sensoren. Funksjonen bruker pass by reference
    //til å lagre sensormålingene i variablene deklarert
    //i toppen av skriptet
    Sensor.getMagneticField(&bx, &by, &bz);

    // Skriv ut magnetsensordata for hver akse. Formatet blir
    //en slags manuelt formatert CSV som som seriell-plotteren
    //kan lage en graf av
    Serial.print("Bx:");
    Serial.print(bx);
    Serial.print(',');
    Serial.print("By:");
    Serial.print(by);
    Serial.print(',');
    Serial.print("Bz:");
    Serial.println(bz);
  }
}
