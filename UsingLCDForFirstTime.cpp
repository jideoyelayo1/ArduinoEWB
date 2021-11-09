/* Below I have attached example code on how to use the LCD */
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2); // we are having a 16 across and 2 down LCD

}

void loop() {
    lcd.setCursor(0,0); // start writing from 0,0
    lcd.print("First line");// writes where the cursor is
    lcd.setCursor(0,1); // start writing from 0,1
    lcd.print("Second line");// writes where the cursor is
    delay(1000); // waits one second
}
