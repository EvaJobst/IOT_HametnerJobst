/*
 Basic ESP8266 MQTT example
 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "  " every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.
 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"
    
    More information about projects PDAControl
    Mas informacion sobre proyectos PDAControl
    Blog PDAControl English   http://pdacontrolenglish.blogspot.com.co/   
    Blog PDAControl Espanol   http://pdacontrol.blogspot.com.co/
    Channel  Youtube          https://www.youtube.com/c/JhonValenciaPDAcontrol/videos   
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SimpleTimer.h>

// Update these with values suitable for your network.

const char* ssid =         "HametnerJobst-da1885";
const char* password =    "HametnerJobst";
const char* mqtt_server = "192.168.12.1";   /// example 192.168.0.19

// Flame-Sensor:
const int flameSensor = 2; // D4

// Gas-Sensor
const int gasSensor = A0; // A0

// Button-Sensor:
const int buttonPin = 5; // D1
bool buttonHasBeenPressed = true;
int buttonState = 0;

// LED-Actor: 
int greenPin = 15; // D8
int redPin = 13; // D7

// Buzzer-Actor:
int buzzerPin = 12; // D6

// Timer:
SimpleTimer timer;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
bool freezTrue;
bool freezTrueFirstUse = true;
int currentMillis;
bool buttonWasClicked;

void setup() {
  //client.setServer(mqtt_server, 1883);
  //client.setCallback(callback);
  Serial.begin(115200);
  setup_wifi();

  // Flame-Sensor:
    pinMode(flameSensor,INPUT);

    // Gas-Sensor:
    pinMode(gasSensor, INPUT);

    // Button-Sensor:
  pinMode(buttonPin, INPUT);

  // LED-Actor:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Buzzer-Actor:
  pinMode(buzzerPin, OUTPUT);

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
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
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  // Flame-Sensor:
  if (digitalRead(flameSensor) == 0) {
    //Serial.println(" --> HIGH");
    publishClient("0", "iot/Flame");
  } else if (digitalRead(flameSensor) == 1) {
    //Serial.println(" --> LOW");
    publishClient("1", "iot/Flame");
  }

  // Gas-Sensor:
  if (analogRead(gasSensor) > 400)
  {
    publishClient("0", "iot/Gas");
  }
  else
  {
    publishClient("1", "iot/Gas");
  }

  
  
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  //delay(5000);
  
    // Button:     
  if (client.subscribe("iot/IsFlame") == 0) {
  if (digitalRead(buttonPin) == 0) { // click
    Serial.println("Flame was deactivated");
      analogWrite(redPin, LOW);
  analogWrite(greenPin, LOW);
      analogWrite (buzzerPin, -1);
      delay(10000);
  } else if (digitalRead(buttonPin) == 1) {
    Serial.println("Flame");
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
      analogWrite (buzzerPin, 255);
  }
  } else {
    Serial.println("no Flame");
    if (client.subscribe("iot/IsGas") == 0) {
  if (digitalRead(buttonPin) == 0) { // click
    Serial.println("Gas was deactivated");
      analogWrite(redPin, LOW);
  analogWrite(greenPin, LOW);
      delay(10000);
  } else if (digitalRead(buttonPin) == 1) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255); 
    Serial.println("Gas");
  }
  } else {
    Serial.println("no Gas");
    analogWrite(redPin, LOW);
    analogWrite(greenPin, LOW);
    analogWrite (buzzerPin, -1);
  }
  }

  
}

void publishClient(char* _msg, char* _publisher) {
  snprintf (msg, 75, _msg, value); 
  client.publish(_publisher, msg);
}
