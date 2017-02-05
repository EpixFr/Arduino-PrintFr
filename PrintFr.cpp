  #include "PrintFr.h"


PrintFr::PrintFr() {
    //Pour la stabilité de la liaison
    delay(1);
    //Démarrage de la connexion USB/Série
    Serial.begin(9600);    
  }

void PrintFr::Ecrit(String Texte) {
  Ecrit(Texte,true,false);
}

void PrintFr::Ecrit(String Texte,boolean RetourLn) {
  Ecrit(Texte,RetourLn,false);
}

void PrintFr::Ecrit(String Texte,boolean RetourLn,boolean Debug) {
  int Caract;
  for (byte index=0; index < Texte.length(); index++) {
   if ((byte (Texte[index]) == 0xC3)|| (byte (Texte[index]) == 0xC2)) {
    Caract = int(Texte[++index]);    
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
     if (Debug) { Serial.print("[");Serial.print(Caract);Serial.print("]"); }  
   } else {
    Serial.print(Texte[index]);
   }
 }
 if (RetourLn) { Serial.println(); }
}
