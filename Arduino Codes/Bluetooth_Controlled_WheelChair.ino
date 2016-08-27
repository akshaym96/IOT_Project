
 #include <SoftwareSerial.h>
// ic 3 red color ic 6 black  right motor
// ic 14 black ic 11 red left motor
int motorPin1 = 4; // pin 2 on L293D IC  
int motorPin2 = 3; // pin 7 on L293D IC    //
int motor1Pin1=1; // pin 15 on L293D IC
int motor1Pin2=11; // pin 10 on L293D IC
int enablePin = 5; // pin 1 on L293D IC
int enablepin2=0; // pin 9 on L293D IC
int state;  //char character;
int flag=0;        //makes sure that the serial only prints once the state
int btx=9; // tx on BTl 
int brx=10;// rx on BT
SoftwareSerial mySerial(btx, brx);
void setup() {

       mySerial.begin(9600);
    Serial.begin(9600);
    // sets the pins as outputs:
    pinMode(motorPin1, OUTPUT);// 1st motor pin 3 on L293D IC
    pinMode(motorPin2, OUTPUT); //pin 6 on L293D IC
    pinMode(motor1Pin1, OUTPUT);// 2nd motor pin  14 on L293D IC
    pinMode(motor1Pin2, OUTPUT);// pin 11 on L293D IC
  
    pinMode(enablePin, OUTPUT); //  pin 1 on L293D IC
    pinMode(enablepin2, OUTPUT);// sets enablePin high so that motor can turn on: pin 9 on L293D IC
    digitalWrite(enablePin, HIGH);
    digitalWrite(enablepin2, HIGH);
    
   
//delay(1000);

}

void loop() {
    //if some date is sent, reads it and saves in state
  
    if(mySerial.available()>0)
    {
      
      state = mySerial.read();
       if (state == '0') {     //STOP
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW);
         digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, LOW);
        // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor: off");
          flag=1;
        }
    }
    // if the state is '1' the motor will move forward
    if (state == '1') {          
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, HIGH);
         digitalWrite(motor1Pin1,HIGH ); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, LOW);
        // set pin 7 on L293D high
        if(flag == 0){
          Serial.println("Motor: FORWARD");
          flag=1;
        }
    }
    // if the state is '2' the motor will move backward
     if (state == '2') {
        digitalWrite(motorPin1, HIGH ); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW);
         digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, HIGH);
        // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor: BACKWARD");
          flag=1;
        }
    }
       if (state == '3') {
        digitalWrite(motorPin1, LOW ); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW);
         digitalWrite(motor1Pin1, HIGH); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, LOW);
        // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor:RIGHT");
          flag=1;
        }
    }

  if (state == '4') {
        digitalWrite(motorPin1, LOW ); // set pin 2 on L293D high
        digitalWrite(motorPin2, HIGH);
         digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, LOW);
        // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor: LEFT");
          flag=1;
        }
    }
    
      
     /* 
      
      
      
      
      
      
      
      
      }
    
    
    
    
    
    
    
    String Data = "";
    
     Data.concat(character);
     Serial.println(Data);
//     Serial.println("foo");
     
    Serial.print("State input: ");
    Serial.println(state);
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is '0' the DC motor will turn off
    if (state == 0) {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor: off");
          flag=1;
        }
    }
    // if the state is '1' the motor will turn right
    else if (state == 1) {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
        if(flag == 0){
          Serial.println("Motor: right");
          flag=1;
        }
    }
    // if the state is '2' the motor will turn left
    else if (state == '2') {
        digitalWrite(motorPin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor: left");
          flag=1;
        }
    }*/
}
}
