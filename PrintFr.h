/*****************************************/
/* Bibliothèque permettant l'affichage 
/* des lettre accentuées lors de l'envoi
/* de données par USB/serial
/*****************************************/
#ifndef PrintFr_h
#define PrintFr_h

#include <Arduino.h>

class PrintFr 
{
    public :
      //Constructeur
      PrintFr();
      //Méthodes
      void Ecrit(String Texte);
      void Ecrit(String Texte,boolean RetourLn);
      void Ecrit(String Texte,boolean RetourLn,boolean Debug);
};

#endif
