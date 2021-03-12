#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "ArViNd'S sd845";
const char* password = "123456789";
 const char *host = "jsonplaceholder.typicode.com";
const int httpsPort = 443;
const char fingerprint[] PROGMEM = "B7 CB 1D 1B 02 72 1D 0E 89 A7 94 92 55 38 A7 37 9B 5D CD C4";
void setup () {
 
Serial.begin(115200);
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) {
 
delay(1000);
Serial.print("Connecting..");
 
}
 
}
 
void loop() {
 
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
WiFiClientSecure https;  //Declare an object of class HTTPClient
  https.setFingerprint(fingerprint);
  https.setTimeout(15000); // 15 Seconds
  delay(1000);
    Serial.print("HTTPS Connecting");
  int r=0; //retry counter
  while((!https.connect(host, httpsPort)) && (r < 30)){
      delay(100);
      Serial.print(".");
      r++;
  }
  if(r==30) {
    Serial.println("Connection failed");
  }
  else {
    Serial.println("Connected to web");
  }
https.begin("https://coronavirus-19-api.herokuapp.com/countries/india");  //Specify request destination
int httpCode = https.GET();                                                                  //Send the request
 
if (httpCode > 0) { //Check the returning code
 
String payload = https.getString();   //Get the request response payload
Serial.println(payload);                     //Print the response payload
 
}
 
https.end();   //Close connection
 
}
 
delay(30000);    //Send a request every 30 seconds
 
}
