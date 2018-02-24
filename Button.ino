/** Retourne le bouton appuyé (si il y en a un) */
byte getPressedButton() {

  /* Lit l'état des boutons */
  int value = analogRead(A0);

  if (value < 1000)
        Serial.println(value);

  /* Calcul l'état des boutons */
  if (value < 50)
    return BUTTON_RIGHT;
  else if (value < 200)
    return BUTTON_UP;
  else if (value < 300)
    return BUTTON_DOWN;
  else if (value < 600)
    return BUTTON_LEFT;
  else if (value < 850)
    return BUTTON_SELECT;
  else
    return BUTTON_NONE;
}


void GestionBouton()
{

    // check for key presses
    // check for key presses
    if (testMillis() > lastKeyCheckTime + keySampleRate)
    {
        lastKeyCheckTime = testMillis();
        localKey = getPressedButton();
        if (localKey != lastKeyPressed)
        {
            TraitementBouton(localKey);
        }
        else
        {
            // key value has not changed, key is being held down, has it been long enough?
            // (but don't process localKey = 0 = no key pressed)
            if (localKey != 0 && testMillis() > lastKeyPressTime + keyRepeatRate)
            {
                // yes, repeat this key
                // changed: don't repeat left and right, they only change menu options
                if (localKey != 5 && localKey != 2)
                {
                    // and really, no sense in repeating except when chaning numeric settings
                    //if (!strcmp(settings[settingsPos].type, "int") || !strcmp(settings[settingsPos].type, "dec")){
                        TraitementBouton(localKey);
                    //}
                }
            }
        }
    }
}

void TraitementBouton(byte bout)
{

  switch (bout) {

      case BUTTON_NONE:
        break;

      ////////////////
      case BUTTON_UP:


           if (MODE_AFFICHAGE == 2) // Ajuste horloge
           {
                adjuste_Time = DateTime (adjuste_Time.unixtime() + 60);
           }
           if (MODE_AFFICHAGE == 3) // Ajuste lcd
            {
                backlight_niveau = backlight_niveau + 5;
                analogWrite(BACKLIGHT_PWM_PIN, backlight_niveau);
            }

        break;

      ///////////////////
      case BUTTON_DOWN:

            if (MODE_AFFICHAGE == 2) // Ajuste horloge
            {
                adjuste_Time = DateTime (adjuste_Time.unixtime() - 60);
            }
            if (MODE_AFFICHAGE == 3) // Ajuste lcd
            {
                backlight_niveau = backlight_niveau - 5;
                analogWrite(BACKLIGHT_PWM_PIN, backlight_niveau);
            }


        break;

       //////////////////////
       case BUTTON_SELECT:

            if (MODE_AFFICHAGE == 2) // Ajuste horloge
            {
                RTC.adjust(adjuste_Time);     // Enregistre
                EcritureLCD("Changement ok   "); // Affiche ok
                delay(1000);                   // Attend
                MODE_AFFICHAGE = 0;           // change sur le menu d'origine
            }
            if (MODE_AFFICHAGE == 1) // Forcer chargement
            {
                if (forceChargement)
                {
                    forceChargement = false;
                    EcritureLCD("Arret ok        ");
                }
                else
                {
                    forceChargement = true;
                    EcritureLCD("Depart ok       ");
                }
                delay(2000);                   // Attend
                MODE_AFFICHAGE = 0;           // change sur le menu d'origine
            }


        break;


      // Changement de menu gauche droite
      case BUTTON_RIGHT:
         {
            MODE_AFFICHAGE = MODE_AFFICHAGE + 1;
            if (MODE_AFFICHAGE > MAX_MODE_AFFICHAGE)
            {
                MODE_AFFICHAGE = 0;
            }
            break;
         }
      case BUTTON_LEFT:
         {
            MODE_AFFICHAGE = MODE_AFFICHAGE - 1;
            if (MODE_AFFICHAGE < 0)
            {
                MODE_AFFICHAGE = MAX_MODE_AFFICHAGE;
            }
            break;
         }


  }

}
