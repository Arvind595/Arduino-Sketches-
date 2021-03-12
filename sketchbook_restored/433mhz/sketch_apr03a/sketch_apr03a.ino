void setup() {  
    Serial.begin(9600);             // using serial port to check analog value 
     pinMode(2, OUTPUT);             // LED on digital pin 2 
    }
 void loop() { 
     int analog_val;                 // analog value read from A2 
     static bool led_state = false;  
    // current state of LED    
    analog_val = analogRead(A2); 
     if (analog_val > 10) {          // trigger threshold    // toggle LED   
         if (led_state) {      
            led_state = false;          // LED was on, now off     
             digitalWrite(2, LOW);      Serial.println(analog_val); // print analog value for debug purposes    
            }    else {     
             led_state = true;      digitalWrite(2, HIGH);      // LED was off, now on      
            Serial.println(analog_val); 
               }    delay(50); 
         // wait for clap noise to subside  
        } }