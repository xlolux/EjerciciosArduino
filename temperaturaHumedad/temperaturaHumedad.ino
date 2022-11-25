#include <DHT.h>
const int DHTPIN = 2;
const int ledPIN = 12;
const char* DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);// Inicializamos el sensor DHT11
void setup() {
  Serial.begin(9600);
  dht.begin();
 
}
void loop() {
  delay(5000);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
  if(temperature > 10 && humidity <80){
    digitalWrite(ledPIN , HIGH);
  }else{
    digitalWrite(ledPIN , LOW);
  }
  Serial.print("Humedad: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print(" *C ");
}