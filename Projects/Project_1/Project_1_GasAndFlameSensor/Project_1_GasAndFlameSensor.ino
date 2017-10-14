#include <Base64.h>

// Gas-Sensor:
int inputGasA = A0;
bool isGasTrue = false;

// Flame-Sensor:
int inputFlameD = 4;
bool isFlameHigh = LOW;

void setup() {
  Serial.begin(115200);
  // Gas-Sensor:
  pinMode(inputGasA, INPUT);

  // Flame-Sensor:
  pinMode(inputFlameD, INPUT);
}

void loop() {
  // Gas Sensor:
  int gasSensor = analogRead(inputGasA);
  Serial.print("Pin A0: ");
  Serial.println(gasSensor);

  if (gasSensor > 400)
  {
    Serial.println("ACHTUNG!!!");
    isGasTrue = true;
  }
  else
  {
    Serial.println("normal");
    isGasTrue = false;
  }
  
  // Flame-Sensor:
  isFlameHigh = digitalRead(inputFlameD);
  if (isFlameHigh == HIGH) {
    Serial.println("DigitalReader Flame: HIGH");
  } else {
    Serial.println("DigitalReader Flame: LOW");
  }
  
  
  isGasTrue = true; // to test please delete!!!
  isFlameHigh = HIGH; // to test please delete!!!

  if (isGasTrue) {
    if (isFlameHigh == HIGH) {
      // LED-Event = Rot
      Serial.println("LED is red!");
    } else {
      // LED-Event = Grün
      Serial.println("LED is green!");
    }
  } else {
    // LED-Event = OFF
    Serial.println("LED is off!");
  }
  delay(100);
}
