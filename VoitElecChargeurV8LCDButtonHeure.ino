// fonctions Date et heure en utilisant
// le RTC DS1307 RTC via bus I2C et librairie Wire
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

// Utilise les port A4 (SDA) et A5 (SCL)
RTC_DS1307 RTC;

// LCD
static LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const byte BACKLIGHT_PWM_PIN = 10; /** Broche pour le contrôle du rétroéclairage */
byte backlight_niveau = 125;


// Bouton
enum {
  BUTTON_NONE,  /*!< Pas de bouton appuyé */
  BUTTON_UP,    /*!< Bouton UP (haut) */
  BUTTON_DOWN,  /*!< Bouton DOWN (bas) */
  BUTTON_LEFT,  /*!< Bouton LEFT (gauche) */
  BUTTON_RIGHT, /*!< Bouton RIGHT (droite) */
  BUTTON_SELECT /*!< Bouton SELECT */
};

const int keyRepeatRate = 80;    // when held, key repeats 1000 / keyRepeatRate times per second
unsigned long lastKeyCheckTime = 0;
int lastKeyPressed = 0;
const int keySampleRate = 200; // ms between checking keypad for key
unsigned long lastKeyPressTime = 0;
int localKey =0;

// Relay pin
const int relay1Pin = 3;
const int relay2Pin = 2;
bool relay1Miev;
bool relay2Ionic;

// date
// Variable pour mettre la date une seule fois au demarrage
// ATTENTION : Recompiler avec false pour qu'il n'y ai pas remise à la date a chaque reboot.

bool setFirstDateTime = false;
DateTime now;
DateTime adjuste_Time;
DateTime Debut1Miev;
DateTime Fin1Miev;
DateTime Debut2Ionic;
DateTime Fin2Ionic;
bool forceChargement = false;

// menu
int MODE_AFFICHAGE;
#define MAX_MODE_AFFICHAGE 9

void setup ()
{
  // INIT SERIAL
  Serial.begin(9600);

  // INIT RELAIS
  pinMode(relay1Pin, OUTPUT);
  digitalWrite(relay1Pin, HIGH);
  pinMode(relay2Pin, OUTPUT);
  digitalWrite(relay2Pin, HIGH);

  // INIT RTC
  Wire.begin();
  RTC.begin();
  
  // SET RTC
  if (setFirstDateTime)
  {
    Serial.println("Mise en place heure");
    if (RTC.isrunning())
    {
      Serial.println("Mise en place heure OK");
      RTC.adjust(DateTime(__DATE__, __TIME__)); // La ligne suivante fixe la date et l'heure du RTC avec les date et heure de compilation du sketch
      //RTC.adjust(DateTime(2014, 1, 21, 8, 59, 40));
    }
    else
    {
      Serial.println("Erreur mise en place RTC");
    }
  }

  // INIT LCD
  lcd.begin(16, 2);
  // rétroéclairage 0->255
  analogWrite(BACKLIGHT_PWM_PIN, backlight_niveau);

  // Menu
  MODE_AFFICHAGE = 0;

}

void loop ()
{

  now = RTC.now();
  CalculDebutFin();

  // Si force chargement
  // Pas de vérif des timers
  if (!forceChargement)
  {
    CheckRelais1();
    CheckRelais2();
  }

  // Gestion force chargement
  CheckForceChargement();

  GestionBouton();
  GestionAffichageMenu();
  delay(100);

}


unsigned long testMillis(){
 
    return 0xFFFEB3F8 + millis() ;
}
