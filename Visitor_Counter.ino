#define trigpin 8
#define echopin 9
#define pinIR 7
float duration = 0.00;
float distance = 0.00;
int visitor, sum, threshold, temp;
boolean oldIRState = LOW;
boolean newIRState = LOW;
#include <LiquidCrystal.h>
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(pinIR, INPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Visitor= ");
  lcd.println(visitor);
  Serial.begin(9600);
}
void loop() {   // put your main code here, to run repeatedly:
  newIRState=digitalRead(pinIR);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration/58.82;
  Serial.print("Distance=");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
  if(distance<=10 && abs(temp)>=30)
  {
    visitor++;
    lcd.clear();
    lcd.print("visitor=");
    lcd.println(visitor);
    Serial.print("visitor=");
    Serial.print(visitor);
    for(int i=0;i<500;i++)
    {
      sum+=distance;
      delay(5);
    }
    threshold=sum/500;
  }
  temp=threshold-distance;
  if(newIRState!=oldIRState)
  {
    if(newIRState==LOW && visitor>0)
    {
      visitor--;
      lcd.clear();
      lcd.print("visitor=");
      lcd.print(visitor);
      Serial.print("visitor=");
      Serial.println(visitor);
    }
  }
  oldIRState=newIRState;
}
