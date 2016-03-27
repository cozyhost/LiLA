#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

int ledPin2 = 7;                // EA led bulb on breadboard
int piezo = 8;                  // EA piezo on pin 8
int pitch = 1047;               // EA middle C

void setup()
{
  pinMode(ledPin2, OUTPUT);
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed"); 
}

void loop()
{
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.

      Serial.print("Message: ");
      Serial.println((char*)buf);
      digitalWrite(ledPin2, HIGH);
      tone(piezo, pitch, 2000);
      delay(8000); 
      digitalWrite(ledPin2, LOW);  
            
    }
}
