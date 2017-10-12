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

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  13;      // the number of the LED pin
bool buttonHasBeenPressed = true;
int greenPin = 15;
int redPin = 13;
bool gasIsTrue = false;
bool flameIsTrue = false;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  Serial.println();
  // initialize the LED pin as an output:
  //pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT); //set redPin as OUTPUT
  pinMode(greenPin, OUTPUT);//set greenPin as OUTPUT
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // Serial.print("not pressed");
    //digitalWrite(ledPin, HIGH);
    buttonHasBeenPressed = true;
  } else {
    if (buttonHasBeenPressed) {
    Serial.println("Button is pressed"); // send a HQTT-message that button is pressed
    buttonHasBeenPressed = false;
    }
  }
  // to test
  gasIsTrue = false;
  flameIsTrue = false;
  unsigned int len = 10;
  char* t = "Topic";
  byte* p;
  LEDColor(t, p, len);
}

void LEDColor(char* topic, byte* payload, unsigned int length) {
  // to test
  /*switch(topic) {
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
  }*/

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
  
