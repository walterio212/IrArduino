#include "IRLibSendBase.h"
#include "IRLib_P01_NEC.h"
IRsendNEC mySender;

int input;
void setup() {  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    input = Serial.read();

    if(input == '1'){//Apagar 
      for(int i = 0; i< 7; i++){ 
        mySender.send(0xC53A9966, 40);
        mySender.send(0xF50A05FA, 40);
        delay(40);
      }
    }
    if(input == '2'){//Play
      for(int i = 0; i< 6; i++){
        mySender.send(0xC53A7986, 40);
        delay(40);
      }
    }
    if(input == '3'){//Stop
      for(int i = 0; i< 6; i++){
        mySender.send(0xC53A19E6, 40);
        delay(40);
      }
    }
    if(input == '4'){//Pause
      mySender.send(0xC53AF906, 40);      
    }
  }  
}
