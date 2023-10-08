int pinLED = 11;
int pinIR = 2;
boolean oldIRState = LOW;
boolean newIRState = LOW;
boolean LEDstatus = LOW;
void setup (){
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);
  pinMode(pinIR, INPUT);
}
void loop (){
  newIRState = digitalRead(pinIR);
  if(newIRState != oldIRState)
  {
    if(newIRState == HIGH)
    {
      if(LEDstatus == LOW)
      {
        delay(100);
        digitalWrite(pinLED, HIGH);
        LEDstatus = HIGH;
      }
      else {
        delay(100);
        digitalWrite(pinLED, LOW);
        LEDstatus = LOW;
      }
    }
    oldIRState = newIRState;
  }
}
