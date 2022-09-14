/*  
 *   Example how to use rolling code
 *   The rolling code is changing on every removing batteris from sensor  
 *   Author - Dmitriy Rossolov
 *   https://github.com/Rossolov/Arduino_Fanju_lib
 * 
 */

#include <Arduino.h>
#include "fanju.h"

#define DATA_PIN  2     

Fanju myFanju(DATA_PIN);
uint8_t channel, rollingCode;
bool sensorPaired = false;


void setup() {
  Serial.begin(115200);
  Serial.println("Read from Fanju sensor. Press TX button on temperature sensor");
  myFanju.begin();
}

void loop() {
  if(myFanju.read()){
    if(!sensorPaired){
        if(myFanju.getTxReq()){  //Check if TX button was pressed
          sensorPaired = true;
          rollingCode = myFanju.getRollingCode();
          channel = myFanju.getChannel();
          Serial.print("Sensor paired. Rolling code - 0x");
          Serial.print(rollingCode);
          Serial.print(", channel - ");
          Serial.println(channel);
        }
    }
    else if(myFanju.getRollingCode() == rollingCode && myFanju.getChannel() == channel){
      Serial.print("Temperature - ");
      Serial.print(myFanju.getTemp(), 1);
      Serial.print("C, Humidity - ");
      Serial.print(myFanju.getHum());      
      Serial.print(", Battery - ");
      if(myFanju.getBatOK()) Serial.print("OK");
      else Serial.print("Low");
      Serial.println();
    }    
  }  
}
