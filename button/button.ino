#include <analogWrite.h>
#include <Bounce.h>
const int bt1 =36;
Bounce bts1=Bounce(36, 50);
int btany=0;
void setup() {
Serial.begin(115200);
pinMode(bt1,INPUT);
}

void loop() {
  if(bts1.update() == true && bts1.read() == HIGH){
      btany+=1;
      }
Serial.print("btany:");
      Serial.println(btany);

}
