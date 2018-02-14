

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



