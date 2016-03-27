/* www.duino-robotics.com/obstacle-avoidance.html
 *  Jaidyn Edwards
 *  March 6, 2016
*/

#include <Servo.h>     //Inclue Servo Library 
#include <NewPing.h>   //Include NewPing Library

// Added Right DC Motor
const int motorR1 = 6;
const int motorR2 = 7;

// Added Left DC Motor
const int motorL1 = 4;
const int motorL2 = 5;

// Removed Servo leftServo;       //Create Left Servo object
// Removed Servo rightServo;      //Create Right Servo object

#define TRIGGER_PIN  12   //Trigger pin of Ultrasonic sensor connected to pin 6
#define ECHO_PIN     11   //Echo pin of Ultrasonic sensor connected to pin 7
#define MAX_DISTANCE 400 //The maximum distance we want the sensor to look for is 1m

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  //Create Ultrasonic sensor object
Servo head;

unsigned int time;            //Variable to store how long it takes for the ultrasonic wave to come back
int distance;                 //Variable to store the distance calculated from the sensor
int triggerDistance = 20;     //The distance we want the robot to look for a new path
int fDistance;                //Variable to store the distance in front of the robot
int lDistance;                //Variable to store the distance on the left side of the robot
int rDistance;                //Variable to store the distance on the right side of the robot

void setup() {
/* Removed
 * { 
  leftServo.attach(9);        //Left servo connected to pin 9
  leftServo.write(90);        //Write the neutral position to that servo
  rightServo.attach(8);       //Right servo connected to pin 8
  rightServo.write(90);       //Write the neutral position to that servo
} */
// Added Servo functionality
  head.attach(9);
  head.write(90);

// Added motor initialization  
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  
// Added motor initialization
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
}

void loop()
{
  scan();                                //Get the distance retrieved
  fDistance = distance;                  //Set that distance to the front distance
  if(fDistance < triggerDistance){       //If there is something closer than 30cm in front of us
    moveBackward();                      // motor Move Backward for a second
    delay(50); 
    moveStop();
    head.write(0);                       // Added Servo turn Right
    scan();
    delay(500);                          // Take a reading
    rDistance = distance;                // Store that to the distance on the right side
    head.write(180);                     // Added Servo Turn left
    scan(); 
    delay(500);                          // Take a reading
    lDistance = distance;                // Store that to the distance on the left side
    head.write(90);                      // Added return servo to 90 degree position
    if(lDistance < rDistance){           // If the distance on the left is smaller than that of the right
      moveRight();                       // Move right for a quarter of a second
      delay(250);
      moveForward();                     //Then move forward
    }
    else {
      moveLeft();                       // Added the motor Move left
      delay(250);
      moveForward();                     //If the left side is larger than the right side move forward
    }
  }
  else{
    moveForward();                       //If there is nothing infront of the robot move forward
  }
}

void scan(){
  time = sonar.ping();                  //Send out a ping and store the time it took for it to come back in the time variable
  distance = time / US_ROUNDTRIP_CM;    //Convert that time into a distance
  if(distance == 0){                    //If no ping was recieved
    distance = 100;                     //Set the distance to max
  }
  delay(10);
}

/* Removed
 * void moveBackward(){
  rightServo.write(180);
  leftServo.write(0); 
}*/

/*void moveForward(){
  rightServo.write(0);
  leftServo.write(180);
}*/

/*void moveRight(){
  rightServo.write(0);
  leftServo.write(0);  
}*/

/*void moveLeft(){
  rightServo.write(180);
  leftServo.write(180);
}*/

/*void moveStop(){
  rightServo.write(90);
  leftServo.write(95); 
}*/

// Added motors go forward
void moveForward(){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  }

// Added motors go backward
void moveBackward(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  }

// Added motors stop
void moveStop(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
  }

// Added motors left turn
void moveLeft(){ 
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  }

// Added motors right turn 
void moveRight(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  }


