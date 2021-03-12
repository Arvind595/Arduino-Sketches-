
//to reAD writr DATA to SERVER
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
String apiWritekey = "G5N29ENR7WE04MGL"; //THINGSPEAK API key
const char *ssid = "ArViNd's sd845"; // wifi SSID name
  const char *password = "123123123";   // wifi pasword
int statusCode = 0;

  const char *server = "api.thingspeak.com";
  float resolution = 3.3 / 1023; //3.3 is the supply volt & 1023 is max analog read value
  WiFiClient client;
  
unsigned long counterChannelNumber = 888687;          // Channel ID
const char *myCounterReadAPIKey = "JE72L1Q9TV3HECT9"; // Read API Key
const int FieldNumber1 = 1;

void setup()
{
  Serial.begin(115200);
   WiFi.disconnect();
  delay(10);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
 
  WiFi.begin(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
     Serial.print(".");
  }
   Serial.println();
  Serial.print("NodeMcu connected to wifi...");
  Serial.println(ssid);
  Serial.println();
  }


void loop()
{
  float temp = (analogRead(A0) * resolution) * 100;

  if (client.connect(server, 80))
  {
    String tsData = apiWritekey;
    tsData += "&field1=";
    tsData += String(temp);
    tsData += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiWritekey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(tsData.length());
    client.print("\n\n"); //the 2 carriage returns indicate closing of Header fields & starting of data
    client.print(tsData);

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println("uploaded to Thingspeak server....");
  }
  client.stop();

  Serial.println("Waiting to upload next reading...");
  Serial.println();
  // thingspeak needs minimum 15 sec delay between updates
  

//-----------------reading code---------------------//
  //---------------- Channel 1 ----------------//
   long tempc = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.println("reading from thinkspeak");
     Serial.println();
    
    Serial.print("Temperature:");
    Serial.print(tempc);
    Serial.print("*C");
     Serial.println();
     Serial.println();
    Serial.println("Waiting to upload next reading...");
  Serial.println();
  }

  else
  {
    Serial.println("UNABLE TO READ OR NO INTERNET!");
   
  }
    delay(15000);
}
