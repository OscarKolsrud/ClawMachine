#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "SortlandKolsrudNETT";
const char* password = "Barenettverk123";
const char* mqttServer = "broker.shiftr.io";
const int mqttPort = 1883;
const char* mqttUser = "d65206d7";
const char* mqttPassword = "ClawMachine";

int MEGA = 23;
 
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
client.publish("game_started","started");
digitalWrite(MEGA, HIGH);
digitalWrite(LED, HIGH);
delay(150);
digitalWrite(LED, LOW);
delay(150);
digitalWrite(LED, HIGH);
delay(150);
digitalWrite(LED, LOW);
digitalWrite(MEGA, LOW);
}
 
void setup()
{
Serial.begin(115200);
WiFi.begin(ssid, password);
pinMode(LED,OUTPUT);
pinMode(MEGA, OUTPUT);
 
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
client.subscribe("game/online");
}
 
void loop()
{
client.loop();
}
