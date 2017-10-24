#include <Wire.h>
#include <VL53L0X.h>

// Pinout
#define rainPin D0 //Rain sensor
#define echoPin D4 // Echo Pin
#define trigPin D3 // Trigger Pin
#define reedPin D5 // Reed Pin

// Storing values
int counter = 0;
int containerHeight = 10;

VL53L0X sensor;

void setup() {
  Serial.begin(115200); //initialize the serial monitor
  printHeader();

  // Reed switch
  pinMode(reedPin, INPUT);
  
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
  bool isFull = readReedSwitch();
  uint16_t oDistance = readOpticalDistance();
  long aDistance = readAcousticDistance();
  int aHeight = containerHeight - aDistance;
  int oHeight = containerHeight - oDistance;
  printValues(oDistance, aDistance, oHeight, aHeight, isConductive, isFull);
  counter++;
  delay(2000);
}

void printHeader() {
  Serial.println("|Nr.|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height | Is Conductive | Is Full |");
  Serial.println("|----|----|----|----|----|----|----|");
}

void printValues(uint16_t oDistance, long aDistance, int oHeight, int aHeight, bool isConductive, bool isFull) {
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

  if(!isConductive) {
    Serial.print(" True |");
  }

  else {
    Serial.print(" False |");
  }

  if(!isFull) {
    Serial.print(" True |");
  }

  else {
    Serial.print(" False |");
  }

  Serial.println();
}

bool readReedSwitch() {
  return digitalRead(reedPin);  
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
