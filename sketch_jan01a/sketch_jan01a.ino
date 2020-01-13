   int ThermistorPin;
    double adcMax, Vs;

    double R1 = 100000.0;   // voltage divider resistor value
    double Beta = 3950.0;  // Beta value
    double To = 298.15;    // Temperature in Kelvin for 25 degree Celsius
    double Ro = 100000.0;   // Resistance of Thermistor at 25 degree Celsius


    void setup() {
      Serial.begin(9600);

      ThermistorPin = 34;
      adcMax = 4095.0;   // ADC resolution 10-bit (0-1023)
      Vs = 3.3;          // supply voltage

    }

    void loop() {
      double Vout, Rt = 0;
      double T, Tc, Tf = 0;

      Vout = analogRead(ThermistorPin) * Vs/adcMax;
      Rt = R1 * Vout / (Vs - Vout);
      T = 1/(1/To + log(Rt/Ro)/Beta);  // Temperature in Kelvin
      Tc = T - 273.15;                 // Celsius
      Tf = Tc * 9 / 5 + 32;            // Fahrenheit
      Serial.println(Tc);

      delay(200);
    }
