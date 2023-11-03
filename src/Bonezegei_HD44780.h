#include <stdint.h>
/*
  This Library is written for HD44780 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: October 2023 
*/
#ifndef _BONEZEGEI_HD44780_H_
#define _BONEZEGEI_HD44780_H_
#include <Arduino.h>

#define HD44780_8BIT 0
#define HD44780_4BIT 1

class Bonezegei_HD44780 {
public:
  //parameters that corresponds to the LCD
  //R/W is set to ground since this library does not read any register to the LCD
  Bonezegei_HD44780(int8_t rs, int8_t en, int8_t d4, int8_t d5, int8_t d6, int8_t d7);
  Bonezegei_HD44780(int8_t rs, int8_t en, int8_t d0, int8_t d1, int8_t d2, int8_t d3, int8_t d4, int8_t d5, int8_t d6, int8_t d7);

  // initialize the Display
  void begin();

  //clock effect
  void latch();

  // set the last nibble to the Data pins
  void write4Bit(uint8_t data);
  // set the whole byte to the Data pins
  void write8Bit(uint8_t data);

  // set 8 bit
  void writeByte(uint8_t data);

  void writeCommand4(uint8_t data);
  void writeCommand(uint8_t data);
  void writeData(uint8_t data);

  void setPosition(uint8_t x, uint8_t y);
  void print(char *str);

  int8_t mode;
  //pin Values in private
private:
  int8_t _rs;
  int8_t _en;
  int8_t _d0;
  int8_t _d1;
  int8_t _d2;
  int8_t _d3;
  int8_t _d4;
  int8_t _d5;
  int8_t _d6;
  int8_t _d7;
};

#endif
