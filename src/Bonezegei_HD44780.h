/*
  This Library is written for HD44780 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: October 2023 
*/
#ifndef _BONEZEGEI_HD44780_H_
#define _BONEZEGEI_HD44780_H_
#include <Arduino.h>

class Bonezegei_HD44780 {
public:

  Bonezegei_HD44780(int8_t rs, int8_t en, int8_t d4, int8_t d5, int8_t d6, int8_t d7);

  void begin();


private:
  int8_t _rs;
  int8_t _en;
  int8_t _d4;
  int8_t _d5;
  int8_t _d6;
  int8_t _d7;
};


#endif
