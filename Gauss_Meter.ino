#include<LiquidCrystal.h>
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int threshold=0;
int sensorvalue;
long sum=0;

void setup() {    // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  for(int i=0;i<500;i++)
  {
    sensorvalue=analogRead(A0);
    sum+=sensorvalue;
    delay(5);
  }
  threshold = sum/500;
}

void loop() { // put your main code here, to run repeatedly:
  int sensorvalue=analogRead(A0);
  int x=(sensorvalue-threshold);
  if(sensorvalue>490 && sensorvalue<=22)
  {
    x=0;
  }
  float flux=x/3.48;
  Serial.println(sensorvalue);
  Serial.println(flux);
  lcd.print("flux=");
  lcd.print(flux);
  lcd.print("G");
  delay(500);
  lcd.clear();
}
