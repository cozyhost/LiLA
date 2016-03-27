#include <RH_ASK.h> // This library was inside the RadioHead Library
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
int inputPin = 2; 
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;  

void setup()
{
    pinMode(inputPin, INPUT);  
    
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    val = digitalRead(inputPin);

    if (val == HIGH) { 

      if (pirState == LOW) {
       pirState = HIGH;

      const char *msg = "pirState HIGH";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(5000);
    pirState = LOW;
    delay(1000);
      
    } //else {
    
      //if (pirState == HIGH){
      // we have just turned of
      //Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      //pirState = LOW; 

      //const char *msg = "pirState LOW - No Motion";
    //driver.send((uint8_t *)msg, strlen(msg));
    //driver.waitPacketSent();
    //delay(1000);
      
   // }   
    }
    }
//    }
    
