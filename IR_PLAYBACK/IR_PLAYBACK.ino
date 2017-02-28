#include <elapsedMillis.h>
#include "IR_Commands.h"

#define IR_PIN 3

elapsedMicros elapsedTime;

void setup() {
 Serial.begin(115200);
 delay(500);
 pinMode(IR_PIN,OUTPUT);  
 digitalWrite(IR_PIN,HIGH);
 Serial.println("Starting");
}

void loop() {
  if (Serial.available()){
    char incomingLetter = Serial.read();
    pressButton(incomingLetter);
    digitalWrite(IR_PIN, HIGH);
  }
  delay(100);
}

void pressButton(char c) {
  bool* buttonCmd;
  int len;
  if(c=='p'){
    buttonCmd = button1Cmd; 
    len = sizeof(button1Cmd);
  }
  else if(c=='u'){
    buttonCmd = button2Cmd;
    len = sizeof(button2Cmd); 
  }
  else if(c=='s'){
    buttonCmd = button3Cmd; 
    len = sizeof(button3Cmd);
  }
  else if(c=='l'){
    buttonCmd = button4Cmd; 
    len = sizeof(button4Cmd);
  } 
  else if(c=='m'){
    buttonCmd = button5Cmd; 
    len = sizeof(button5Cmd);
  }
  else if(c=='r'){
    buttonCmd = button6Cmd; 
    len = sizeof(button6Cmd);
  } 
  else if(c=='0'){
    buttonCmd = button7Cmd; 
    len = sizeof(button7Cmd);
  } 
  else if(c=='d'){
    buttonCmd = button8Cmd; 
    len = sizeof(button8Cmd);
  }   
  else if(c=='b'){
    buttonCmd = button9Cmd; 
    len = sizeof(button9Cmd);
  } 
  else if(c=='1'){
    buttonCmd = button10Cmd; 
    len = sizeof(button10Cmd);
  }
  else if(c=='2'){
    buttonCmd = button11Cmd; 
    len = sizeof(button11Cmd);
  }  
  else if(c=='3'){
    buttonCmd = button12Cmd; 
    len = sizeof(button12Cmd);
  } 
  else if(c=='4'){
    buttonCmd = button13Cmd; 
    len = sizeof(button13Cmd);
  } 
  else if(c=='5'){
    buttonCmd = button14Cmd; 
    len = sizeof(button14Cmd);
  } 
  else if(c=='6'){
    buttonCmd = button15Cmd; 
    len = sizeof(button15Cmd);
  } 
  else if(c=='7'){
    buttonCmd = button16Cmd; 
    len = sizeof(button16Cmd);
  } 
  else if(c=='8'){
    buttonCmd = button17Cmd; 
    len = sizeof(button17Cmd);
  } 
  else if(c=='9'){
    buttonCmd = button18Cmd; 
    len = sizeof(button18Cmd);
  }
  for(int i=0; i<len; i++){   
    elapsedTime=0;
    if(buttonCmd[i]){
      digitalWrite(IR_PIN,HIGH);
     Serial.println(1);
    }
     else{
      digitalWrite(IR_PIN,LOW);
     Serial.println(0);
    }
    while (elapsedTime<200);

  } 
}
