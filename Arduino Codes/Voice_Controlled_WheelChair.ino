#include <SoftwareSerial.h>

SoftwareSerial BT(9, 10); //TX, RX respetively
String readvoice;
int motorPin1 = 4; // pin 2 on L293D IC  
int motorPin2 = 3; // pin 7 on L293D IC    //
int motor1Pin1=1; // pin 15 on L293D IC
int motor1Pin2=11; // pin 10 on L293D IC
int enablePin = 5; // pin 1 on L293D IC
int enablepin2=0; // pin 9 on L293D IC
int flag=0;
void setup() {
 BT.begin(9600);
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

}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

  if(readvoice == "forward")
  {
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

  else if(readvoice == "backward")
  {
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

  else if (readvoice == "right")
  {
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

 else if ( readvoice == "left")
 {
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

 else if (readvoice == "stop")
 {
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
readvoice="";}} //Reset the variable
