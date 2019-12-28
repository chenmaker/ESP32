int ledPin[] ={33,25,26,27,14,12,13};

void setup() 
{
 for(int x=0;x<=6;x++){
  pinMode(ledPin[x], OUTPUT);
 }
}

void loop()
{for(int i=0;i<=6;i++){
  digitalWrite(ledPin[i], HIGH); 
  delay(500);
  digitalWrite(ledPin[i], LOW); 
  delay(100); 
  }
}
