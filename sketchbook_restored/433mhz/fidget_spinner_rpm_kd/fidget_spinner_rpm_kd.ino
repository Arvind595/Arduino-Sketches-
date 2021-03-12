//Spinner Tachometer Test Code 
//Kevin Darrah 5/2/17
#include <LiquidCrystal.h>
 #include <SPI.h>
 #define CSpin 2

LiquidCrystal lcd(10);
 float frequency, frqArray[10], RPM, frqAvg; byte full_count; 
byte digits[8];
 void displayCounter(); 
void initMAX7219(); 
void setup() {
    lcd.begin(16,2);
    
     initMAX7219();
     noInterrupts();
     pinMode(8, INPUT);
    //for input capture
     TCCR1A = B00000000; 
    TCCR1B = B11000001;
    //b7 Noise Canceling ON, b6 Rising Edge Input Capture, Full Speed /1 Clock
     TIMSK1 = B00100001; Serial.begin(115200);
     interrupts(); 
    } 
void loop() { 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Freq: ");
    lcd.print(frequency);
    lcd.print(" Hz");
    lcd.setCursor(0,1);
    lcd.print("Rpm: ");
    lcd.print(RPM);
    delay(500);
     Serial.print(frequency, 2); 
     Serial.print("Hz ");
     frqAvg = 0; 
    for (byte i = 0; i < 10; i++) { 
        frqAvg = frqArray[i] + frqAvg; 
        } 
    frqAvg = frqAvg / 10; 
    RPM = frqAvg * 60.00;
     Serial.print(RPM, 2); 
    Serial.print("RPM "); 
    RPM = RPM / 7; 
    Serial.print(RPM, 2); 
     Serial.println("RPM/7 ");
     displayCounter();
     delay(50);
     } 
void displayCounter() { 
    unsigned long digitsCounter = int(RPM); for (int i = 0; i < 8; i++) {
         digits[i] = digitsCounter % 10;
         if (int(RPM) < pow(10, i)) 
        // 1, 10, 100, 1000....
         digits[i] = 0x0F; 
        digitsCounter /= 10; PORTD &= ~(1 << CSpin);
         SPI.transfer(i + 1); SPI.transfer(digits[i]);
         PORTD |= (1 << CSpin); 
        } 
    } 
void initMAX7219() {
     SPI.setClockDivider(SPI_CLOCK_DIV2); SPI.setDataMode(SPI_MODE0); SPI.setBitOrder(MSBFIRST); digitalWrite(CSpin, HIGH); 
    pinMode(CSpin, OUTPUT); 
    SPI.begin();
     digitalWrite(CSpin, LOW);
    //come out of shutdown
     SPI.transfer(0x0C); 
    SPI.transfer(0x01); 
    digitalWrite(CSpin, HIGH); digitalWrite(CSpin, LOW);
    //decode 8 digits 
    SPI.transfer(0x09);
     SPI.transfer(0xFF);
     digitalWrite(CSpin, HIGH); 
    for (int i = 1; i < 9; i++) {
        //set all digits OFF
         digitalWrite(CSpin, LOW);
        //digit 0
         SPI.transfer(i); 
        SPI.transfer(0x0F); digitalWrite(CSpin, HIGH);
         } 
    digitalWrite(CSpin, LOW);
    //intensity 
    SPI.transfer(0x0A);
     SPI.transfer(0x07); 
    digitalWrite(CSpin, HIGH); digitalWrite(CSpin, LOW);
    //scan limit - all 8
     SPI.transfer(0x0B);
     SPI.transfer(0x07); 
    digitalWrite(CSpin, HIGH); 
    } 
ISR(TIMER1_CAPT_vect) {
     TCNT1 = 0; frequency = 1000 / ((ICR1 + full_count * 65535) * 0.0000625); 
    full_count = 0;
     for (byte i = 9; i > 0; i--) { frqArray[i] = frqArray[i - 1]; 
        } 
    frqArray[0] = frequency; 
    frequency = frequency/10.00; 
    }
//interrupt
 ISR(TIMER1_OVF_vect) { 
    TCNT1 = 0; full_count++; 
    }
// overflow