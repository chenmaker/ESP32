#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <analogWrite.h>
#include <Bounce.h>
//SPI
#define OLED_MOSI  23
#define OLED_CLK   18
#define OLED_DC    4
#define OLED_CS    15
#define OLED_RESET 5
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

unsigned char gucRxBuf[100];
unsigned int pmcount25;
float temp=0.0;
float humi=0.0;
//PM:RX-->GPIO17 TX-->GPIO16

const int fan1 = 26;
const int fan2 = 12;
int in1,in2,fan1_speed,fan2_speed;
const int bt1 =34;
Bounce bts1=Bounce(34, 50);
int btany=0;
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(fan1,OUTPUT); 
  pinMode(fan2,OUTPUT); 
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
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
void loop() {
  in1=analogRead(39);
  in2=analogRead(36);
  fan1_speed = in1*(255 / 4095.0);
  fan2_speed = in2*(255 / 4095.0);
  analogWrite(fan1,fan2_speed);
  analogWrite(fan2,fan2_speed);
  //Serial.print("fan_speed:");
  //Serial.println(fan_speed);
  pm();
  OLED();
  }
