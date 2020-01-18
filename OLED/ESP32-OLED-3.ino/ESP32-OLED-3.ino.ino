#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
//OLED1
#define OLED_MOSI  23
#define OLED_CLK   18
#define OLED_DC    19
#define OLED_CS    5
#define OLED_RESET 21
//OLED2
#define OLED_MOSI2  23
#define OLED_CLK2   18
#define OLED_DC2    19
#define OLED_CS2    15
#define OLED_RESET2 4
Adafruit_SH1106 Display1(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
Adafruit_SH1106 Display2(OLED_MOSI2, OLED_CLK2, OLED_DC2, OLED_RESET2, OLED_CS2);
void setup()   {                
  Serial.begin(9600);
  Display1.begin(SH1106_SWITCHCAPVCC);
  Display2.begin(SH1106_SWITCHCAPVCC);
}
void loop() {
  Display1.clearDisplay();
  Display1.setTextSize(2); //Sixe(1)10,Sixe(2)20           
  Display1.setTextColor(WHITE);        
  Display1.setCursor(0,0);//寬,高     
  Display1.println("Hello");
  Display1.display();
  delay(2000);
  Display2.clearDisplay();
  Display2.setTextSize(2); //Sixe(1)10,Sixe(2)20           
  Display2.setTextColor(WHITE);        
  Display2.setCursor(0,0);//寬,高     
  Display2.println("word");
  Display2.display();
  delay(2000);
}
