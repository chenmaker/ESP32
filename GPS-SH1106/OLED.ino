int btany=0,btany2=0;
String c=""; //設定變數
char copy[60];
void OLED(){
  c=gps.speed.kmph();
  c.toCharArray(copy,10); 
  if(bts1.update() == true && bts1.read() == HIGH){
     if(btany==0&&btany2==0){
      btany+=1;
      }else if(btany==1&&btany2==0){
          btany+=1;
          btany2=1;
      }else if(btany==2&&btany2==1){
          btany-=1;
      }else if(btany==1&&btany2==1){
          btany-=1;
          btany2=0;
      }
      Serial.print("btany:");
      Serial.println(btany);
      Serial.print("btany2:");
      Serial.println(btany2);
      delay(250);
    }
 switch (btany) {
  case 0:
  display.clearDisplay();
  display.setTextSize(7);            
  display.setTextColor(WHITE);        
  display.setCursor(0,10);
  display.print(copy[0]);
  display.print(copy[1]);
  display.print(copy[2]);
  display.display();
  break;
  case 1:
  display.clearDisplay();
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(0,10);             
  display.print(gps.time.hour()+8); 
  display.print(":");          
  display.print(gps.time.minute());
  display.print(":");
  display.print(gps.time.second());
  display.println();        
  display.println();   
  display.print(gps.date.year());
  display.print("/");
  display.print(gps.date.month());
  display.print("/");
  display.print(gps.date.day());
  display.display();
  break;
  case 2:
  display.clearDisplay();
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0); 
  display.println("E");            
  display.println(gps.location.lat());
  display.println("N");               
  display.println(gps.location.lng());
  display.println(tp);
  display.display();
  break;
        }
  }
