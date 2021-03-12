#include <Arduino.h>
/*
  #include <ESP8266WiFi.h>

  String apiWritekey = "G5N29ENR7WE04MGL"; //THINGSPEAK API key
  const char *ssid = "ArViNd's sd845"; // wifi SSID name
  const char *password = "123123123";   // wifi pasword

  const char *server = "api.thingspeak.com";
  float resolution = 3.3 / 1023; //3.3 is the supply volt & 1023 is max analog read value
  WiFiClient client;

  void setup()
  {
  Serial.begin(115200);
  WiFi.disconnect();
  delay(10);
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
  Serial.println("");
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
  delay(15000);
  }
*/
//-----------Electronics-project-hub-------------//
//to reAD DATA FROM SERVER
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
const char ssid[] = "ArViNd's sd845"; // your network SSID (name)
const char pass[] = "123123123"; // your network password
int statusCode = 0;
WiFiClient client;
//LiquidCrystal_I2C lcd(0x27, 16, 2);

//---------Channel Details---------//
unsigned long counterChannelNumber = 888687;          // Channel ID
const char *myCounterReadAPIKey = "JE72L1Q9TV3HECT9"; // Read API Key
const int FieldNumber1 = 1;
//const int FieldNumber2 = 2;
//-------------------------------//

void setup()
{
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  //lcd.init();
  //lcd.backlight();
  //lcd.setCursor(0, 0);
  //lcd.print("Display Test:OK");
  Serial.println("serial link test ok");
  delay(1000);
}


void loop()
{
  //----------------- Network -----------------//
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("CONNECTING TO WIFI:");
    Serial.print(ssid);
    Serial.println("  ");
    /* lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Connecting to ");
      lcd.setCursor(0, 1);
      lcd.print(ssid);
      delay(1000);*/
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      delay(3000);
    }

    Serial.println("connected to wifi sucessfully");
    Serial.println("  ");
    /*  lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Conn.. to Wi-Fi");
      lcd.setCursor(0, 1);
      lcd.print("Succesfully.");
      delay(1000);
      lcd.clear();*/
  }
  //--------- End of Network connection--------//

  //---------------- Channel 1 ----------------//
  long tempc = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("Temperature:");
    Serial.print(tempc);
    Serial.print("*C");
    Serial.println("  ");
  }
  /*  lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.print(temp);
    lcd.print("*C");*/

  else
  {
    Serial.println("UNABLE TO READ OR NO INTERNET!");
    /*  lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Unable to read");
      lcd.setCursor(0, 1);
      lcd.print("or No internet!");*/
  }
  delay(100);}
  //-------------- End of Channel 1 -------------//

  //---------------- Channel 2 ----------------//
  /* long humidity = ThingSpeak.readLongField(counterChannelNumber, FieldNumber2, myCounterReadAPIKey);
    statusCode = ThingSpeak.getLastReadStatus();
    if (statusCode == 200)
    {
     lcd.setCursor(0, 1);
     lcd.print("Humidity:");
     lcd.print(humidity);
     lcd.print("%   ");
    }
    else
    {
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Unable to read");
     lcd.setCursor(0, 1);
     lcd.print("or No internet!");
    }
    delay(3000);
    //-------------- End of Channel 2 -------------//
    }*/
  //-----------Electronics-project-hub-------------//
