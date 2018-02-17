void EcritureLCD(String info)
{
  //lcd.clear();
  lcd.setCursor(0,1) ; //sets cursor to second line first row
  lcd.print("                ");
  lcd.setCursor(0,1) ;
  lcd.print(info);
}

void EcritureNiveauBackLight(byte level)
{
  lcd.setCursor(12,1);
  lcd.print("   ");
  lcd.setCursor(12,1);
  lcd.print(level);
}



void EcritureStatutRelais()
{
    // |10:10:10 M=M I=A|
    // |10:10:10 FORCE  |
    if (forceChargement)
    {
        lcd.setCursor(8,0); 
  lcd.print(" FORCE  ");
        }
        else
        {
       // |10:10:10 M=M I=A|
  lcd.setCursor(8,0); 
  lcd.print(" M=");
  lcd.print(relay1Miev);
  lcd.print(" I=");
  lcd.print(relay2Ionic);
   }
   
}

void EcritureTimeLCD(DateTime MyDateAndTime)
{
    lcd.setCursor(0,0);
    LcdPrint2Digits(MyDateAndTime.hour());
    sep();
    LcdPrint2Digits(MyDateAndTime.minute());
    sep();
    LcdPrint2Digits(MyDateAndTime.second());
}

void EcritureTimeLCDSecondeLigne(DateTime MyDateAndTime)
{
    LcdPrint2Digits(MyDateAndTime.hour());
    lcd.print(":");
    LcdPrint2Digits(MyDateAndTime.minute());
}

void EcritureTimeLCDFixe(DateTime MyDateAndTime)
{
    lcd.setCursor(0,0);
    LcdPrint2Digits(MyDateAndTime.hour());
    lcd.print("-");
    LcdPrint2Digits(MyDateAndTime.minute());
    lcd.print("-");
    LcdPrint2Digits(MyDateAndTime.second());
}

// sur ligne 2
void EcritureDateLCD(DateTime MyDateAndTime)
{
    lcd.setCursor(0,1) ; //sets cursor to second line first row
    lcd.print("                ");
    lcd.setCursor(0,1);
    LcdPrint2Digits(MyDateAndTime.day());
    lcd.print("/");
    LcdPrint2Digits(MyDateAndTime.month());
    lcd.print("/");
    lcd.print(MyDateAndTime.year());
}

/////////////////////////////////////
// Clignotement ":"
/////////////////////////////////////
char sep()
{
    unsigned long s = millis()/1000;
    if(s%2==0)
    {
        lcd.print(":");
    }
    else {
        lcd.print(" ");
    }
}

/////////////////////////////////////
// Gestion affichage sur 2H -> 02H
/////////////////////////////////////
void LcdPrint2Digits(byte number)
{
  if (number < 10)
  {
      lcd.print("0");
  }
  //lcd.print(number, DEC);
  lcd.print(number);
}
