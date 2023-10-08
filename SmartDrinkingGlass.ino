const int tiltswitchpin = 8;
const int redpin = 3;
const int greenpin = 5;
const int bluepin = 6;
int tiltSwitchState = 0;
int count;
byte thisstate, laststate;
void setup() {
  Serial.begin(9600);
  pinMode(tiltswitchpin, INPUT_PULLUP);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
}
void loop() {
  tiltSwitchState = digitalRead(tiltswitchpin);
  delay(1000);
  if(tiltSwitchState == HIGH)
  {
    laststate = tiltSwitchState;
  }
  else if(tiltSwitchState == LOW)
  {
    if(laststate != tiltSwitchState)
    {
      delay(80);
      laststate = tiltSwitchState;
      count++;
      Serial.println(count);
      if(count < 3)
      {
        analogWrite(redpin, 5);
        digitalWrite(greenpin, LOW);
        digitalWrite(bluepin, LOW);
      }
      else if(count >= 3 && count < 8)
      {
       digitalWrite(redpin, LOW);
       analogWrite(bluepin, 10);
       digitalWrite(greenpin, LOW); 
      }
      else if(count >= 8)
      {
       digitalWrite(redpin, LOW);
       digitalWrite(bluepin, LOW);
       analogWrite(greenpin, 150);
      }
    }
  }
}
