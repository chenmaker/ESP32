#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

//SPI
#define OLED_MOSI  23
#define OLED_CLK   18
#define OLED_DC    5
#define OLED_CS    15
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

unsigned char gucRxBuf[100];
unsigned int pmcount25;
float temp=0.0;
float humi=0.0;
//PM:RX-->GPIO17 TX-->GPIO16
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(3);             
  display.setTextColor(WHITE);       
  display.setCursor(30,20);            
  display.println("Hello");
  display.display();
  delay(1500);
}
void loop() {
  pm();
  display.clearDisplay();
  display.setTextSize(2);            
  display.setTextColor(WHITE);        
  display.setCursor(0,0);
  display.print("C:");
  display.println(temp);
  display.setTextSize(2);            
  display.setTextColor(WHITE);        
  display.setCursor(0,25);
  display.print("H:");
  display.println(humi);
  display.setTextSize(2);            
  display.setTextColor(WHITE);       
  display.setCursor(0,50);               
  display.println("PM2.5:"+String(pmcount25));
  display.display();
}
