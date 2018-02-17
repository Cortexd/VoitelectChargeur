


void GestionAffichageMenu()
{

   EcritureStatutRelais();

   switch (MODE_AFFICHAGE)
    {
        // Affiche info demarrage
        case 0:
          {
                EcritureTimeLCD(now);
                EcritureLCD("Power Concoures");
                adjuste_Time = DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), 0);
                break;
          }

        // force chargement
        case 1:
         {
                EcritureTimeLCD(now);
                EcritureLCD("Forcer Chargement ?");
                break;
          }

        // Reglage heure
        case 2:
          {
                //RTC.adjust(DateTime(2014, 1, 21, 23, 59, 50));
                EcritureTimeLCDFixe(adjuste_Time);
                EcritureLCD("Reglage Heure");
                break;
          }


        // Reglage LCD
        case 3:
          {
                EcritureTimeLCD(now);
                EcritureLCD("Reglage LCD");
                EcritureNiveauBackLight(backlight_niveau);
                break;
          }


        // Affiche date
        case 4:
          {
                EcritureTimeLCD(now);
                EcritureDateLCD(now);
                break;
          }

          // Affiche memoire restante
        case 5:
            {
                  EcritureTimeLCD(now);
                  EcritureLCD("Mem: ");
                  lcd.setCursor(5,1) ;
                  lcd.print(freeRam());
                  break;
            }

         // Affiche Miev1
        case 6:
            {
                  EcritureTimeLCD(now);
                  EcritureLCD("MIEV1:");
                  lcd.setCursor(6,1) ;
                  EcritureTimeLCDSecondeLigne(Debut1Miev);
                  break;
            }
         // Affiche Miev2
        case 7:
            {
                  EcritureTimeLCD(now);
                  EcritureLCD("MIEV2:");
                  lcd.setCursor(6,1) ;
                  EcritureTimeLCDSecondeLigne(Fin1Miev);
                  break;
            }
         // Affiche Miev2
        case 8:
            {
                  EcritureTimeLCD(now);
                  EcritureLCD("IONIC1:");
                  lcd.setCursor(7,1) ;
                  EcritureTimeLCDSecondeLigne(Debut2Ionic);
                  break;
            }
        // Affiche Miev2
        case 9:
            {
                  EcritureTimeLCD(now);
                  EcritureLCD("IONIC2:");
                  lcd.setCursor(7,1) ;
                  EcritureTimeLCDSecondeLigne(Fin2Ionic);
                  break;
            }


    }
}
