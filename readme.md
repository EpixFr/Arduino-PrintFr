Arduino PrintFr
=========================

Introduction
------------
PrintFr est une bibliothèque pour Arduino permettant l'affichage de lettres accentuées lors de l'envoi de données par USB/serial avec des cartes Arduino 

[En] : Library for displaying accented letters when sending data via USB/serial with Arduino card

Caractères supportés
--------------------
ä â à ç ë ê é è ï î ö ô ü û ù µ °   

Méthodes
---------------

### *Affiche(String Texte, boolean RetourLn, boolean Debug)* ###
Affiche directement le texte en transcodant les accents.  

**Paramètres :** 
- Texte : Texte qui sera transcodé [Obligatoire]
- RetourLn : Booléen permettant de réaliser un retour à la ligne [Falcultatif - true : par défaut]
- Debug : Booléen permettant de passer en mode Debug [Falcultatif - false : par défaut]

### *Ecrit(String Texte, boolean RetourLn, boolean Debug)* ###
Ecriture lettre par lettre du texte transcodé. 

**Paramètres :** 
- Texte : Texte qui sera transcodé [Obligatoire]
- RetourLn : Booléen permettant de réaliser un retour à la ligne [Falcultatif - true : par défaut]
- Debug : Booléen permettant de passer en mode Debug [Falcultatif - false : par défaut]


Exemple d'utilisation
---------------------

        PrintFr Message;
        Message.Ecrit("Ecriture avec des caratères accentués.");
        Message.Affiche("Caractères pris en charge : ä â à ç ë ê é è ï î ö ô ü û ù µ °", true);
        Message.Affiche("Debugage de caractères accentués avec température en °C.", true,true);

Plus d'informations dans le fichier d'exemple.

Installation
------------
Téléchargez [la dernière version de PrintFr](https://github.com/EpixFr/Arduino-PrintFr/releases).  
 Décompactez l'archive dans le répertoire des bibliothèques de votre Arduino, généralement dans `C:\Program Files (x86)\Arduino\libraries` .


Licence GNU/GPLv2.1
--------------------
PPW is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or any later version.

PPW is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with PPW; if not, write to the 
Free Software Foundation, Inc., 
51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

