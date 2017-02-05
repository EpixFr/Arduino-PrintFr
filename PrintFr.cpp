/***************************************************************
  Bibliothèque PrintFr / Library PrintFr
----------------------------------------------------------------
  DESCRIPTION : Bibliothèque permettant l'affichage de lettres
                accentuées lors de l'envoi de données 
                par USB/serial avec des cartes Arduino 

  DESCRIPTION : Library for displaying accented letters when
                sending data via USB/serial with Arduino card
----------------------------------------------------------------                
  Caractères supportés : ä â à ç ë ê é è ï î ö ô ü û ù µ °  
----------------------------------------------------------------
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the 
Free Software Foundation, Inc., 
51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
----------------------------------------------------------------
@author Eric Gautheron alias EpixFr <epix[at]konectik.fr>
version : 1.0
***************************************************************/

#include "PrintFr.h"

/**
  Constructeur 
  permettant le démarrage de la connexion USB/série
**/
PrintFr::PrintFr() {
    //Pour la stabilité de la liaison
    delay(1);
    //Démarrage de la connexion USB/Série
    Serial.begin(9600);    
  }

/**
  Méthode d'affichage d'un texte 1 paramètre  
  Le paramètre de retour à la ligne est mis à vrai
  Le paramètre de debug est mis à faux
  @param string Texte // Texte qui sera transcodé
**/
void PrintFr::Affiche(String Texte) {
  Transcodage(Texte,true,false,false);
}

/**
  Méthode d'affichage d'un texte avec 2 paramètres
  Le paramètre de debug est mis à faux
  @param string Texte // Texte qui sera transcodé
  @param boolean RetourLn // True : retour à la ligne
**/
void PrintFr::Affiche(String Texte,boolean RetourLn) {
  Transcodage(Texte,RetourLn,false,false);
}

/**
  Méthode d'affichage d'un texte avec 3 paramètres
  @param string Texte // Texte qui sera transcodé
  @param boolean RetourLn // True : retour à la ligne
  @param boolean Debug // True : Debug activé
**/
void PrintFr::Affiche(String Texte,boolean RetourLn,boolean Debug) {
 Transcodage(Texte,RetourLn,Debug,false);
}

/**
  Méthode d'écriture d'un texte 1 paramètre  
  Le paramètre de retour à la ligne est mis à vrai
  Le paramètre de debug est mis à faux
  @param string Texte // Texte qui sera transcodé
**/
void PrintFr::Ecrit(String Texte) {
  Transcodage(Texte,true,false,true);
}

/**
  Méthode d'écriture d'un texte avec 2 paramètres
  Le paramètre de debug est mis à faux
  @param string Texte // Texte qui sera transcodé
  @param boolean RetourLn // True : retour à la ligne
**/
void PrintFr::Ecrit(String Texte,boolean RetourLn) {
  Transcodage(Texte,RetourLn,false,true);
}

/**
  Méthode d'écriture d'un texte avec 3 paramètres
  @param string Texte // Texte qui sera transcodé
  @param boolean RetourLn // True : retour à la ligne
  @param boolean Debug // True : Debug activé
**/
void PrintFr::Ecrit(String Texte,boolean RetourLn,boolean Debug) {
 Transcodage(Texte,RetourLn,Debug,true);
}

/**
  Méthode privée de transcodage des caractères accentués
  @param string Texte // Texte qui sera transcodé
  @param boolean RetourLn // True : retour à la ligne
  @param boolean Debug // True : Debug activé
  @param boolean Ecriture // True : Ecrit lettre par lettre
**/
void PrintFr::Transcodage(String Texte,boolean RetourLn,boolean Debug,boolean Ecriture) {
  int Caract;
  //Parcours de l'ensemble des caractères du texte
  for (byte index=0; index < Texte.length(); index++) {
   if ((byte (Texte[index]) == 0xC3)|| (byte (Texte[index]) == 0xC2)) {
    Caract = int(Texte[++index]);       
    //Transcodage du caractère en cours  
       switch (Caract) {
         case -92 : {Serial.print(char (228)); break;} // ä     
         case -94 : {Serial.print(char (226)); break;} // â
         case -96 : {Serial.print(char (224)); break;} // à
         case -89 : {Serial.print(char (231)); break;} // ç
         case -85 : {Serial.print(char (235)); break;} // ë
         case -86 : {Serial.print(char (234)); break;} // ê
         case -87 : {Serial.print(char (233)); break;} // é
         case -88 : {Serial.print(char (232)); break;} // è
         case -81 : {Serial.print(char (239)); break;} // ï
         case -82 : {Serial.print(char (238)); break;} // î
         case -76 : {Serial.print(char (244)); break;} // ô
         case -74 : {Serial.print(char (246)); break;} // ö
         case -68 : {Serial.print(char (252)); break;} // ü
         case -69 : {Serial.print(char (251)); break;} // û
         case -71 : {Serial.print(char (249)); break;} // ù
         case -75 : {Serial.print(char (181)); break;} // µ
         case -80 : {Serial.print(char (176)); break;} // °
       }
    //Si le mode Debug est activé on affiche le code du caractère intercepté. 
    //Permet d'ajouter des caractères supplémentaires
     if (Debug) { Serial.print("[");Serial.print(Caract);Serial.print("]"); }  
   } else {
    Serial.print(Texte[index]);
   }
   //Gestion de l'écriture caractère par caractère
    if (Ecriture) {delay(80);}
 }
 //Gestion du retour à la ligne
 if (RetourLn) { Serial.println(); }
}

