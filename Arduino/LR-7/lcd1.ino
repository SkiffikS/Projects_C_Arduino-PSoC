#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  lcd.begin(16, 2);
  
  lcd.print("text1");
  lcd.setCursor(0, 1);
  lcd.print("text2");
}

void loop() {
  lcd.noBlink();
  delay(3000);
  lcd.blink();
  delay(3000);
}