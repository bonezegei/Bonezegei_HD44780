/*
  This Library is written for HD44780 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: October 2023 
*/
#include "Bonezegei_HD44780.h"

Bonezegei_HD44780::Bonezegei_HD44780(int8_t rs, int8_t en, int8_t d4, int8_t d5, int8_t d6, int8_t d7){
  _rs=rs;
  _en=en;
  _d4=d4;
  _d5=d5;
  _d6=d6;
  _d7=d7;
}

Bonezegei_HD44780::begin(){
  pinMode(_rs, OUTPUT);
  pinMode(_en, OUTPUT);
  pinMode(_d4, OUTPUT);
  pinMode(_d5, OUTPUT);
  pinMode(_d6, OUTPUT);
  pinMode(_d7, OUTPUT);
}
