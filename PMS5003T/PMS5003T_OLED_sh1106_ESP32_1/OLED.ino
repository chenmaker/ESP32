void OLED(){
  if(bts1.update() == true && bts1.read() == HIGH){
    if(btany==1){
      btany-=1;
      }else
      {
        btany+=1;
        }
  }
  Serial.print("btany:");
  Serial.println(btany);
 switch (btany) {
  case 0:
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
  break;
  case 1:
  display.clearDisplay();
  display.setTextSize(2);            
  display.setTextColor(WHITE); 
  display.setCursor(0,15);
  display.print("FUN1:");
  display.println(fan2_speed);
  display.setTextSize(2);            
  display.setTextColor(WHITE); 
  display.setCursor(0,35);
  display.print("FUN2:");
  display.println(fan2_speed);
  display.display();
  break;
        }
  }
