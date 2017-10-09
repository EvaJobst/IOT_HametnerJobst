  // ESP8266 with 16x2 i2c LCD
  // Compatible with the Arduino IDE 1.6.6
  // Library https://github.com/agnunez/ESP8266-I2C-LCD1602
  // Original Library https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
  // Modified for ESP8266 with GPIO0-SDA GPIO2-SCL and LCD1206 display
  // edit library and change Wire.begin() by Wire.begin(sda,scl) or other GPIO's used for I2C
  // and access from lcd.begin(sda,scl)
  
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
  
  LiquidCrystal_I2C lcd(0x27,16,2); // Check I2C address of LCD, normally 0x27 or 0x3F
  
  uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};  // example sprite bitmap
  
  void setup()  {
    Wire.begin(0,2);      //sda=0 | D3, scl=2 | D4
    Serial.begin(115200);
    lcd.begin(0,2);      // In ESP8266-01, SDA=0, SCL=2               
    lcd.backlight();
    lcd.createChar(1, heart);
  }
  
  void loop()  {
    lcd.home();                // At column=0, row=0
    lcd.print("ESP8266");   
    lcd.setCursor(0, 1);
    lcd.print("LiquidCrystalI2C");
    delay(500);
    lcd.setCursor(10, 0);      // At column=10, row=0
    lcd.write(byte(1));
    delay(500);
    lcd.setCursor(10, 0);      // At column=10, row=0
    lcd.print(" ");            // Wipe sprite


  // ===== Scanning =====
    byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
 
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  }
