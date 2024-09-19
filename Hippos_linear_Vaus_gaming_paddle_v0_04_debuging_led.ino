/* Linear game paddle to play Arkanoid
by Hippolyte Mounier
2024-01-05

*/
#define VERSION "Hippo Vaus Paddle v0.04"

#include "myleds.h"

#include <ezButton.h>
#include "Mouse.h"
#include "debug.h"
#include "PotFilter.h"

#define BUTTON_FIRE_PIN    2
#define X_POT_PIN         A0
#define SENSITIVITY_PIN   A1

#define DELAY_LIGHT_SHOW 10000 // 10 s
#define SENSITIVITY_LIGHT_SHOW 10
#define MOUSE_UPDATE_MILISECOND 5 // total 15 ms per loop = 66 Hz

PotFilter pot(X_POT_PIN);

ezButton ezbutton(BUTTON_FIRE_PIN);  // create ezButton object that attach to pin 4

long   lastmove       = 0;
float  sensitivity    = 1.0;
int    potValue2Last  = 0;

void setup() {
  Serial.begin(9600);
  DEBUGTXT(VERSION);

  Mouse.begin();
  ezbutton.setDebounceTime(50);  // set debounce time to 50 milliseconds

  ledinit();
  flash();
}

long loopTime=0;
int counter = 0;

void loop() 
{

  ezbutton.loop();  // MUST call the loop() function first
  if (ezbutton.isPressed())
  {
    Mouse.press(MOUSE_LEFT);
    DEBUGTXT("button pressed")
    fire();
    lastmove = millis();
  }

  if (ezbutton.isReleased())
  {
    Mouse.release(MOUSE_LEFT);
    DEBUGTXT("button released")
  }
  /*
  long time = millis();
  int deltaT = time-loopTime;
  loopTime = time;
  DEBUGVAL("delta time", deltaT)*/

  int mousex = pot.readDeltaInteger();
  
  Mouse.move(mousex , 0, 0);
  
  if (abs(mousex >= SENSITIVITY_LIGHT_SHOW)) 
  {
    DEBUGVAL2("Moving mousex", mousex, "rawDeltaX", pot.getRawDeltaX());
    lastmove = millis();
  }
  else
    DEBUGVAL2("       mousex", mousex, "rawDeltaX", pot.getRawDeltaX());


  if(millis() - lastmove > DELAY_LIGHT_SHOW) // 10 s
    ledloop();
  else
    ledPaddle(pot.getX());

  if (counter ++ > 20)
   {
    counter = 0;
    int potValue2 = analogRead(SENSITIVITY_PIN);
    sensitivity =  mapfloat(potValue2, 0, 1023, 0.3, 3)  ;
    if (abs(potValue2 - potValue2Last) > 10)
      DEBUGVAL("sensitivity", sensitivity);
    pot.setSensitivity(sensitivity);

    potValue2Last = potValue2;
  }

  delay(MOUSE_UPDATE_MILISECOND);

}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return  (x - in_min) * (out_max - out_min) / (float) (in_max - in_min) + out_min ;
}

