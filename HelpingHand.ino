const int sensorpin = 10;
const int buzzer = 11;
int tiltstate = 0;
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(sensorpin, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  tiltstate = digitalRead(sensorpin);
  Serial.println(tiltstate);
  delay(100);
  if(tiltstate == HIGH)
  {
    digitalWrite(buzzer, LOW);
  }
  else {
    digitalWrite(buzzer, HIGH);
  }
}
