#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;



void setup(){
	  Serial.begin(9600);
  while (!Serial) {
    ;
  }

String data="this is line one comment";
unsigned long time = micros();

  Serial.print("Initializing SD card...");
  
retry:
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
	Serial.println("retrying in 2sec");
	delay(2000);
	goto retry;
  }
  Serial.println("initialization done.");

  //check if file exists
    if (SD.exists("test.txt")) {
    Serial.println("test.txt exists.");
	SD.remove("test.txt");
  } else {
    Serial.println("test.txt doesn't exist.");
  }

  // open a new file and immediately close it:
  Serial.println("Creating test.txt...");
  myFile = SD.open("test.txt", FILE_WRITE);

  //open and write to file
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println(data);
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  Serial.println(time);
}
void loop(){
  
}
