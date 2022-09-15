# Arduino_Fanju_lib

This arduino library used for cheap chineese FanJu sensors. 
Library based on https://github.com/adaasch/fanju_decoder_arduino_pi.

Main feature is software filter for spikes rf noise. This is significally inreased distance to sensor.

Tested with 433MHz receiver MX-RF-5V and SYN480, has to work with any other. Connect Data pin from receiver to an interrupt pin (ATMega328p - pin D2 or D3). 
For indetifying of the sensor use Rolling Code. But be careful - code will be changed on ever sensor battery disconnecting. 

Library tested with Arduino Nano ATMega328 and NodeMCU ESP8266.
![image](https://user-images.githubusercontent.com/41646850/190326634-0205444f-2e84-4cf0-981e-eafb2799a326.png)
