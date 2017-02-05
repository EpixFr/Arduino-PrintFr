/*
 * Fichier d'exemple de fonctionnement 
 * de la bibliothèque PrintFr 
 * 
 * Par Eric Gautheron
 */

#include "PrintFr.h"

void setup() {
  /* Création de l'instance Message de type PrintFr */
  PrintFr Message;
  /* Ecriture d'un message sans paramètre optionnel */
  Message.Ecrit("Test avec des caratères accentués.");
  /* Ecriture d'un message en obligeant le retour à la ligne */
  Message.Ecrit("ä â à ç ë ê é è ï î ö ô ü û ù µ °", true);
  /* Ecriture d'un message sans retour à la ligne avec la gestion du debug */
  Message.Ecrit("C'est un début pour voir où l'on va avec cette température en °C ou en µF", false,true); 
  }
 
void loop() {
  }

