
#ifndef DEBUGTXT

  #ifndef NODEBUG
    #define DEBUGTXT(txt)                                    { Serial.println(txt); }
    #define DEBUGVAL(txt, val)                               { Serial.print(txt);  Serial.print("="); Serial.println(val); }
    #define DEBUGVAL2(txt, val, txt2, val2)                  { Serial.print(txt);  Serial.print("="); Serial.print(val); Serial.print(" "); Serial.print(txt2);  Serial.print("="); Serial.println(val2);}
    #define DEBUGVAL3(txt, val, txt2, val2, txt3, val3)      { Serial.print(txt);  Serial.print("="); Serial.print(val); Serial.print(" "); Serial.print(txt2);  Serial.print("="); Serial.print(val2); Serial.print(" "); Serial.print(txt3); Serial.print("="); Serial.println(val3);}
    #define DEBUGPLOT3(val1, val2, val3)                     { Serial.print(val1); Serial.print(","); Serial.print(val2);  Serial.print(","); Serial.println(val3);}
  #else
    #define DEBUGTXT(txt)                                    { }
    #define DEBUGVAL(txt, val)                               { }
    #define DEBUGVAL2(txt, val, txt2, val2)                  { }
    #define DEBUGVAL3(txt, val, txt2, val2, txt3, val3)      { }
    #define DEBUGPLOT3(val1, val2, val3)                     { }
  #endif
#endif