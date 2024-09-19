
#define SPEED_THRESHOLD   40
#define SPEED_MULTIPLIER   3
#define BORDER_AREA 20
#define BORDER_PUSH_SPEED 5
#define MOUSE_MOVE_MAX 127/// 127 is maximum due to mouse driver
#define SLOW_MOVE_FILTER_THRESHOLD 5.0 // above a certain mouse speed, filter is lowered
#define FILTER_POWER_LOW  0.7
#define FILTER_POWER_HIGH 0.1

class PotFilter
{
  float stableValue = 500.0;
  int pin_;
  int xRaw_         = 0;
  int xRawOld_      = 0;
  int rawDelta_     = 0;
  float filteredDelta_ = 0;
  float x_          = 0;
  float xOld_       = 0;
  float missedMove_ = 0;
  float sensitivity_= 1.0;

  public:
  PotFilter(int pin)
  {
    pin_=pin;
  }

  float getX()
  {
    return x_;
  }

  int getRawDeltaX()
  {
    return rawDelta_;
  }

  float getfilteredDeltaX()
  {
    return filteredDelta_;
  }

  void setSensitivity(float s)
  {
    sensitivity_ = s;
  }


  int readDeltaInteger()
  {
    xRaw_ = analogRead(pin_);
    rawDelta_ = xRaw_-xRawOld_;

    x_ = filterValue_( (float) xRaw_) ;
    //DEBUGVAL2("xraw_", xRaw_, "x", x_);
    
    float delta = x_ - xOld_ ;
    filteredDelta_ = delta;

    // define minimum movement value in case of hitting border of linear potentiometer
    if(x_ <= BORDER_AREA)        delta = -BORDER_PUSH_SPEED;
    if(x_ >= (1023-BORDER_AREA)) delta = BORDER_PUSH_SPEED;
    
    if( abs(delta) >= SPEED_THRESHOLD && abs(delta) <= 100 )
    {
        delta *= SPEED_MULTIPLIER;
        DEBUGVAL("Accelerating", delta)
    }

    delta *= sensitivity_;
    delta += missedMove_;
    missedMove_=0;

    // makes pot values compatible with the physical limits for the mouse function
    if(delta >= MOUSE_MOVE_MAX)
      {
        missedMove_ = delta - MOUSE_MOVE_MAX;
        delta = MOUSE_MOVE_MAX;
      }
    if(delta <= -MOUSE_MOVE_MAX) 
      {
        missedMove_ = delta + MOUSE_MOVE_MAX;
        delta = -MOUSE_MOVE_MAX;
      }

    int deltaRounded = round( delta );
    float roundDiff = delta-deltaRounded;

    missedMove_ += roundDiff;

    if (abs(missedMove_) > 1.0)
      DEBUGVAL("missedMove_ (compensating now)", missedMove_)

    xOld_    = x_;
    xRawOld_ = xRaw_;
    return deltaRounded;
  }

private:
  float filterValue_(float value)
  {
    float gapHeight = abs(value - stableValue);
    float filter;
    if (gapHeight > SLOW_MOVE_FILTER_THRESHOLD ) 
      filter = FILTER_POWER_LOW;
    else 
      filter = FILTER_POWER_HIGH;

    float v = ( filter * value + (1.0 - filter) * stableValue);
    stableValue = v;
    return v;
  }


  float mapfloat_(float x, float in_min, float in_max, float out_min, float out_max)
  {
    return  (x - in_min) * (out_max - out_min) / (float) (in_max - in_min) + out_min ;
  }
};