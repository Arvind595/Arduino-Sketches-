#include "HT1621Translator.h"
#include <HT1621.h>
Translator::Translator(bool displayMsg) {
  // Anything you need when instantiating your object goes here
 
}




// Pretend this is one or more complex and involved functions you have written
long Translator::getRandomNumber() {
write(2,0);
  unsigned long specialNumber = random(5, 1000);

  specialNumber *= getPi();

  specialNumber -= 5;

  return specialNumber;

}

// Private method for this class
float Translator::getPi() {
  return 3.1415926;
}
