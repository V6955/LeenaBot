#include<LiquidCrystal.h>
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
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
int buzzer = 7;
void setup(){
  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" WELCOME To ");
  Serial.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("Leenabot Robotics");
  delay(2000);
  lcd.clear();
}

void loop() {
if(digitalRead (ir_s1) == LOW && flag1==0){
timer1 = millis(); 
flag1=1;
}
if(digitalRead (ir_s2) == LOW && flag2==0){
  timer2 = millis(); 
  flag2=1;
  }
if (flag1==1 && flag2==1){
     if(timer1 > timer2){
      Time = timer1 - timer2;
      }
else if(timer2 > timer1){
  Time = timer2 - timer1;
  }
 Time=Time/1000;//convert millisecond to second
 speed=(distance/Time);//v=d/t
 speed=speed*3600;//multiply by seconds per hr
 speed=speed/1000;//division by meters per Km
}

if(speed==0){ 
lcd.setCursor(0, 1); 
if(flag1==0 && flag2==0){
lcd.print("No car  detected");
Serial.println("No Car");
}
else{
  lcd.print("Searching...    ");
  Serial.println("Searching...");
  } 
}
else{
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("Speed:");
    Serial.println("Speed=");
    lcd.print(speed,1);
    Serial.print(speed,1);
    lcd.print("Km/Hr  ");
    Serial.println("Km/Hr");
    lcd.setCursor(0, 1); 
  if(speed > 50){
    lcd.print("  Over Speeding  ");
    Serial.println("Over speedding"); 
    digitalWrite(buzzer, HIGH);
    }
  else{
    lcd.print("  Normal Speed   ");
    Serial.println("Normal speed");
   
  }    
    delay(1000);
    digitalWrite(buzzer, LOW);
    speed = 0;
    flag1 = 0;
    flag2 = 0;    
 }
}
