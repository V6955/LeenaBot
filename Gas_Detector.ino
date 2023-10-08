int sensorvalue;
int Gassensorpin = A0;
int buzzerpin = 3;
void setup() {
  pinMode(buzzerpin, OUTPUT);
  pinMode(Gassensorpin, INPUT);
  Serial.begin(9600);
}
void sms(){
  Serial.begin(9600);
  Serial.print("\r");
  delay(1000);
  Serial.print("AT+CMGS=1\r");
  delay(1000);
  Serial.print("AT+CMGF=\" + 3013776327\"\r");
  delay(1000);
  Serial.print("Gas Detected");
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
}
void loop(){
  sensorvalue = analogRead(Gassensorpin);
  Serial.println(sensorvalue, DEC);
  if(sensorvalue < 350)
  {
    Serial.println("No Gas");
    digitalWrite(buzzerpin, LOW);
  }
  else {
    Serial.println("Gas Detected"); 
    digitalWrite(buzzerpin, HIGH);
    sms();
  }
  delay(1000);
}
