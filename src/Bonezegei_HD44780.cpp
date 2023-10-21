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
  mode = HD44780_4BIT;
}

Bonezegei_HD44780::Bonezegei_HD44780(int8_t rs, int8_t en, int8_t d0, int8_t d1, int8_t d2, int8_t d3, int8_t d4, int8_t d5, int8_t d6, int8_t d7) {
  _rs = rs;
  _en = en;
  _d0 = d0;
  _d1 = d1;
  _d2 = d2;
  _d3 = d3;
  _d4 = d4;
  _d5 = d5;
  _d6 = d6;
  _d7 = d7;
  mode = HD44780_8BIT;
}

void Bonezegei_HD44780::begin() {
  pinMode(_rs, OUTPUT);
  pinMode(_en, OUTPUT);
  pinMode(_d4, OUTPUT);
  pinMode(_d5, OUTPUT);
  pinMode(_d6, OUTPUT);
  pinMode(_d7, OUTPUT);
  delay(50);
  digitalWrite(_rs, LOW);
  digitalWrite(_en, LOW);

  if (mode == HD44780_8BIT) {
    pinMode(_d0, OUTPUT);
    pinMode(_d1, OUTPUT);
    pinMode(_d2, OUTPUT);
    pinMode(_d3, OUTPUT);
    write8Bit(0x30);
    delay(5);
    write8Bit(0x30);
    delayMicroseconds(150);
    write8Bit(0x30);
    write8Bit(0x3C);
    write8Bit(0x08);
    write8Bit(0x01);
    write8Bit(0x07);
    write8Bit(0x0F);
    writeData('A');
  } else {

    write4Bit(0x03);
    delayMicroseconds(4500);
    write4Bit(0x03);
    delayMicroseconds(4500);
    write4Bit(0x03);
    delayMicroseconds(150);
    write4Bit(0x02);

    write4Bit(0x02);
    write4Bit(0x0C);
    write4Bit(0x00);
    write4Bit(0x08);
    write4Bit(0x00);
    write4Bit(0x01);
    write4Bit(0x00);
    write4Bit(0x06);

    write4Bit(0x00);
    write4Bit(0x0F);
  }
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

void Bonezegei_HD44780::write8Bit(uint8_t data) {
  if (data & 0x1) {
    digitalWrite(_d0, HIGH);
  } else {
    digitalWrite(_d0, LOW);
  }

  if (data & 0x2) {
    digitalWrite(_d1, HIGH);
  } else {
    digitalWrite(_d1, LOW);
  }

  if (data & 0x4) {
    digitalWrite(_d2, HIGH);
  } else {
    digitalWrite(_d2, LOW);
  }

  if (data & 0x8) {
    digitalWrite(_d3, HIGH);
  } else {
    digitalWrite(_d3, LOW);
  }
  if (data & 0x10) {
    digitalWrite(_d4, HIGH);
  } else {
    digitalWrite(_d4, LOW);
  }

  if (data & 0x20) {
    digitalWrite(_d5, HIGH);
  } else {
    digitalWrite(_d5, LOW);
  }

  if (data & 0x40) {
    digitalWrite(_d6, HIGH);
  } else {
    digitalWrite(_d6, LOW);
  }

  if (data & 0x80) {
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
  if (mode == HD44780_4BIT) {
    writeByte(data);
  } else {
    write8Bit(data);
  }
}
void Bonezegei_HD44780::writeData(uint8_t data) {
  digitalWrite(_rs, HIGH);
  if (mode == HD44780_4BIT) {
    writeByte(data);
  } else {
    write8Bit(data);
  }
}
