#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include <IRremote.h>

int IR_PIN = 13;
IRrecv irrecv(IR_PIN);
decode_results results;

SoftwareSerial MP3Serial(10, 11); // RX, TX

int mp3vol = 10;

void setup() {
 Serial.begin (9600);
 MP3Serial.begin (9600);
 mp3_set_serial (MP3Serial); //set Serial for DFPlayer-mini mp3 module 
 mp3_set_volume (mp3vol);
 irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 0xFF6897) {
      while (digitalRead(8)==HIGH) {
        mp3_play(1);
        Serial.println("sending #1");
      }
    }
    if (results.value == 0xFF9867) {
      while (digitalRead(8)==HIGH) {
        mp3_play(2);
        Serial.println("sending #2");
      }
    }
    if (results.value == 0xFF629D) {
        mp3vol = mp3vol + 10;
        if (mp3vol>100) {
          mp3vol = 100;
        }
      while (digitalRead(8)==HIGH) {
         mp3_set_volume (mp3vol);
        mp3_play(4);
        Serial.print("sending vol up");
        Serial.println(mp3vol);
      }
    }
    if (results.value == 0xFFA857) {
        mp3vol = mp3vol - 10;
        if (mp3vol<0) {
          mp3vol = 0;
        }
      while (digitalRead(8)==HIGH) {

         mp3_set_volume (mp3vol);
         mp3_play(5);
        Serial.print("sending vol down");
        Serial.println(mp3vol);
      }
    }
    
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }

  
  delay(100);

  
}
