#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
DHT dht(8, DHT11);

void setup() {
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  delay(500);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C");
}
