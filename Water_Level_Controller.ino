#include <LiquidCrystal.h>
int sensorpin = A0;
int A1A = 8;
int A1B = 9;
int sensorvalue = 0;
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  lcd.begin(16, 2);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
}
void loop(){
  sensorvalue = analogRead(sensorpin);
  if(sensorvalue < 300)
  {
    lcd.setCursor(0,0);
    lcd.print("Empty");
    digitalWrite(A1A, HIGH);
    digitalWrite(A1B, LOW);
  }
  else if(sensorvalue>=300&&sensorvalue<360)
  {
    lcd.setCursor(0,0);
    lcd.print("Half Empty     ");
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW);
  }
  else if(sensorvalue>=360)
  {
    lcd.setCursor(0,0);
    lcd.print("Full    ");
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);
  }
  lcd.setCursor(0,1);
  lcd.print(sensorvalue);
  lcd.print("   ");
}
