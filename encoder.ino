#define MOTOR_LA 18
#define MOTOR_LB 19
#define MOTOR_RA 14
#define MOTOR_RB 21
 
#define ENC1A_PIN 2
#define ENC1B_PIN 4
#define ENC2A_PIN 47
#define ENC2B_PIN 48
 
#include <ESP32Encoder.h>
ESP32Encoder enc1;
ESP32Encoder enc2;
int i;
 
void Lmotor(int i) {
  Serial.print("i = ");
  Serial.println(i);
  /*if (i == 0) {
    ledcWrite(0, 0);
    ledcWrite(1, 0);
  Serial.print("i = ");
  Serial.print(i);
  Serial.print(" ,L = ");
  Serial.print(enc1.getCount());
  Serial.print(" ,R = ");
  Serial.println(enc2.getCount());
  }
  else if (i > 0) {
    if (i > 1024){
    //i = 1024;*/
    ledcWrite(0, i);
    ledcWrite(1, 0);
  Serial.print("i = ");
  Serial.print(i);
  Serial.print(" ,L = ");
  Serial.print(enc1.getCount());
  Serial.print(" ,R = ");
  Serial.println(enc2.getCount());
    }
  /*}
  else {
    if (i < -1024){
    //i = -1024;
    ledcWrite(0, 0);
    ledcWrite(1, -i);
  Serial.print("i = ");
  Serial.print(i);
  Serial.print(" ,L = ");
  Serial.print(enc1.getCount());
  Serial.print(" ,R = ");
  Serial.println(enc2.getCount());
    }
  }
}*/
 
void Rmotor(int i) {
  Serial.print("i = ");
  Serial.println(i);
  if (i == 0) {
    ledcWrite(2, 0);
    ledcWrite(3, 0);
  Serial.print("i = ");
  Serial.print(i);
  Serial.print(" ,L = ");
  Serial.print(enc1.getCount());
  Serial.print(" ,R = ");
  Serial.println(enc2.getCount());
  }
  else if (i > 0) {
    if (i > 1024){
    //i = 1024;
    ledcWrite(2, i);
    ledcWrite(3, 0);
  Serial.print("i = ");
  Serial.print(i);
  Serial.print(" ,L = ");
  Serial.print(enc1.getCount());
  Serial.print(" ,R = ");
  Serial.println(enc2.getCount());
    }
  }
  else {
    if (i < -1024){
    //i = -1024;
    ledcWrite(2, 0);
    ledcWrite(3, -i);
  Serial.print("i = ");
  Serial.print(i);
  Serial.print(" ,L = ");
  Serial.print(enc1.getCount());
  Serial.print(" ,R = ");
  Serial.println(enc2.getCount());
    }
  }
}
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  
  ESP32Encoder::useInternalWeakPullResistors = UP;
  enc1.attachHalfQuad(ENC1A_PIN, ENC1B_PIN);
  enc1.clearCount();
  enc1.setFilter(8);

 
  enc2.attachHalfQuad(ENC2A_PIN, ENC2B_PIN);
  enc2.clearCount();
  enc2.setFilter(8);

 
  ledcSetup(0, 2000, 10);
  ledcSetup(1, 2000, 10);
  ledcSetup(2, 2000, 10);
  ledcSetup(3, 2000, 10);

 
  ledcAttachPin(MOTOR_LA, 0);
  ledcAttachPin(MOTOR_LB, 1);
  ledcAttachPin(MOTOR_RA, 2);
  ledcAttachPin(MOTOR_RB, 3);

 
  Lmotor(0);
  Rmotor(0);
}
 
void loop() {
  Lmotor(512);
  delay(1000);
  Lmotor(0);
  delay(1000);
  /*Rmotor(512);
  delay(1000);
  Rmotor(0);
  delay(1000);&*/
}
