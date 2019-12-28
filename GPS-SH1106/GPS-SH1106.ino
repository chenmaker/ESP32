//GPS
#include <TinyGPS++.h>
//OLED
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <analogWrite.h>
#include <Bounce.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_MOSI  23
#define OLED_CLK   18
#define OLED_DC    4
#define OLED_CS    15
#define OLED_RESET 5
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
//GPS  
//static const int RXPin = 4, TXPin = 3;//GPS TX-->4 RX-->3
//static const uint32_t GPSBaud = 9600;//與GPS包綠
TinyGPSPlus gps;
//PM:RX-->GPIO17 TX-->GPIO16
const int bt1 =34;
Bounce bts1=Bounce(34, 50);
int btany=0;
void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600);
  pinMode(bt1,INPUT);
  display.begin(SH1106_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(3);             
  display.setTextColor(WHITE);       
  display.setCursor(25,20);            
  display.println("Hello");
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
}
