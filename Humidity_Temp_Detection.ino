#include<DHT.h>
#include<LiquidCrystal.h>
#define DHTPIN A0
#define DHTTYPE DHT11
LiquidCrystal lcd(12,11,5,4,3,2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.print("Temperature: ");
  Serial.print("Humidity: ");
  lcd.begin(16,2);
  dht.begin();
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print(h);
  Serial.print(" ");
  Serial.print(t);
  lcd.print("Temperature: ");
  lcd.print(t);
  lcd.print(char(223));
  lcd.print("c");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  delay(100);
  lcd.clear();
}
