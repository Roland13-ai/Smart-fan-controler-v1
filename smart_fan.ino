#include <DHT.h>

#define DHTPIN 2 // Pin for DHT11/DHT22 sensor
#define DHTTYPE DHT11 // Change to DHT22 if you have DHT22
#define RELAY_PIN 7 // Pin for fan relay
#define PIR_PIN 4 // Pin for PIR presence sensor (HC-SR501)
#define TEMP_THRESHOLD 28.0 // Temperature threshold °C
#define HUM_THRESHOLD 70.0 // Humidity threshold %

DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
pinMode(RELAY_PIN, OUTPUT);
pinMode(PIR_PIN, INPUT);
digitalWrite(RELAY_PIN, HIGH); // Relay OFF at startup
dht.begin();

Serial.println("Smart Fan Controller V2 started");
}

void loop() { 
float temp = dht.readTemperature(); 
float hum = dht.readHumidity(); 
bool presence = digitalRead(PIR_PIN); 

if (isnan(temp) || isnan(hum)) { 
Serial.println("DHT reading error!"); 
delay(2000); 
return; 
} 

Serial.print("Temp: "); Serial.print(temp); 
Serial.print("°C | Hum: "); Serial.print(hum); 
Serial.print("% | Presence: "); Serial.println(presence ? “YES” : “NO”); 

// Intelligent logic: heat/humidity AND human presence

if ((temp > TEMP_THRESHOLD || hum > HUM_THRESHOLD) && presence) {
digitalWrite(RELAY_PIN, LOW); // Relay ON → Fan turns on
Serial.println("-> FAN ON (heat + presence detected)");

} else {
digitalWrite(RELAY_PIN, HIGH); // Relay OFF
Serial.println("-> FAN OFF");
}

delay(2000); // Read every 2 seconds
}
