#include <WiFiS3.h>
#include <ArtronShop_LineNotify.h>
#define LINE_TOKEN "XuUcpi5Sz9U7YH9EMokJ8rI76oMXpEEmNfaszYgPmxT"
#include "DHT.h"
#define DHTPIN 2
const char* ssid = "NoInternet";  // Your SSID
const char* password = "12345678pan";  // Your Password
#define DHTTYPE DHT11  // DHT 11
//#define DHTTYPE DHT22  // DHT 22 (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
String TextNotify;

void setup() {
  Serial.begin(9600);

  // Connect to the Wi-Fi network
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Since there’s no password, pass only the SSID
  WiFi.begin(ssid, password);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  Serial.println("\nConnected to WiFi network");
  // Print the IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  dht.begin();
  LINE.begin(LINE_TOKEN);
  LINE.send("Hello from Arduino R4 !");
}

void loop() {
  delay(1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  
  // Read humidity
  float h = dht.readHumidity();
  
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  
  // Compute heat index in Celsius (isFahrenheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C  "));

  Serial.print(F("Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C  "));
  Serial.print(hif);
  Serial.println(F("°F"));

  TextNotify = "Now Humidity: " + String(h) + "%  Temperature: " + String(t) + "°C  Heat index: " + String(hic) + "°C  " + String(hif) + "°F";
  LINE.send(TextNotify);
}