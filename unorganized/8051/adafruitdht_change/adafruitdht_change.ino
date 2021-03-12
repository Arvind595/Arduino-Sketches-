
#include "DHT.h"
DHT dht(11, DHT11);
void setup() {
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(12, 0);
  digitalWrite(10, 1);
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

}
