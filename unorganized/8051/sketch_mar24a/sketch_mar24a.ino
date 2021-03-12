#include <ESP8266WiFi.h>

const char* ssid = "ArViNd'S sd845🔥";
const char* password ="zxcvbnm,.";


const char* host = "ortex.lt";
String line;

void setup()
{
  pinMode(2,OUTPUT);
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  digitalWrite(2,LOW);
  delay(1000);
  digitalWrite(2,HIGH);
  delay(500);
    digitalWrite(2,LOW);
  delay(1000);
  digitalWrite(2,HIGH);
  delay(500);
   digitalWrite(2,LOW);
}


void loop()
{
  WiFiClient client;
  Serial.printf("\n[Connecting to %s ... ", host);
  if (client.connect(host, 80))
  {
    Serial.println("connected]");

    Serial.println("[Sending a request]");
    String url = "https://www.mohfw.gov.in/";
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
               "Connection: close\r\n" +
                "\r\n"
                );

    Serial.println("[Response:]");
    while (client.connected())
   {    
    line = client.readStringUntil('\r');
    Serial.print(line);
   }

    client.stop();
    Serial.println("\n[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    client.stop();
  }  
  delay(5000);
}
