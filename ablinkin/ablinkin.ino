//  A'blinkin
//  Julien Eid
//  Josh McSavaney
 
#include "letters.c"

int dataPin = P1_0;        //Define which pins will be used for the Shift Register control
int latchPin = P1_4;
int clockPin = P1_5;

int byte1 = 0;         //The counter for storing the byte #1 value
int byte2 = 0;         //The counter for storing the byte #2 value

char inChar;

void setup()
{
  pinMode(dataPin, OUTPUT);       //Configure each IO Pin
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(4800);
}

void loop()
{
   while(Serial.available() > 0)
   {
     Serial.write("before read");
     inChar = Serial.read(); // Read a character
     Serial.write("after read");
     //char eye [] = "/\\";
   //for( byte2 = 1; byte2 >= 0; byte2--)
       for (byte1 = 3; byte1 >= 0; byte1--)
       {
           digitalWrite(latchPin, LOW);           //Pull latch LOW to start sending data
           shiftOut(dataPin, clockPin, LSBFIRST, get_char_section(inChar, byte1)<<2); //Send the data byte 1
           digitalWrite(latchPin, HIGH);          //Pull latch HIGH to stop sending data
           delay(300);
       }
   }
}
