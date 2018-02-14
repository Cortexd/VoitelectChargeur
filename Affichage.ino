


void GestionAffichageMenu()
{


switch (MODE_AFFICHAGE)
    {
        // Affiche info demarrage
        case 0:
          {
                EcritureTimeLCD(now);
                EcritureStatutRelais();
                EcritureLCD("Power Concoures");
                adjuste_Time = DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), 0);
                break;
          }

        // Reglage heure
        case 1:
          {
                //RTC.adjust(DateTime(2014, 1, 21, 23, 59, 50));
                EcritureTimeLCDFixe(adjuste_Time);
                EcritureLCD("Reglage Heure");
                break;
          }


        // Reglage LCD
        case 2:
          {
                EcritureTimeLCD(now);
                EcritureLCD("Reglage LCD");
                EcritureNiveauBackLight(backlight_niveau);
                break;
          }


        // Affiche date
        case 3:
          {
                EcritureTimeLCD(now);
                EcritureDateLCD(now);
                break;
          }

          // Affiche memoire restante
        case 4:
            {
                  EcritureTimeLCD(now);
                  EcritureLCD("Mem: ");
                  lcd.setCursor(5,1) ;
                  lcd.print(info);
                  break;
            }
    }
}
