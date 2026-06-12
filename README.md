# Smart Fan Controller V1
**Ventilateur intelligent - Projet CSC 2027 Bénin**

### 🎯 Objectif
Allumer/éteindre automatiquement un ventilateur selon la température et l’humidité ambiante. 
Confort optimal + économie d’énergie.

### 🔧 Matériel utilisé
- Arduino Uno
- Capteur DHT11/DHT22 Température + Humidité  
- Module Relais 5V + Ventilateur 12V
- Alimentation 12V

### ⚡ Logique de fonctionnement
```cpp
Si Température > 28°C OU Humidité > 70% → Ventilo ON
Sinon → Ventilo OFF