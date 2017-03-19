#include "IRLibSendBase.h"
#include "IRLib_P03_RC5.h"
IRsendRC5 mySender;

int input;
void setup() {  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    input = Serial.read();

    if(input == '1'){//Apagar 
      for(int i = 0; i< 7; i++){
        mySender.send(0x100C, 13);
        delay(40);
      }
    }
    if(input == '2'){//Prender Ch Up
      for(int i = 0; i< 6; i++){
        mySender.send(0x1020, 13);
        delay(40);
      }
    }
    if(input == '3'){//Ch Down
      for(int i = 0; i< 6; i++){
        mySender.send(0x1021, 13);
        delay(40);
      }
    }
    if(input == '4'){//Vol Up
      mySender.send(0x1010, 13);      
    }
    if(input == '5'){//Vol Down
      mySender.send(0x1011, 13);      
    }
  }  
}
