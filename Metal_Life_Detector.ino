const int buzzerpin = 11;
const int sensorpin = A0;
void setup () {
  pinMode(buzzerpin, OUTPUT);
  pinMode(sensorpin, INPUT);
  Serial.begin(9600);
}
void loop() {
  int sensorvalue = analogRead(A0);
  Serial.println(sensorvalue);
  delay(50);
  if(sensorvalue < 1000) {
    digitalWrite(buzzerpin, HIGH);
  }
  else {
    digitalWrite(buzzerpin, LOW);
  }
}
