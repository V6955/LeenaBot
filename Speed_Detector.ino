#include<LiquidCrystal.h>
const int rs = 12,en = 11, d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int timer1;
int timer2;
float Time;
int flag1 = 0;
int flag2 = 0;
float distance = 5.0;
float speed;
int ir_s1 = A0;
int ir_s2 = A1;
int buzzer = 13;

void setup() {
  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome");
  delay(2000);
  lcd.clear();
}

void loop() {
  if(digitalRead(ir_s1) == LOW && flag1 == 0){
    timer1 = millis();
    flag1 = 1;
  }
  if(digitalRead(ir_s2) == LOW && flag2 == 0){
    timer2 = millis();
    flag2 = 1;
  }
}
