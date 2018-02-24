
/////////////////////////
//  Verif si on doit arreter le forcage
//  Arret à 9H
/////////////////////////
void CheckForceChargement()
{
    // Si on est en forcé
    if (forceChargement) 
    {
        // Si relais pas encore actif -> On active
        if (!relay1Miev)
        {
            relay1Miev = true;
            digitalWrite(relay1Pin, LOW);
        }
        if (!relay2Ionic)
        {
            relay2Ionic = true;
            digitalWrite(relay2Pin, LOW);
        }

        // Doit on arreter le forceCharge ?
        // est on entre 9h00'00s et 9h00'10s
        DateTime deb = DateTime(now.year(), now.month(), now.day(), 9, 0, 0);
        DateTime fin = DateTime(now.year(), now.month(), now.day(), 9, 0, 10);
    
        bool test = IsBetween(now, deb, fin);
        if (test)
        {
            forceChargement = false;
        }
    }
 }



/////////////////////////
//  Regle relais 1 MIEV
/////////////////////////
void CheckRelais1()
{

  bool test = IsBetween(now, Debut1Miev, Fin1Miev);

  // 12h00 entre 9h -> 22H15 : true
  // 00h00 entre 23h -> 9H : false
 if (test)
  {
    //Serial.println("MIEV OFF");
    // DE activation uniquement si nécessaire
    if (relay1Miev)
    {
      relay1Miev = false;
      digitalWrite(relay1Pin, HIGH);
    }
  }
  else
  {
    //Serial.println("MIEV ON");
    //  activation uniquement si nécessaire
    if (!relay1Miev)
    {
      relay1Miev = true;
      digitalWrite(relay1Pin, LOW);
    }
  }
}

/////////////////////////
//  Regle relais 2 IONIC
/////////////////////////
void CheckRelais2()
{
   bool test = IsBetween(now, Debut2Ionic, Fin2Ionic);

   // 12h00 entre 1h30h -> 9H : false
   // 02h00 entre 1h30 -> 9H : true
  if (!test)
  {
    //Serial.println("IONIC OFF");
    // DE activation uniquement si nécessaire
    if (relay2Ionic)
    {
      relay2Ionic = false;
      digitalWrite(relay2Pin, HIGH);
    }
  }
  else
  {
    //Serial.println("IONIC ON");
    //  activation uniquement si nécessaire
    if (!relay2Ionic)
    {
      relay2Ionic = true;
      digitalWrite(relay2Pin, LOW);
    }
  }
}
