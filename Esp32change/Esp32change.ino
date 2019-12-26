#include "AiEsp32RotaryEncoder.h"
#include "Arduino.h"

#define ROTARY_ENCODER_A_PIN 32
#define ROTARY_ENCODER_B_PIN 21
#define ROTARY_ENCODER_BUTTON_PIN 25
#define ROTARY_ENCODER_VCC_PIN 27 
AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN);

int test_limits = 2;
int encoderValue; 
int a=0;
void rotary_onButtonClick() {
	  rotaryEncoder.reset();
	//rotaryEncoder.disable();
	//rotaryEncoder.setBoundaries(-test_limits, test_limits, false);
}
void setup() {
	Serial.begin(115200);
	rotaryEncoder.begin();
	rotaryEncoder.setup([]{rotaryEncoder.readEncoder_ISR();});
	rotaryEncoder.setBoundaries(0,100,true);
 // rotaryEncoder.enable();
}

void loop() {
 if (rotaryEncoder.currentButtonState() == BUT_RELEASED) {
    rotary_onButtonClick();
  }
  int16_t encoderDelta = rotaryEncoder.encoderChanged();
  if (encoderDelta == 0) return;
  if (encoderDelta>0){
    Serial.print("+");
    a=a+encoderValue;
  }
  if (encoderDelta<0){
    Serial.print("-");
    a=a-encoderValue;
  }
  if (encoderDelta!=0) {
    encoderValue = rotaryEncoder.readEncoder();
    Serial.print("Value: ");
    Serial.println(encoderValue);
    Serial.print("A: ");
    Serial.println(a);
  } 
	delay(50);															 
}
