#include <DHT.h>

#define DHTPIN 2        // Pin du capteur DHT11/DHT22
#define DHTTYPE DHT11   // Change en DHT22 si t’as DHT22
#define RELAY_PIN 7     // Pin du relais pour ventilo
#define TEMP_THRESHOLD 28.0  // Seuil température °C
#define HUM_THRESHOLD 70.0   // Seuil humidité %

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relais OFF au démarrage
  dht.begin();
  Serial.println("Smart Fan Controller V1 démarré");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Erreur lecture DHT !");
    delay(2000);
    return;
  }

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print("°C | Hum: "); Serial.print(hum);
  Serial.println("%");

  // Logique intelligente
  if (temp > TEMP_THRESHOLD || hum > HUM_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW); // Relais ON → Ventilo tourne
    Serial.println("→ VENTILO ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Relais OFF
    Serial.println("→ VENTILO OFF");
  }
  
  delay(2000); // Lecture toutes les 2s
}