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

void setup()   {                
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC);
}
void loop() {
  display.clearDisplay();
  display.setTextSize(2); //Sixe(1)10,Sixe(2)20           
  display.setTextColor(WHITE);        
  display.setCursor(0,0);//寬,高     
  display.println("Hello");
  display.setCursor(0,20);           
  display.println("Hello1");
  display.display();
  delay(2000);
}
