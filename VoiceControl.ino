#define BLYNK_PRINT Serial
#define led D7

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,16,2);

char auth[] = "143ca53f9cb644b4b88e72a0105dece8";
WidgetLCD lcd(V2);
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

void setup()
{
  // Debug console
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(led,OUTPUT);
  Blynk.begin(auth, ssid, pass,IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1) 
{
  int pinData = param.asInt();
  if(pinData == 1)
  {
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}

BLYNK_WRITE(V2)
{
  int pinData = param.asInt();
  if(pinData == 1)
  {
    lcd.clear();
    lcd.print(0,0,"LIGHT ON!!");
  }else{
    lcd.clear();
    lcd.print(0,0,"LIGHT OFF!!");
  }
}
