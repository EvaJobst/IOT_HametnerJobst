/*
 *  HTTP over TLS (HTTPS) example sketch
 *
 *  This example demonstrates how to use
 *  WiFiClientSecure class to access HTTPS API.
 *  We fetch and display the status of
 *  esp8266/Arduino project continuous integration
 *  build.
 *
 *  Created by Ivan Grokhotkov, 2015.
 *  This example is in public domain.
 */

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const char* ssid = "HametnerJobst-da1885";
const char* password = "HametnerJobst";

String url = "https://maker.ifttt.com/trigger/notify_phone/with/key/dpLOveXyj81hUdJ8GoGo6d";
const char* host = "maker.ifttt.com";
const int httpsPort = 443;
WiFiClientSecure client;
LiquidCrystal_I2C lcd(0x27,16,2); // Check I2C address of LCD, normally 0x27 or 0x3F

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
//const char* fingerprint = "CF 05 98 89 CA FF 8E D8 5E 5C E0 C2 E4 F7 E6 C3 C7 50 DD 5C";

int buttonPin = 5;
int val;
int counter = 0;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  Serial.print("requesting URL: ");
  Serial.println(url);

  // Button
  pinMode(buttonPin, INPUT);

  // LCD:
  lcd.begin(0,2);
  lcd.backlight();
  loop();
  
}

void loop() {
  val = digitalRead(buttonPin);

  if (val != HIGH) {
    Serial.println("Button press detected!");
    sendRequest();
    lcd.print(counter);
    lcd.print(" Hello World! ");
    counter++;
  }
}


void sendRequest() {
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}
