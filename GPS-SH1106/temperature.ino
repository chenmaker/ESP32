void T(){
  tp=Thermister(AnalogRead());
  Serial.println(Thermister(AnalogRead())); 
  }
  int AnalogRead() {
  int val = 0;
  for(int i = 0; i < 20; i++) {
    val += analogRead(34);
    delay(1);
  }

  val = val / 20;
  return val;
}

double Thermister(int val) {
  double V_NTC = (double)val / 1024;//4095???
  double R_NTC = (Rs * V_NTC) / (Vcc - V_NTC);
  R_NTC = log(R_NTC);
  double Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * R_NTC * R_NTC ))* R_NTC );
  Temp = Temp - 273.15;         
  return Temp;
  }
