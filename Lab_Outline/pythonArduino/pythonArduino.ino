#define LED 13

// Using http://slides.justen.eng.br/python-e-arduino as refference

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(115200);
    Serial.print("Start");
}

void loop() {
    if (Serial.available()) {
        char serialListener = Serial.read();
        if (serialListener == 'ON') {
            digitalWrite(LED, HIGH);
        }
        else { // if (serialListener == 'L')
            digitalWrite(LED, LOW);
        }
    }
}

