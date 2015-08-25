#include <LiquidCrystal.h>
#include <BigFont.h>

// set this up for your LCD display connections
LiquidCrystal lcd(7, 8, 2, 3, 4, 5);

BigFont bigfont;

void setup() 
{
  lcd.begin(20,4);
  lcd.clear();  
  
  Serial.begin(115200);
  Serial.println();

  bigfont.loadchars(lcd);
}

void loop() 
{
  int inChar;
  String inString = "";
  while(Serial.available()>0)
  {
    inChar = Serial.read();
    Serial.print("char = ");
    Serial.print(inChar);
    Serial.print("\n");
    if(isDigit(inChar))
    {
      inString += (char) inChar;
    }
    // (LCD, digit, col, row, symbol)
    bigfont.printbigchar(lcd, (byte)inString.toInt(),    0, 0, 0);
    bigfont.printbigchar(lcd, (byte)inString.toInt()+1,  5, 0, 0);
    bigfont.printbigchar(lcd, (byte)inString.toInt()+2, 10, 0, 1); 
  } // while(Serial.available)
} // loop()
