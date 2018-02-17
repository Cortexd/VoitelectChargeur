

/////////////////////////
//  Regle relais 1 MIEV
//  Maintenant :
//  DateDeb : 6h30  -> Arret relais
//  DateFin : 22H30 -> Debut relais
//  retourne true si DateDeb < maintenant < DateFin
/////////////////////////
bool IsBetween(DateTime maintenant, DateTime dateDeb, DateTime dateFin)
{
  unsigned long test = maintenant.unixtime();
  unsigned long deb  = dateDeb.unixtime();
  unsigned long fin  = dateFin.unixtime();

  if (deb < test & test < fin)
  {
      return true;
  }
  else
  {
      return false;
  }
}


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
