/*
 * Fichier d'exemple de fonctionnement 
 * de la bibliothèque PrintFr 
 * 
 * Par EpixFr <https://github.com/epixfr>
 */

#include <PrintFr.h>

void setup() {
  /* Création de l'instance Message de type PrintFr */
  PrintFr Message;
  /* Ecriture d'un message sans paramètre optionnel */
  Message.Ecrit("Ecriture avec des caratères accentués.");
  /* Affichage d'un message en obligeant le retour à la ligne */
  Message.Affiche("Caractères pris en charge : ä â à ç ë ê é è ï î ö ô ü û ù µ °", true);
  /* Ecriture d'un message sans retour à la ligne avec la gestion du debug */
  Message.Affiche("Debugage de caractères accentués avec température en °C.", true,true); 
  /* Ecriture d'un message sans paramètre optionnel */
  Message.Ecrit("Lancement du test de boucle.");
  }
 
void loop() {
  /* Création de l'instance Message de type PrintFr */
  PrintFr Message;
  /* Affichage libellé */
  Message.Affiche("Température : ",false);
  /* Affichage donnée */
  int temp = random(-20,50);
  Serial.print(temp);
  /* Affichage */
  Message.Affiche("°C"); 
  /* Pause 1 seconde*/
  delay(1000);  
  }

