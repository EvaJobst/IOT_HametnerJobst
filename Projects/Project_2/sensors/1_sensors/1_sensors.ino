#include <Wire.h>
#include <VL53L0X.h>

// Pinout
#define analogPin A0 // Analog Rain Pin
#define rainPin D0 //Rain sensor
#define echoPin D4 // Echo Pin
#define trigPin D3 // Trigger Pin

// Storing values
int counter = 0;
int containerHeight = 10;

VL53L0X sensor;

void setup() {
  Serial.begin(115200); //initialize the serial monitor
  printHeader();
  
  // Rain sensor
  pinMode(rainPin,INPUT); //set digitalPin as INPUT
  
  // Acoustic distance
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Optical distance
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}

void loop() {
  bool isConductive = readDigitalRainSensor();
  uint16_t oDistance = readOpticalDistance();
  long aDistance = readAcousticDistance();
  int aHeight = containerHeight - aDistance;
  int oHeight = containerHeight - oDistance;
  int rainHeight = readAnalogRainSensor();
  printValues(oDistance, aDistance, oHeight, aHeight, rainHeight, isConductive);
  counter++;
  delay(2000);
}

void printHeader() {
  Serial.println("|Nr.|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height | Rain Height | Is Conductive|");
  Serial.println("|----|----|----|----|----|----|----|");
}

void printValues(uint16_t oDistance, long aDistance, int oHeight, int aHeight, int rainHeight, bool isConductive) {
  Serial.print("| ");
  Serial.print(counter);
  Serial.print(" | ");
  Serial.print(oDistance);
  Serial.print(" cm | ");
  Serial.print(aDistance);
  Serial.print(" cm |");
  Serial.print(oHeight);
  Serial.print(" cm |");
  Serial.print(aHeight);
  Serial.print(" cm |");
  Serial.print(rainHeight);
  Serial.print(" cm |");

  if(!isConductive) {
    Serial.print("True |");
  }

  else {
    Serial.print("False |");
  }

  Serial.println();
}

long readAcousticDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
  return duration/58.2;
}

uint16_t readOpticalDistance() {
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  return sensor.readRangeContinuousMillimeters()/10;
}

bool readDigitalRainSensor() {
  return digitalRead(rainPin);
}

int readAnalogRainSensor() {
  //CorrectedValue = (((RawValue – RawLow) * ReferenceRange) / RawRange) + ReferenceLow
  return analogRead(analogPin);
}
