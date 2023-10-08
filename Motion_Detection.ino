const int PIR = 13;
int PIROUTPUT;
int Buzzer = 10;

void setup() {
  pinMode(Buzzer, OUTPUT);
  pinMode(PIR, INPUT);
}
void loop() {
  PIROUTPUT = digitalRead(PIR);
  if(PIROUTPUT == HIGH)
 {
  digitalWrite(Buzzer, HIGH);
 }
 else {
  digitalWrite(Buzzer, LOW);
 }
}
