/*
  This Library is written for HD44780 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: October 2023 
*/
#include "Bonezegei_HD44780.h"

Bonezegei_HD44780::Bonezegei_HD44780(int8_t rs, int8_t en, int8_t d4, int8_t d5, int8_t d6, int8_t d7) {
  _rs = rs;
  _en = en;
  _d4 = d4;
  _d5 = d5;
  _d6 = d6;
  _d7 = d7;
}

void Bonezegei_HD44780::begin() {
  pinMode(_rs, OUTPUT);
  pinMode(_en, OUTPUT);
  pinMode(_d4, OUTPUT);
  pinMode(_d5, OUTPUT);
  pinMode(_d6, OUTPUT);
  pinMode(_d7, OUTPUT);
  delayMicroseconds(50000);

  digitalWrite(_rs, LOW);
  digitalWrite(_en, LOW);

  write4Bit(0x03);
  delayMicroseconds(4500);  // wait min 4.1ms

  // second try
  write4Bit(0x03);
  delayMicroseconds(4500);  // wait min 4.1ms

  // third go!
  write4Bit(0x03);
  delayMicroseconds(150);

  // finally, set to 4-bit interface
  write4Bit(0x02);

  writeByte(0x2C);  //set Display 2 line 5x20 dots
  writeByte(0x08);
  writeByte(0x01);
  writeByte(0x07);

  writeByte(0x0F);

  writeData('A');
  writeData('A');
  writeData('A');


}

void Bonezegei_HD44780::latch() {
  digitalWrite(_en, LOW);
  delayMicroseconds(1);
  digitalWrite(_en, HIGH);
  delayMicroseconds(1);
  digitalWrite(_en, LOW);
  delayMicroseconds(100);
}

void Bonezegei_HD44780::write4Bit(uint8_t data) {
  if (data & 0x1) {
    digitalWrite(_d4, HIGH);
  } else {
    digitalWrite(_d4, LOW);
  }

  if (data & 0x2) {
    digitalWrite(_d5, HIGH);
  } else {
    digitalWrite(_d5, LOW);
  }

  if (data & 0x4) {
    digitalWrite(_d6, HIGH);
  } else {
    digitalWrite(_d6, LOW);
  }

  if (data & 0x8) {
    digitalWrite(_d7, HIGH);
  } else {
    digitalWrite(_d7, LOW);
  }

  latch();
}



void Bonezegei_HD44780::writeByte(uint8_t data) {
  write4Bit(data >> 4);
  write4Bit(data);
}

void Bonezegei_HD44780::writeCommand4(uint8_t data) {
  digitalWrite(_rs, LOW);
  write4Bit(data);
}

void Bonezegei_HD44780::writeCommand(uint8_t data) {
  digitalWrite(_rs, LOW);
  writeByte(data);
}
void Bonezegei_HD44780::writeData(uint8_t data) {
  digitalWrite(_rs, HIGH);
  writeByte(data);
}
