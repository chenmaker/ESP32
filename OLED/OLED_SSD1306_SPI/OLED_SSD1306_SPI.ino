#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//SPI
#define OLED_MOSI  23 //SDA
#define OLED_CLK   18 //SCL
#define OLED_DC    5 //DC
#define OLED_CS    15 //不用接
#define OLED_RESET 4  //RES
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  Serial.begin(9600);
display.begin(SSD1306_SWITCHCAPVCC);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);           
  display.setTextColor(WHITE);     
  display.setCursor(30,25);//寬,高        
  display.println("Hello");
  display.display();
  delay(2000);
}
