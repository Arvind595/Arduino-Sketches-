	#include <string.h>
#include<stdio.h>

int main(void) {
  char *src = "abcdefghijklmnopqrstuvwxyz";
  char dst[27]; /* not enough for all of src */
printf("hello ");
  //strcpy(dst, src); /* BANG!!! */
  strncpy(dst, src, sizeof dst - 1); /* OK ... but `dst` needs to be NUL terminated */
      dst[sizeof(dst)-1] = '\0';
printf("%s", dst);
  return 0;
}
//next code :

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
File myFile;
void setup(){
	  Serial.begin(9600);
  while (!Serial) {
    ;
  }

String data="this is line one 555 comment";
unsigned long time = micros();


	//Check SD card Connection.
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");


  //check if file exists
    if (SD.exists("test.txt")) {
			Serial.println("File exists.");
			//SD.remove("test.txt");
			//Serial.println("removed File");
  }
	else {
		Serial.println("File doesn't exist.");
		// open a new file and immediately close it:
		Serial.println("Creating File...");
		myFile = SD.open("test.txt", FILE_WRITE);
		myFile.close();

  }


  //open and write to file
	myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    //Serial.print("Writing to File...");
    //myFile.println(data);
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening File");
  }

  // re-open the file for reading:
  String pBuffer="";
  myFile = SD.open(F("test.txt"));
	Serial.println("reading File");

	if(!myFile){
	 // if the file didn't open, print an error:
	 Serial.println("error opening File");
 }

		while(myFile.available()){
     pBuffer+=(char)myFile.read();
	 }

	Serial.println(pBuffer+"aravind");
	myFile.close();
  Serial.println(time);
}

void loop(){

}
