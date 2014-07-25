// Testing multiple LCD(I2C)

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);

void setup()
{
  lcd1.begin();
  lcd2.begin();

}

void loop()
{
  lcd1.setCursor(0,0);
  lcd1.print("Hello! LCD1"); 
  lcd1.setCursor(0,1);
  lcd1.print("2456 Watts-Hour");
  lcd2.setCursor(0,0);
  lcd2.print("Welcome! LCD2");
  lcd2.setCursor(0,1);
  lcd2.print("43 Baht per Hour");
  //lcd2.scrollDisplayLeft();
  delay(500);  
}

int strlen(char *str)
{
  int i=0, count = 0;

  while(str[i] != '\0') {
    count++;
    i++;
  }
  return count;
}
