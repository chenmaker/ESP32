void OLED(){
  if(bts1.update() == true && bts1.read() == HIGH){
    if(btany==1){
      btany-=1;
      }else
      {
        btany+=1;
        }
  }
  //Serial.print("btany:");
 // Serial.println(btany);
 switch (btany) {
  case 0:
  display.clearDisplay();
  display.setTextSize(4);            
  display.setTextColor(WHITE);        
  display.setCursor(30,20);
  display.print(gps.speed.kmph());
  display.display();
  break;
  case 1:
  display.clearDisplay();
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0);             
  display.println(gps.location.lat());
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(0,20);             
  display.println(gps.location.lng());
  display.display();
  break;
        }
  }
