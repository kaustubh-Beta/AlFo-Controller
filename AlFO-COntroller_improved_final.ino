/* this is the code for AlFo-Controller A mini project using arduino 
 created by Kaustubh sadekar 
 Date : 20 october 2015
 the basic function of the code is to create a bridge between alfo controller(a gaming device) and the gaming host system.
 alfo controler takes basically two saperate types of inputs , 
(i) Moves for locomotion 
(ii) Moves for special functions like nitor in NFS MW .....
*/

#include <Keyboard.h>

const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis of the accelerometer

// Defining GPIO pins corresponding to the function keys.
// Attach your push buttons / aluminium foil based sensors to these pins. 
int fn1 = 6, fn2 = 5, fn3 = 4, fn4 = 3; 

// Initializing variables 
int i=0, j=0; 

// Assigning custom control string 
// NOTE :  The perticular letter key will be pressed and released.
const char fn1_str = 'n';
const char fn2_str = 'm';
const char fn3_str = 'x';
const char fn4_str = 'z';
const char loco_move1 = 'w';
const char loco_move2 = 's';
const char loco_move3 = 'a';
const char loco_move4 = 'd';


void setup()
{
  
  // setting the pinmode for the GPIO pins

  pinMode(fn1,INPUT);
  pinMode(fn2,INPUT);
  pinMode(fn3,INPUT);
  pinMode(fn4,INPUT);

  // Pinmode for analog sensors 
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);

  // Pin 13 is for visual signals 
  pinMode(13,OUTPUT);
  
  Serial.begin(9600);
  Keyboard.begin();
  
}


//Function that provides some delay to read the pin status. (Not an apt debounce function)
// the delay is used to simply avoid the ambigious status of the input pin state during debounce period 

boolean deb(int pin)
{ 
  digitalRead(pin);
  delay(50);
  return (digitalRead(pin));
}  


// This part of code runs forever in a loop.  
void loop()
{ 

digitalWrite(13,HIGH);

// For special function keys

  if(deb(fn1) == HIGH )
  {
    Keyboard.press(fn1_str);
  }
  else if(deb(fn1) == LOW) 
  {
    Keyboard.release(fn1_str);
  }


  if(deb(fn2) == HIGH )
  {
    Keyboard.press(fn2_str);
  }
  else if(deb(fn2) == LOW) 
  {
    Keyboard.release(fn2_str);
  }


  if(deb(fn3) == HIGH )
  {
    Keyboard.press(fn3_str);
  }
  else if(deb(fn3) == LOW) 
  {
    Keyboard.release(fn3_str);
  }


  if(deb(fn4) == HIGH )
  {
    Keyboard.press(fn4_str);
  }
  else if(deb(fn4) == LOW) 
  {
    Keyboard.release(fn4_str);
  }

  //.......................................................................
  // Creating the gaming locomotion controsl 
  // We use an accelerometer for alfocontoller
 
 // controling forward and back locomotion
 if (analogRead(xpin) < 310 )
 {
   Keyboard.press(loco_move1);
 }
 else if(analogRead(xpin) > 380 )
 {
   Keyboard.press(loco_move2);
 }
else if(analogRead(xpin) < 380 && analogRead(xpin) > 310 )
 {
   Keyboard.release(loco_move1);
   Keyboard.release(loco_move2);
 }
 

 // controling the right and left locomotion 
  if (analogRead(ypin) < 310 )
 {
   Keyboard.press(loco_move3);
 }
 else if(analogRead(ypin) > 380 )
 {
   Keyboard.press(loco_move4);
 }
else if(analogRead(ypin) < 380 && analogRead(ypin) > 310 )
 {
   Keyboard.release(loco_move3);
   Keyboard.release(loco_move4);
 }
 
 // end of loop
}
