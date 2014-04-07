//  Cylon eye code for A'blinkin. To be factored into a lib.
//  Julien Eid
//  Josh McSavaney

int dataPin = P1_0;        //Define which pins will be used for the Shift Register control
int latchPin = P1_4;
int clockPin = P1_5;

int byte1 = 0;         //The counter for storing the byte #1 value
int byte2 = 0;         //The counter for storing the byte #2 value
int val = 0;

void setup()
{
  pinMode(dataPin, OUTPUT);       //Configure each IO Pin
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  digitalWrite(latchPin, LOW);
  delay(250);
  shiftOut(dataPin, clockPin, MSBFIRST, 0xff);
  shiftOut(dataPin, clockPin, MSBFIRST, 0xff);
  shiftOut(dataPin, clockPin, MSBFIRST, 0xff);
  digitalWrite(latchPin, HIGH);
  for (;;)
  {
    for ( int h = 0; h < 12; h++ )
    {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, 0);
      digitalWrite(latchPin, HIGH);
      delay(200);
    }
    for ( int i=0; i <= 13 ; i++ )
    {
      digitalWrite(latchPin, LOW);

      for ( int k = 0; k < i-1; k++ )
      {
        shiftOut(dataPin, clockPin, MSBFIRST, 0);
      }
      shiftOut(dataPin, clockPin, MSBFIRST, 0xff);
      shiftOut(dataPin, clockPin, MSBFIRST, 0xff);
      shiftOut(dataPin, clockPin, MSBFIRST, 0xff);
      for ( int j = 13; j > i; j-- )
      {
        shiftOut(dataPin, clockPin, MSBFIRST, 0);
      }

      digitalWrite(latchPin, HIGH);
      delay(200);
    }
  }
}
