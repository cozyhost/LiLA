#include <SPI.h>
#include <TFT.h>

#define cs 10
#define dc 9
#define rst 8

TFT TFTscreen = TFT(cs, dc, rst);

char sensorPrintout[4];


void setup() {
  TFTscreen.begin();
  TFTscreen.background(0,0,0);
  TFTscreen.stroke(255,255,255);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Hello World", 0,0);
  TFTscreen.setTextSize(5);

}

void loop() {
  String sensorVal = String(analogRead(A0));
  sensorVal.toCharArray(sensorPrintout, 4);
  TFTscreen.stroke(255,255,255);
  TFTscreen.text(sensorPrintout, 0, 20);
  delay(250);
  TFTscreen.stroke(0,0,0);
  TFTscreen.text(sensorPrintout, 0, 20);


}
