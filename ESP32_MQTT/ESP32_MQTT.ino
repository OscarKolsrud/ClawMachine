#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "SortlandKolsrudNETT";
const char* password = "XXX-XXX-XXX";
const char* mqttServer = "m24.cloudmqtt.com";
const int mqttPort = 14523;
const char* mqttUser = "iqtmxfoj";
const char* mqttPassword = "i2V4Of9K1Nu8";
 
WiFiClient espClient;
PubSubClient client(espClient);

#define LED 2

void callback(char* topic, byte* payload, unsigned int length)
{
Serial.print("Message arrived in topic: ");
Serial.println(topic);
Serial.print("Message:");
for (int i = 0; i < length; i++)
{
Serial.print((char)payload[i]);
}
Serial.println();
Serial.println("-----------------------");
digitalWrite(LED,HIGH);
delay(1500);
digitalWrite(LED,LOW);
}
 
void setup()
{
Serial.begin(115200);
WiFi.begin(ssid, password);
pinMode(LED,OUTPUT);
 
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.println("Connecting to WiFi..");
}
Serial.println("Connected to the WiFi network");
 
client.setServer(mqttServer, mqttPort);
client.setCallback(callback);
 
while (!client.connected()) {
Serial.println("Connecting to MQTT...");
 
if (client.connect("ESP32Client", mqttUser, mqttPassword ))
{
Serial.println("connected");
}
else
{
Serial.print("failed with state ");
Serial.print(client.state());
delay(2000);
}
}
client.subscribe("esp32/esp32test");
 
}
 
void loop()
{
client.loop();
}
