//--------------------------------------------
//        Affichage des caractères accentués
// 
// EG - 05.02.17
// Version : 0.4
//-------------------------------------------

#include "PrintFr.h"



void setup() {
  Serial.begin(9600);
  Serial.println("coucou c'est un test");

  PrintFr Message;
  Message.Ecrit("Test avec des caratères accentués.");
  Message.Ecrit("ä â à ç ë ê é è ï î ö ô ü û ù µ °", true);
  Message.Ecrit("C'est un début pour voir où l'on va avec cette température en °C ou en µF",false,true); 
  }
 
void loop() {

  }

