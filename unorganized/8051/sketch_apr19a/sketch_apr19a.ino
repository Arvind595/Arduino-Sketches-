#include<IOexpander.h>

IOexpander io(1,4,3,2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(io.readPin(3));
delay(1000);
}
