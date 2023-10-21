#include <stdint.h>
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
  //parameters that corresponds to the LCD
  //R/W is set to ground since this library does not read any register to the LCD
  Bonezegei_HD44780(int8_t rs, int8_t en, int8_t d4, int8_t d5, int8_t d6, int8_t d7);

  // initialize the Display
  void begin();

  //clock effect
  void latch();

  // set the last nibble to the Data pins
  void write4Bit(uint8_t data);

  // set 8 bit
  void writeByte(uint8_t data);

  void writeCommand4(uint8_t data);
  void writeCommand(uint8_t data);
  void writeData(uint8_t data);


  void setCursor(uint8_t x, uint8_t y);


  //pin Values in private
private:
  int8_t _rs;
  int8_t _en;
  int8_t _d4;
  int8_t _d5;
  int8_t _d6;
  int8_t _d7;
};

#endif
