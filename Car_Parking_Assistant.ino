#include <LiquidCrystal.h>
int trig = 8;
int echo = 9;
int redled = 24;
int yellowled = 25;
int greenled = 26;
int whiteled = 27;
long duration;
int distance;
int buzzer = 30;
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(whiteled, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Starting System");
  delay(1500);
  lcd.clear();
  lcd.print("System On");
  delay(4000);
}
void loop() { 
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034/2;
  Serial.println("Distance = ");
  Serial.println(distance);
  if(distance <= 25) {
    lcd.print("Extreme Risk");
    lcd.setCursor(0, 1);
    Serial.println("Extreme Risk");
    lcd.print("Glowing Red LED");
    Serial.println("Glowing Red LED");
    digitalWrite(redled, HIGH);
    digitalWrite(yellowled, LOW);
    digitalWrite(greenled, LOW);
    digitalWrite(whiteled, LOW);
    digitalWrite(buzzer, HIGH);
    delay(1000);
  }
  else if(distance > 26 && distance <= 35){
    lcd.setCursor(0,0);
    lcd.print("medium risk");
    Serial.println("medium risk");
    lcd.setCursor(0,1);
    lcd.print("Glowing yellow LED");
    Serial.println("Glowing yellow LED");
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, HIGH);
    digitalWrite(greenled, LOW);
    digitalWrite(whiteled, LOW);
    digitalWrite(buzzer, HIGH);
    delay(500);
  }
  else if(distance > 36 && distance <= 50){
    lcd.setCursor(0,0);
    lcd.print("low risk");
    Serial.println("low risk");
    lcd.setCursor(0,1);
    lcd.print("Glowing green LED");
    Serial.println("Glowing green LED");
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, LOW);
    digitalWrite(greenled, HIGH);
    digitalWrite(whiteled, LOW);
    digitalWrite(buzzer, HIGH);
    delay(500);
  }
   else {
    lcd.setCursor(0,0);
    lcd.print("safe no risk");
    Serial.println("safe no risk");
    lcd.setCursor(0,1);
    lcd.print("Glowing white LED");
    Serial.println("Glowing white LED");
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, LOW);
    digitalWrite(greenled, LOW);
    digitalWrite(whiteled, HIGH);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
}
