#define sensorPin A5  
#define LED 2
int sensorValue;
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.print("sensorValue="); 
  Serial.println(sensorValue); 
if (sensorValue <240) {
digitalWrite(LED,LOW);
}
else {
  digitalWrite(LED,HIGH);
}
}
