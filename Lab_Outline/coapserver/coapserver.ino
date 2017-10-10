/*
ESP-COAP Server
*/

#include <ESP8266WiFi.h>
#include <coap_server.h>

String light = "no light";


// CoAP server endpoint url callback
void callback_light(coapPacket &packet, IPAddress ip, int port, int obs);

coapServer coap;

//WiFi connection info
const char* ssid = "HametnerJobst-da1885";
const char* password = "HametnerJobst";

// LED STATE
bool LEDSTATE;

// CoAP server endpoint URL
void callback_light(coapPacket *packet, IPAddress ip, int port,int obs) {
  //Serial.println("no light");

  // send response
  char p[packet->payloadlen + 1];
  memcpy(p, packet->payload, packet->payloadlen);
  p[packet->payloadlen] = NULL;
  Serial.println(p);

  String message(p);

  if (message.equals("1"))
  {
    digitalWrite(LED_BUILTIN,LOW);
    light = "Light";
    Serial.println(light);
    //Serial.println("if loop");
  }
  else if (message.equals("0"))
  {
    digitalWrite(LED_BUILTIN,HIGH);
    //Serial.println("else loop");
    light = "no light";
    Serial.println(light);
  } 
  char *light = (digitalRead(LED_BUILTIN) > 0)? ((char *) "0") :((char *) "1");
  
   //coap.sendResponse(packet, ip, port, light);
   if(obs==0)
    coap.sendResponse(light);
   else
    coap.sendResponse(ip,port,light);
 
}



void callback_lightled(coapPacket *packet, IPAddress ip, int port,int obs) {
  Serial.println("lighted");

  // send response
  char p[packet->payloadlen + 1];
  memcpy(p, packet->payload, packet->payloadlen);
  p[packet->payloadlen] = NULL;

  String message(p);

  if (message.equals("1"))
    LEDSTATE = false;
  else if (message.equals("0"))
    LEDSTATE = true;

  if (LEDSTATE) {
    digitalWrite(LED_BUILTIN, HIGH) ;
    if(obs==0)
     coap.sendResponse("0");
     else
    coap.sendResponse(ip, port, "0");
    
    //coap.sendResponse("0");
  } else {
    digitalWrite(LED_BUILTIN, LOW) ;
    if (obs==0)
    coap.sendResponse("1");
    else
    coap.sendResponse(ip, port, "1");
    //coap.sendResponse("1");
  }
}


void setup() {
  yield();
  //serial begin
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println(" ");

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    //delay(500);
    yield();
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());

  // LED State
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  LEDSTATE = true;

  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  //LEDSTATE = true;


  // add server url endpoints.
  // can add multiple endpoint urls.

  coap.server(callback_light, "light");
  coap.server(callback_lightled, "lightled");
 // coap.server(callback_text,"text");

  // start coap server/client
  coap.start();
   //coap.start(5683);
}

void loop() {
  coap.loop();
  delay(1000);
}
