/* The following code will make the robot move forward for 4 seconds,
 *  stop for 1 second, turn left for 0.4 second, stop for 1 second, turn
 *  right for 0.4 second, stop for one second, go backward for 2 seconds,
 *  stop for 1 second, stop for one second, and repeat.
 */

//pins for right motor
const int MotorR1 = 6; //forward
const int MotorR2 = 7; // backward

//pins for left motor
const int MotorL1 = 4; // forward
const int MotorL2 = 5; // backward

void setup() {
  // put your setup code here, to run once:
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);


  //variable initialization
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  //go forward
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  delay(4000);

  //stop
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  delay(1000);

  //turn left
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  delay(400);

  //stop
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  delay(1000);

  //turn right
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  delay(400);

  //stop
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  delay(1000);

  //go backwards
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  delay(2000);

  //stop
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  delay(1000);
  
}
