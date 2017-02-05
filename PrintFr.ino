/*
 * Fichier d'exemple de fonctionnement 
 * de la bibliothèque PrintFr 
 * 
 * Par Eric Gautheron
 * Version 1.0
 */

#include "PrintFr.h"

void setup() {
  /* Création de l'instance Message de type PrintFr */
  PrintFr Message;
  /* Ecriture d'un message sans paramètre optionnel */
  Message.Ecrit("Ecriture avec des caratères accentués.");
  /* Affichage d'un message en obligeant le retour à la ligne */
  Message.Affiche("Affichage : ä â à ç ë ê é è ï î ö ô ü û ù µ °", true);
  /* Ecriture d'un message sans retour à la ligne avec la gestion du debug */
  Message.Affiche("C'est un début pour voir où l'on va avec cette température en °C ou en µF", false,true); 
  }
 
void loop() {
  }

