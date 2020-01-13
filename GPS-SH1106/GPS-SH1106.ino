//GPS
#include <TinyGPS++.h>
//OLED
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <analogWrite.h>
#include <Bounce.h>/按鈕
#include <math.h>//溫度
//OLED
#define OLED_MOSI  23
#define OLED_CLK   18
#define OLED_DC    4
#define OLED_CS    15
#define OLED_RESET 5
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS); 
//GPS:RX-->GPIO17 TX-->GPIO16
TinyGPSPlus gps;
const int bt1 =36;
Bounce bts1=Bounce(36, 50);
//LED
int led[] ={25,26,27,12,13};
//溫度
unsigned int Rs = 10000;
double Vcc = 3.3;
int tp;
void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600);
  for(int x=0;x<=4;x++){
  pinMode(led[x], OUTPUT);
  }
  pinMode(bt1,INPUT);
  display.begin(SH1106_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(3);             
  display.setTextColor(WHITE);       
  display.setCursor(25,0);            
  display.println("Hello");
  display.println("CHEN");
  display.display();
  delay(1500);
}

void loop()
{ while (Serial2.available() > 0)
    if (gps.encode(Serial2.read()))
      displayInfo();
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }  
  OLED();
  LED();
  T();
}
