/*

PINOUT

DISPLAY
1   GND
2   5v
3   NC
4   12
5   GND
6   11
7   NC
8   NC
9   NC
10  NC
11  5
12  4
13  3
14  2
15  NC
16  NC

SWITCHES
1
2
3 R1 - GND
4
5 C3 - 8
6 C2 - 7
7 C1 - 6
8
9

*/


#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buttonLeft = 6, buttonMiddle = 7, buttonRight = 8;

void setup() {
  // Set button inputs
  pinMode(buttonLeft, INPUT_PULLUP);
  pinMode(buttonMiddle, INPUT_PULLUP);
  pinMode(buttonRight, INPUT_PULLUP);
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // restart the display which appears to make it behave itself!
  lcd.noDisplay();
  delay(500);
  lcd.display();
}

void loop() {
  // Read button inputs
  int buttonValLeft = digitalRead(buttonLeft);
  int buttonValMiddle = digitalRead(buttonMiddle);
  int buttonValRight = digitalRead(buttonRight);

  // Output uptime in ms on line 1
  lcd.setCursor(0, 0);
  lcd.print("Uptime: ");
  lcd.setCursor(8, 0);
  lcd.print(millis());

  // Output left button state on line 2
  lcd.setCursor(0, 1);
  if (buttonValLeft == LOW) {
    lcd.print("Left: On ");
  } else {
    lcd.print("Left: Off");
  }

  // Output middle button state on line 3
  lcd.setCursor(0, 2);
  if (buttonValMiddle == LOW) {
    lcd.print("Middle: On ");
  } else {
    lcd.print("Middle: Off");
  }

  // Output right button state on line 4
  lcd.setCursor(0, 3);
  if (buttonValRight == LOW) {
    lcd.print("Right: On ");
  } else {
    lcd.print("Right: Off");
  }
}
