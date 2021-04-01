#ifndef HT1621Translator_H
#define HT1621Translator_H

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Translator  {
  public:
    // Constructor 
    Translator(bool displayMsg=false);

    // Methods
    
    long getRandomNumber();

  private:
    bool _msg;
    float getPi();
};
#endif
