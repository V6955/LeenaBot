#include<Servo.h>
Servo myservo;
const int trigpin =3;
const int echopin =5;
long timeduration;
int distance;

void setup() {
    myservo.attach(9);
    pinMode(trigpin, OUTPUT);
    pinMode(echopin, OUTPUT);
    Serial.begin(9600);
}

void loop() { 
digitalWrite(trigpin,LOW); 
delayMicroseconds(2); 
digitalWrite(trigpin,HIGH); 
delayMicroseconds(10); 
digitalWrite(trigpin,LOW); 
timeduration=pulseIn(echopin,HIGH); 
distance=(0.034*timeduration)/2; 
if(distance<=7){ 
myservo.write(0); 
} 
else{ 
myservo.write(90);
}
 Serial.print("distance:"); 
Serial.println(distance); 
delay(2000); 

}
