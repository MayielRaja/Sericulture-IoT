#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include "DHT.h"

// WiFi Credentials
#define WIFI_SSID "OPPO F17 Pro" // wifi name
#define WIFI_PASS "stupid data" // wifi password

// Firebase Configuration
#define DATABASE_URL "https://sericulture-monitor-*****-default-rtdb.firebaseio.com/"    / firebase url
#define API_KEY "************************"                                              //API key of firebase url

// Firebase Objects
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// DHT22 Sensor Setup
#define DHTPIN 4    
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Relay Pins for Peltier & Fan
#define PELTIER_RELAY 13
#define FAN_RELAY 14

// LDR Sensor Pin
#define LDR_PIN 34  // Analog Pin for LDR (ESP32 ADC)

// I2C LCD Display Setup
LiquidCrystal_PCF8574 lcd(0x27); // Default I2C address

// Temperature Threshold
#define THRESHOLD_TEMP 25.0  

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  // Firebase Setup
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  // Enable Anonymous Sign-in
  auth.user.email = "";
  auth.user.password = "";
  Firebase.signUp(&config, &auth, "", "");

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Setup Pins
  pinMode(PELTIER_RELAY, OUTPUT);
  pinMode(FAN_RELAY, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  
  // Start DHT sensor
  dht.begin();

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.setCursor(0, 0);
  lcd.print("System Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read Temperature & Humidity from DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read Light Intensity from LDR
  int lightIntensity = analogRead(LDR_PIN);
  
  // Print values to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Light: ");
  Serial.println(lightIntensity);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: "); lcd.print(temperature); lcd.print("C  ");
  lcd.setCursor(0, 1);
  lcd.print("Hum: "); lcd.print(humidity); lcd.print("%  ");

  // Control Peltier & Fan based on temperature
  if (!isnan(temperature)) {
    if (temperature > THRESHOLD_TEMP) {
      digitalWrite(PELTIER_RELAY, LOW); // Relay ON
      digitalWrite(FAN_RELAY, LOW);
      Serial.println("Peltier & Fan: ON");
      Firebase.RTDB.setString(&fbdo, "/peltier/status", "ON");
    } else {
      digitalWrite(PELTIER_RELAY, HIGH);
      digitalWrite(FAN_RELAY, HIGH);
      Serial.println("Peltier & Fan: OFF");
      Firebase.RTDB.setString(&fbdo, "/peltier/status", "OFF");
    }

    // Send data to Firebase
    Firebase.RTDB.setFloat(&fbdo, "/peltier/temperature", temperature);
    Firebase.RTDB.setFloat(&fbdo, "/peltier/humidity", humidity);
    Firebase.RTDB.setInt(&fbdo, "/peltier/light", lightIntensity);
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }

  delay(5000);
}
