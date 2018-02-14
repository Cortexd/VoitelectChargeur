

void CalculDebutFin()
{
  // Tarif bleu 12Kw
  // HC : 0.13kw/h
  // Heure creuse : 22h30 -> 6h30

  // Charge dure max 8H * 2.3kw =
  // Indique la plage d'arret
  Debut1Miev =  DateTime(now.year(), now.month(), now.day(), 9, 0, 0);
  Fin1Miev =    DateTime(now.year(), now.month(), now.day(), 22, 35, 0);

  // Charge dure max 5H * 2.76kw =
  Debut2Ionic = DateTime(now.year(), now.month(), now.day(), 1, 30, 0);
  Fin2Ionic =   DateTime(now.year(), now.month(), now.day(), 9, 0, 0);
}


/////////////////////////
//  Regle relais 1 MIEV
/////////////////////////
void CheckRelais1()
{

  bool test = IsBetween(now, Debut1Miev, Fin1Miev);

  if (test)
  {
    //Serial.println("MIEV OFF");
    // DE activation uniquement si nécessaire
    if (relay1Miev)
    {
      EcritureLCD("Arret MIEV");
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
      EcritureLCD("Activation MIEV ");
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

  if (!test)
  {
    //Serial.println("IONIC OFF");
    // DE activation uniquement si nécessaire
    if (relay2Ionic)
    {
      EcritureLCD("Arret IONIC");
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
      EcritureLCD("Activation IONIC");
      relay2Ionic = true;
      digitalWrite(relay2Pin, LOW);
    }
  }
}
