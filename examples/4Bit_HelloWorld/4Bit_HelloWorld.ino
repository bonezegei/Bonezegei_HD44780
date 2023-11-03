/*
  4-bit mode Hello World Example
  Author: Bonezegei (Jofel Batutay)
  Date: November 2023
*/

#include <Bonezegei_HD44780.h>

/*
  param1 = RS
  param2 = EN
  param3 = D4
  param3 = D5
  param3 = D6
  param3 = D7
*/
Bonezegei_HD44780 lcd(9, 8, 4, 5, 6, 7);

void setup() {
  lcd.begin();
  lcd.print("Bonezegei");
  lcd.setPosition(0, 1);      //param1 = X   param2 = Y
  lcd.print("HD44780");
  delay(2000);
  lcd.setPosition(0, 0);
  lcd.print("Hello World");
}

void loop() {
  lcd.setPosition(0, 1);
  String str = "ms:";
  str += millis();
  lcd.print(str.c_str());
  delay(100);
}
