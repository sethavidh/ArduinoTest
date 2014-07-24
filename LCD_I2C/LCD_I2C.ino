#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin(); 
}

void loop()
{
  int i, n, num1, num2;
  char char1[17], char2[17];
  
  num1 = 4523;
  num2 = 980;
  
  itoa(num1, char1, 10);
  itoa(num2, char2, 10);
  
  n = strlen(char1);
  lcd.setCursor(16-n,0);
  lcd.print(char1);
  n = strlen(char2);
  lcd.setCursor(16-n,1);
  lcd.print(char2);
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
