    char* pBuffer;                              // Declare a pointer to your buffer.
    myFile = SD.open(F("fileName.txt"));        // Open file for reading.
    if (myFile)
    {
        unsigned int fileSize = myFile.size();  // Get the file size.
        pBuffer = (char*)malloc(fileSize + 1);  // Allocate memory for the file and a terminating null char.
        myFile.read(pBuffer, fileSize);         // Read the file into the buffer.
        pBuffer[fileSize] = '\0';               // Add the terminating null char.
        Serial.println(pBuffer);                // Print the file to the serial monitor.
        myFile.close();                         // Close the file.
    }
    // *** Use the buffer as needed here. ***
    free(pBuffer);                              // Free the memory that was used by the buffer.
	
	
	
	//pointer to array copy
	#include <string.h>
#include<stdio.h>

int main(void) {
  char *src = "gkjsdh";
  char dst[10]; /* not enough for all of src */
printf("hello ");
  strcpy(dst, src); /* BANG!!! */
  strncpy(dst, src, sizeof dst - 1); /* OK ... but `dst` needs to be NUL terminated */
      dst[9] = '\0';
printf("%s", dst);
  return 0;
}



After further research, I got how .read works: It reads the character its cursor is pointing at while advancing the cursor.

So, in order to read the entirety of the file you have to remove the Serial.write portion and convert the characters into char:

string finalString="";
while (mappa.available())
{
finalString+=(char)mappa.read();
}


////////////////////////////////////////////////////////////////////////
  char* pBuffer;
  myFile = SD.open(F("test.txt"));
  if (myFile) {
    Serial.println("reading File");
     unsigned int fileSize = myFile.size();
      pBuffer = (char*)malloc(fileSize + 1);
       myFile.read(pBuffer, fileSize);
       pBuffer[fileSize] = '\0';
       Serial.println(pBuffer);
       myFile.close();
  }
   else {
    // if the file didn't open, print an error:
    Serial.println("error opening File");
  }