// Project 50 – Creating an IR Remote Control Arduino
int receiverpin = 11; // pin 1 of IR receiver to Arduino digital pin 11
#include <IRremote.h>
IRrecv irrecv(receiverpin); // create instance of irrecv
decode_results results;
void setup()
{
  irrecv.enableIRIn(); // start the receiver
  for (int z = 2 ; z < 8 ; z++) // set up digital pins
  {
    pinMode(z, OUTPUT);
  }
}
void pinOn(int pin) // turns on digital pin "pin" for 1 second
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
}
void translateIR()
// takes action based on IR code received
// uses Sony IR codes
{
  switch(results.value)
  {
  case 0xFD8877: 
    pinOn(2); 
    break; // 2
  case 0xFD48B7: 
    pinOn(3); 
    break; // 3
  case 0xFD28D7: 
    pinOn(4); 
    break; // 4
  case 0xFDA857: 
    pinOn(5); 
    break; // 5
  case 0xFD6897: 
    pinOn(6); 
    break; // 6
  case 0xFD18E7: 
    pinOn(7); 
    break; // 7
  }
}
void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR();
    for (int z = 0 ; 
    z < 2 ; 
    z++) // ignore the 2nd and 3rd repeated codes
    {
      irrecv.resume(); // receive the next value
    }
  }
}



/*
0 - FD30CF 
1 - FD08F7 
2 - FD8877 
3 - FD48B7 
4 - FD28D7 
5 - FDA857 
6 - FD6897 
7 - FD18E7 
8 - FD9867 
9 - FD58A7 
Power - FD00FF 
Mute/EQ - FDB04F 
vUp - FD807F 
vDown - FD906F 
cUp - FD50AF 
cDown - FD10EF
*/

