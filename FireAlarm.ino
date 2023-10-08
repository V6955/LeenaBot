const int Buzzer = 11;
const int thermistor = A0;
int Average = 0;
int sensorvalue;
void setup() {
  long sum = 0;
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, LOW);
  delay(1000);
  for(int i = 0; i<500; i++) {
    sensorvalue = analogRead(thermistor);
    sum += sensorvalue;
    delay(5);
    Average = sum/500;
    Serial.print("Average= ");
    Serial.println(Average);
  }
}
void loop(){
int temp;
sensorvalue = analogRead(thermistor);
Serial.print("Sensorvalue=");
Serial.println(sensorvalue);
Serial.print(" , ");
Serial.print("Average=");
Serial.println(Average);
delay(1000);
temp=Average-sensorvalue;
if(temp>=200){
  digitalWrite(Buzzer, HIGH);
  delay(3000);
  digitalWrite(Buzzer, LOW);
  delay(1000);
}
else{
  digitalWrite(Buzzer, LOW);
}
}
