unsigned char gucRxBuf[100];

void setup() {
	Serial.begin(9600);
	Serial2.begin(9600);
}

void PMxx_info(void){
	unsigned int pmcf10 =gucRxBuf[4]*256+gucRxBuf[5];   Serial.print("PM1.0_CF1:"); Serial.print(pmcf10);    Serial.print("   ");
	unsigned int pmcf25 =gucRxBuf[6]*256+gucRxBuf[7];   Serial.print("PM2.5_CF1:"); Serial.print(pmcf25);    Serial.print("   ");
	unsigned int pmcf100=gucRxBuf[8]*256+gucRxBuf[9];   Serial.print("PM10_CF1:");  Serial.println(pmcf100);
	unsigned int pmat10 =gucRxBuf[10]*256+gucRxBuf[11]; Serial.print("PM1.0_AT:");  Serial.print(pmat10);    Serial.print("   ");
	unsigned int pmat25 =gucRxBuf[12]*256+gucRxBuf[13]; Serial.print("PM2.5_AT:");  Serial.print(pmat25);    Serial.print("   ");
	unsigned int pmat100=gucRxBuf[14]*256+gucRxBuf[15]; Serial.print("PM10_AT:");   Serial.println(pmat100);
}
void PMxx_cnt_bsc(void){
	unsigned int pmcount03=gucRxBuf[16]*256+gucRxBuf[17];  Serial.print("PMcount0.3:");   Serial.println(pmcount03);
	unsigned int pmcount05=gucRxBuf[18]*256+gucRxBuf[19];  Serial.print("PMcount0.5:");   Serial.println(pmcount05);
	unsigned int pmcount10=gucRxBuf[20]*256+gucRxBuf[21];  Serial.print("PMcount1.0:");   Serial.println(pmcount10);
	unsigned int pmcount25=gucRxBuf[22]*256+gucRxBuf[23];  Serial.print("PMcount2.5:");   Serial.println(pmcount25);
}

void loop() 
{
	if(Serial2.available()){
		delay(100);
		unsigned char i=0;
		while(Serial2.available()){
			gucRxBuf[i] = Serial2.read();
			i++;
		}
		if (((gucRxBuf[0]==0x42)&&(gucRxBuf[1]==0x4d))&&(i>=12)){
			int chksum=0;
			unsigned char DTL=(gucRxBuf[2]<<8)+gucRxBuf[3];
			for(unsigned char i=0;i<(DTL+2);i++){chksum += gucRxBuf[i];}
			unsigned char csH = (chksum>>8);
			unsigned char csL = (chksum&0xFF);
			if((csH==gucRxBuf[DTL+2])&&(csL==gucRxBuf[DTL+3])){
				Serial.println("========= PMS5003T =========");
				PMxx_info();
				PMxx_cnt_bsc();
				float temp=(float)(gucRxBuf[24]*256+gucRxBuf[25])/10;  Serial.print("Temperature:");  Serial.print(temp,1);       Serial.println(" C");
				float humi=(float)(gucRxBuf[26]*256+gucRxBuf[27])/10;  Serial.print("Humidity:");     Serial.print(humi,1);       Serial.println(" %");
				Serial.print("Version:");     Serial.println(gucRxBuf[28]);
				Serial.print("Error Code:");  Serial.println(gucRxBuf[29]);
			}
			else{
				Serial2.flush();
			}
		}
		else{
			Serial2.flush();
		}
	}
}
