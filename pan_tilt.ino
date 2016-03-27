/*
Adafruit Arduino - Lesson 14. Sweep
*/
/* 
// Makes servos work separately.
#include <Servo.h> 
 
int servoPin1 = 9;
int servoPin2 = 6;
 
Servo servo1; 
Servo servo2; 
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2);
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo1.write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo1.write(angle);           
    delay(15);       
  } 
  {                                  
    servo2.write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo2.write(angle);           
    delay(15);       
  } 
} 
*/

// This makes both servos work simultaneously
#include <Servo.h> 
 
int servoPin1 = 9;
int servoPin2 = 6;
 
Servo servo1; 
Servo servo2; 
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2);
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo1.write(angle);
    servo2.write(angle);               
    delay(15); 
                    
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo1.write(angle); 
    servo2.write(angle);          
    delay(15);
          
  } 
  
} 
