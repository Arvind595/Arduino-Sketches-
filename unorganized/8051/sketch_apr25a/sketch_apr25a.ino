byte binary[7] = {0, 0, 0, 0, 0, 0, 0};
#define latchPin 6
#define dataPin 5
#define clockPin 3
#define registers 2
uint8_t modifyBit(uint8_t number, uint8_t position, bool value) {
  position = position - 1;
  uint8_t mask = 1 << position;
  return (number & ~mask) | ((value << position) & mask);
}
void updateRegister() {
  for(int i=0 ; i<registers;i++){
  shiftOut(dataPin, clockPin, LSBFIRST, binary[i]);
}
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}
void setPin(uint8_t pin, bool voltage) {
  uint8_t chipn = 0;
  for (unsigned int i = 8, j = 8; i <= 4080; i = i + 8, j = j + 7) {
    if (pin <= i) {
      chipn = i - j;
      break;
    }
  }
  binary[chipn]=modifyBit(binary[chipn], (pin-(8*chipn)), voltage);
  updateRegister();
}
void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  
  updateRegister();
for (int i=1;i<=16;i++){
    Serial.print("BINARYIES: ");
  for (int i = 0; i < 7; i++) {
    Serial.print(binary[i]);
    Serial.print(",");
  }
  Serial.println();
  setPin(i, HIGH);
  delay(500);
}


}
void loop(){}
