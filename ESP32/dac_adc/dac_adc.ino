#include <Ticker.h>

#define Vo(x) x*256/3.3

double i;

void setup() {
  // put your setup code here, to run once:


  Serial2.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
  dacWrite(25,Vo(0.5));
  i=analogRead(13)*3.9/4096;
  Serial2.print(i);
  delay(3000);
  dacWrite(25,Vo(1));
  i=analogRead(13)*3.9/4096;
  Serial2.print(i);
  delay(3000);
  dacWrite(25,Vo(2.5));
  i=analogRead(13)*3.9/4096;
  Serial2.print(i);
  delay(3000);
}
