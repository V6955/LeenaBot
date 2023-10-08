int ledpinRed = 2;
int ledpinYellow = 3;
int ledpinGreen = 4;
void setup() {
  pinMode(ledpinRed, OUTPUT);
  pinMode(ledpinYellow, OUTPUT);
  pinMode(ledpinGreen, OUTPUT);
}
void loop() {
  changeLedState(ledpinRed, 3000);
  changeLedState(ledpinYellow, 1000);
  changeLedState(ledpinGreen, 3000);
}
void changeLedState(int ledpin, int duration) {
  if(ledpin == ledpinRed) {
    digitalWrite(ledpinRed, HIGH);
    digitalWrite(ledpinYellow, LOW);
    digitalWrite(ledpinGreen, LOW);
  }
  else if(ledpin == ledpinYellow) {
    digitalWrite(ledpinRed, LOW);
    digitalWrite(ledpinYellow, HIGH);
    digitalWrite(ledpinGreen, LOW);
  }
  else if(ledpin == ledpinGreen) {
    digitalWrite(ledpinRed, LOW);
    digitalWrite(ledpinYellow, LOW);
    digitalWrite(ledpinGreen, HIGH);
  }
  else {
    digitalWrite(ledpinRed, LOW);
    digitalWrite(ledpinYellow, LOW);
    digitalWrite(ledpinGreen, LOW);
  }
  delay(duration);
}
