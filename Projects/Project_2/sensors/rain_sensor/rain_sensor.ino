const int analogPin=A0; //the AO of the module attach to A0
const int digitalPin=16; //D0 attach to pin7
//const int ledPin=13; //pin 13 built-in led
int Astate=0; //store the value of A0
boolean Dstate=0; //store the value of D0
void setup() 
{
  //pinMode(ledPin,OUTPUT); //set the ledPin as OUTPUT 
  pinMode(digitalPin,INPUT); //set digitalPin as INPUT
  Serial.begin(115200); //initialize the serial monitor
}
void loop() 
{
  Astate=analogRead(analogPin); //read the value of A0
  Serial.print("A0: ");
  Serial.println(Astate); //print the value in the serial monitor
  Dstate=digitalRead(digitalPin); //read the value of D0
  Serial.print("D0: ");
  Serial.println(Dstate);
  if(Dstate==HIGH) 
  {
    Serial.println("It's not raining!");
    //digitalWrite(ledPin,LOW);
  }
  else //if the value of D0 is LOW
  {
    Serial.println("It's raining!");
    //digitalWrite(ledPin,HIGH); //turn on the led
  }
}
