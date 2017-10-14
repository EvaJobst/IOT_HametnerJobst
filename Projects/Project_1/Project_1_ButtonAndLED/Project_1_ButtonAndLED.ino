/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
// Button-Sensor:
const int buttonPin = 2;
bool buttonHasBeenPressed = true;
int buttonState = 0;

// LED-Actor: 
int greenPin = 15;
int redPin = 13;

// Buzzer-Actor:
int buzzerPin = 5;

int buzzerOn = 0; // 1 == ON und 0 == OFF
bool gasIsTrue = false;
bool flameIsTrue = false;

void setup() {
  Serial.begin(115200);
  Serial.println();
  // Button-Sensor:
  //pinMode(buttonPin, INPUT);

  // LED-Actor:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Buzzer-Actor:
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Button-Sensor:
  buttonState = digitalRead(buttonPin);

  
  if (buttonState == HIGH) {
    buttonHasBeenPressed = true;
  } else {
    if (buttonHasBeenPressed) {
    Serial.println("Button is pressed"); // send a HQTT-message that button is pressed
    buttonHasBeenPressed = false;
    }
  }

  // Buzzer-Actor:
  if (buzzerOn == 1) {
    analogWrite (buzzerPin, 255);
  }
  
  if (buzzerOn == 0) {
    analogWrite (buzzerPin, -1);
  }
  
  // to test
  gasIsTrue = false;
  flameIsTrue = false;
  unsigned int len = 10;
  char* t = "Topic";
  byte* p;
  LEDColor(t, p, len);
  buzzerOn = 1;
}

void LEDColor(char* topic, byte* payload, unsigned int length) {
  // to test
  switch(topic) {
    case "iot/led/gas:
    gasIsTrue = payload;
    Serial.print("GAS: "); // do sth
    Serial.println(gasIsTrue);
    break;
    case "iot/led/flame:
    flameIsTrue = payload;
    Serial.print("Flame: "); // do sth
    Serial.println(flameIsTrue);
    break;
  }

  if (buttonHasBeenPressed) {
    if (gasIsTrue && flameIsTrue) { // Hier leuchtet das LED rot
      // btn click --> flase alarm
    } else if (gasIsTrue) { // Hier lechtet das LED grün
      // LED switch back to off
    }
  } else {
    if (gasIsTrue && flameIsTrue) {
      // switch led to red
      switchLEDRed();
    } else if (gasIsTrue) {
      // switch led to green
      switchLEDGreen();
    } else {
      // switch led to off
      switchLEDOff();
    }
  }
}

void switchLEDRed() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
}

void switchLEDGreen() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255); 
}

void switchLEDOff() {
  analogWrite(redPin, LOW);
  analogWrite(greenPin, LOW);
}
  
