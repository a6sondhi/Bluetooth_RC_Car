/* 
 *  Bluetooth RC Car
 *  An arduino based RC car that makes use of the arduino motor shield and HC-06 bluetooth module
 *  Aaditya Sondhi
*/


#include <AFMotor.h> //Motor shield library

AF_DCMotor motorR(1); //Right motor setup
AF_DCMotor motorL(4); //Left motor setup

void setup() {
  Serial.begin(9600); //Setup serial comminication
  Serial.println("RC Car by Aaditya Sondhi");

  // turn on motors
  motorL.setSpeed(255);
  motorR.setSpeed(255);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
}

void loop() {
  
   if(Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    Serial.write(Serial.read());
   
    switch (data)
    {
      case '1': //FORWARD
        motorL.run(FORWARD);
        motorL.setSpeed(255);    
        motorR.run(FORWARD);
        motorR.setSpeed(255);
        break;
      case '2': //REVERSE
        motorL.run(BACKWARD);
        motorL.setSpeed(255);    
        motorR.run(BACKWARD);
        motorR.setSpeed(255);
        break;
      case '3': //FORWARD LEFT
        motorR.run(FORWARD);
        motorR.setSpeed(255);
        break;
      case '4': //FORWARD RIGHT
        motorL.run(FORWARD);
        motorL.setSpeed(255);
        break;
      case '5': //REVERSE LEFT
        motorL.run(BACKWARD);
        motorL.setSpeed(255);
        break;
      case '6': //REVERSE RIGHT
        motorR.run(BACKWARD);
        motorR.setSpeed(255);
        break;
      default: //If bluetooth module receives any value not listed above, both motors turn off
        motorL.run(RELEASE);
        motorR.run(RELEASE);
    }

    
  }
 
 
}
