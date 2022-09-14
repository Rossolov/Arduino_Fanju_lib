#ifndef FANJU_H
#define FANJU_H

#include <Arduino.h>

// #define CC1101

// RINGBUFFER
#ifndef BUF_SIZE
  #define BUF_SIZE 128
#endif


class Fanju
{
private:
    //void push(uint8_t v);
    //uint16_t pop();
    int16_t fillLvl();
    #ifdef CC1101
        void setup_cc1101();
    #endif
    bool chkChkSum(uint8_t *data); 
    bool analyse(uint8_t *data);

public:
    Fanju(int RX_pin);
    void begin();
    uint8_t getHum();
    float getTemp();
    bool getBatOK();
    uint8_t getChannel();
    uint8_t getRollingCode();   //Rolling co
    bool getTxReq();
    bool read();  //return true if new data is ready
};


#endif