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
version : 1.1
***************************************************************/

#ifndef PrintFr_h
#define PrintFr_h

/* Inclusion de la bibliothèque Arduino */
#include <Arduino.h>

class PrintFr 
{
    public :
      /* Constructeur */
      PrintFr();
      /* 
       *  Méthode d'affichage directe avec
       *  3 surcharges pour la gestion des paramètres optionnels
       *  
      */
      void Affiche(String Texte);
      void Affiche(String Texte,boolean RetourLn);
      void Affiche(String Texte,boolean RetourLn,boolean Debug);
      /* 
       *  Méthode d'écriture lettre par lettre avec
       *  3 surcharges pour la gestion des paramètres optionnels
       *  
      */
      void Ecrit(String Texte);
      void Ecrit(String Texte,boolean RetourLn);
      void Ecrit(String Texte,boolean RetourLn,boolean Debug);
      
    private :
      /* 
       *  Méthode privée de transcodage des caractères accentués
       */
      void Transcodage(String Texte,boolean RetourLn,boolean Debug,boolean Ecriture); 
};

#endif
