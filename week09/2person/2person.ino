#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "NoInternet";     
const char WIFI_PASSWORD[] = "12345678pan";  
const char MQTT_BROKER[] = "mqtt-dashboard.com";  
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "Sender-Arduino";  
const char PUBLISH_TOPIC[] = "iot/chompoo";    


WiFiClient network;
MQTTClient mqtt(256);

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT); // Potentiometer อ่านค่าจาก A0

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected to WiFi");

  mqtt.begin(MQTT_BROKER, MQTT_PORT, network);
  while (!mqtt.connect(MQTT_CLIENT_ID)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected to MQTT Broker");
}

void loop() {
  mqtt.loop();
  
  int potValue = analogRead(A0); // อ่านค่าจาก Potentiometer (0-1023)
  int brightness = map(potValue, 0, 1023, 0, 255); // แปลงค่าเป็น 0-255

  String brightnessStr = String(brightness);
  mqtt.publish(PUBLISH_TOPIC, brightnessStr.c_str());

  Serial.print("Sent Brightness: ");
  Serial.println(brightness);

  delay(1000); // ส่งทุก 1 วินาที
}