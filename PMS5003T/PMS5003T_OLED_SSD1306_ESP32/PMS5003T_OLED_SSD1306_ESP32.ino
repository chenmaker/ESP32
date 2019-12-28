#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI  23 //SDA
#define OLED_CLK   18 //SCL
#define OLED_DC    5 //DC
#define OLED_CS    15 //不用接
#define OLED_RESET 4  //RES
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
  
unsigned char gucRxBuf[100];
unsigned int pmcount25;
float temp=0.0;
float humi=0.0;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(30,20);             // Start at top-left corner
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
