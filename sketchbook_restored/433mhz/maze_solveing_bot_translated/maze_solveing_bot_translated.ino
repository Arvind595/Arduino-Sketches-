
    // definitions and declarations of variables of the robot code maze resolver;
    
    #define vel_motor_esq 10 // controls left motor speed;
    #define vel_motor_dir 11 // controls the right motor speed;
    #define e1 8 // controls the direction of rotation of the left motor;
    #define e2 9 // controls the direction of rotation of the left motor;
    #define d1 12 // controls the direction of rotation of the right motor;
    #define d2 7 // controls the direction of rotation of the right motor;
 
    int trigger_face = A4; // controls the pulse sent from the front sensor
    int echo_frente = A5; // controls the pulse received from the front sensor
    
    int trigger_esq = A2; // controls the sent forward sensor pulse
    int echo_esq = A3; // controls the received pulse from the front sensor
    
    int trigger_dir = A0; // controls the forward sensor sent pulse
    int echo_dir = A1; // controls the received pulse from the front sensor
    
    // configuration of input types of declared variables;
    void setup ()
    {
        pinMode (trigger_face, OUTPUT); // arduino signal output from trigger_frente
        pinMode (echo_frente, INPUT); // arduino signal input from echo_frente
        
        pinMode (trigger_esq, OUTPUT); // arduino signal output from trigger_frente
        pinMode (echo_esq, INPUT); // arduino signal input from echo_frente
        
        pinMode (trigger_dir, OUTPUT); // triggered arduino signal output
        pinMode (echo_dir, INPUT); // arduino signal input from echo_frente
       
        pinMode (vel_motor_esq, OUTPUT); // arduino signal output from left motor speed
        pinMode (vel_motor_dir, OUTPUT); // arduino signal output from the right motor speed
     
        pinMode (e1, OUTPUT); // arduino signal output from the left motor rotation direction control
        pinMode (e2, OUTPUT); // arduino signal output from the left motor rotation direction control
        pinMode (d1, OUTPUT); // arduino signal output from the right motor rotation direction control
        pinMode (d2, OUTPUT); // arduino signal output from the right motor rotation direction control
        delay (5000);
    }
    
    // code in infinite repetition of the project;
    void loop ()
    {
     // declaration of variables used to control the project;
     long duracao_frente, duracao_esq, duracao_dir, right, left, front;
     
     
     digitalWrite (trigger_face, LOW); // their respective signal inputs and outputs are declared
     delayMicroseconds (2); // Ultrasonic sensor and stored by sensor variable
     digitalWrite (trigger_face, HIGH); // which converts the velocity of the sound which is 340 m / s or
     delayMicroseconds (5); // 29 microseconds per centimeter, as the signal goes back and forth
     digitalWrite (trigger_face, LOW); // this time is half being sensor = time / 29/2;
     duracao_frente = pulseIn (echo_frente, HIGH); // so also on the other two sensors.
     front = duration / 29/2;
    
     digitalWrite (trigger_esq, LOW);
     delayMicroseconds (2);
     digitalWrite (trigger_esq, HIGH);
     delayMicroseconds (5);
     digitalWrite (trigger_esq, LOW);
     duracao_esq = pulseIn (echo_esq, HIGH);
     left = duration / 29/2;
    
     digitalWrite (trigger_dir, LOW);
     delayMicroseconds (2);
     digitalWrite (trigger_dir, HIGH);
     delayMicroseconds (5);
     digitalWrite (trigger_dir, LOW);
     duracao_dir = pulseIn (echo_dir, HIGH);
     right = duracao_dir / 29/2;
     
     analogWrite (vel_motor_esq, 0); // block to initialize inputs with pulse 0 or off;
     analogWrite (vel_motor_dir, 0); //
     analogWrite (e1, 0); //
     analogWrite (e2, 0); //
     analogWrite (d1, 0); //
     analogWrite (d2, 0); //
     
       if (front> 8) // if there is a free path ahead it follows this logic below:
         {
           // the four if's use below within this if are for the control of robot drivability,
           // in order to keep it following the right wall in a straight line;
           
           if (right> 7 && right <13) // if the distance from the wall to the right is between 9 and 12 cm, the robot
                                         // maintains a straight line;
             {
               analogWrite (vel_motor_esq, 120);
               analogWrite (vel_motor_dir, 150);
           
               analogWrite (e1, 255);
               analogWrite (e2, 0);
               analogWrite (d1, 0);
               analogWrite (d2, 255);
             }