//  A'blinkin
//  Julien Eid
//  Josh McSavaney
 
#include "letters.c"

int dataPin = P1_0;        //Define which pins will be used for the Shift Register control
int latchPin = P1_4;
int clockPin = P1_5;

int byte1 = 0;         //The counter for storing the byte #1 value
int byte2 = 0;         //The counter for storing the byte #2 value
int val = 0;

int incomingByte = 0;   // for incoming serial data

void setup()
{
  pinMode(dataPin, OUTPUT);       //Configure each IO Pin
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
   char eye [] = "/\\";
   for( byte2 = 1; byte2 >= 0; byte2--)
       for (byte1 = 3; byte1 >= 0; byte1--)
       {
           digitalWrite(latchPin, LOW);           //Pull latch LOW to start sending data
           shiftOut(dataPin, clockPin, LSBFIRST, get_char_section(eye[byte2], byte1)<<2); //Send the data byte 1
           digitalWrite(latchPin, HIGH);          //Pull latch HIGH to stop sending data
           delay(100);
       }
}
