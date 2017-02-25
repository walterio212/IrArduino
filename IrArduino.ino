#include "IRLibSendBase.h"
#include "IRLib_P02_Sony.h"
IRsendSony mySender;

void setup() {  
}

void loop() {
  for(int i = 0; i< 3; i++){
    mySender.send(0xa8bca, 20);
    delay(40);
  }
  delay(3000);
}
