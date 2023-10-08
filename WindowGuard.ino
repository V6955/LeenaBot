const int sensorpin = 2;
const int buzzerpin = 11;
int sensorstate = 0;
void setup() {
  pinMode(buzzerpin, OUTPUT);
  pinMode(sensorpin, INPUT);
  Serial.begin(9600);
}
void loop() {
  sensorstate = digitalRead(sensorpin);
  Serial.println(sensorstate);
  delay(100);
  if(sensorstate == HIGH)
  {
    digitalWrite(buzzerpin, LOW);
  }
  else
  {
    digitalWrite(buzzerpin, HIGH);
  }
}
