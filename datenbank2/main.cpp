#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "DB.h"
#include "Helper.h"
#include "Absender.h"
#include "Empfaenger.h"

int main(int argc, char **argv)
{
//DB erzeugen etc.
	//erzeugt datenbankobjekt mit name db
   DB db("db");

   //erzeugt Tabellen in der Datenbank db, auf Grundlage der Datei: "db.sql"
   //db.createTables(Helper::getSqlFromFile("db.sql"));
   





//Erzeuge Daten
//   db.insertRecordInWarengruppe("Reh", "Hat ein kleines Gehörn.");
//   db.insertRecordInWarengruppe("Hirsch", "Hat ein großes Geweih.");
// 
//   db.insertRecordInWare("Filet", "Reh");
//   db.insertRecordInWare("Haxen", "Hirsch");
//   db.insertRecordInWare("Blatt", "Reh");
//   db.insertRecordInWare("Lende", "Hirsch");
//   db.insertRecordInWare("Wurstfleisch", "Reh");
//
//   db.insertRecordInAbsenderEmpfaenger("Empfaenger", "Las Kalisz", "Las Kalisz\nStraße des Wildes 123\n04353 Tomnice", "laskalisz@web.pl");





//Ändere Daten
   //db.updateKommentar("Lende", "Hirsch", "Bitte eingefroren.");
   //db.updatePreisProKg("Haxen", "Hirsch",9.3);
   //db.updatePreisProSt("Lende", "Hirsch", 35.45);
   
   //ändert einen Wert in der Tabelle "Absender" oder "Empfänger"
   //db.updateWerteInAbsenderEmpfaenger("Empfaenger", "Wursthandel Jankowski", "Emailadresse", "jankowskiInPolen@mail.pl");

   //setzt alle "Menge"-Felder in der Tabelle "Ware" auf 0
//   db.clearAllMengeFelder();

   //ändere Daten in "Ware" -> Menge
   //db.updateMengeInSt("Ware2", "Reh", 955.11);




//Lösche Daten
   //lösche eine Ware
   //db.deleteWare("Blatt", "Reh");
   
   //prüft, ob die Warengruppe noch in der Tabelle "Ware" als Fremdschlüssel vorkommt
   //std::cout << db.warengruppeIsDeletable("Reh") << std::endl;

   //lösche eine Warengruppe
   //db.deleteWarengruppe("Reh");

   //lösche einen Datensatz in der Tabelle "Empfaenger" oder "Absender"
   //db.deleteRecordInAbsenderEmpfaenger("Empfaenger", "Wildhandel Broy 2");





//Hohle Daten
   //Hohle einen Vector mit Strings von "Warengruppen" aus der DB.
//   std::vector<std::string> testVect = db.getAlleWarengruppenNamen();
//   for (std::string i : testVect)
//   {
//      std::cout << i << std::endl;
//   }

   //Hohle einen Vector mit "Waren" aus der DB.
//   std::vector<Ware> testVectWare = db.getAlleWaren();
//   for (Ware i : testVectWare)
//   {
//      std::cout << i.getWarenName() << ", " << i.getWarenGruppeName() << ", " << i.getPreisProGewicht() \
//      << ", " << i.getPreisProStueck() << ", " << i.getKommentar() << ", " << i.getMengeInStueck() << ", " << i.getMengeInGewicht() << std::endl;
//   }
   
   
   

   //Hohle einen Vector mit Strings von "Empfaenger" aus der DB
//   std::vector<std::string> testVect = db.getAlleEmpfaengerNamen();
//   for (std::string i : testVect)
//   {
//      std::cout << i << std::endl;
//   }

   //Hohle einen Vector mit "Stellen" aus der DB
//   std::vector<Absender> testVect = db.getAlleAbsender();
//   for (Absender i : testVect)
//   {
//      std::cout << i.getName() << ", " << i.getAdresse() << ", " << i.getEmailadresse() << std::endl;
//   };

   //Hohle den ersten Empfaenger aus der DB
//   Empfaenger temp2 = db.getErstenEmpfaenger();
//   std::cout << temp2.getName() << ", " << temp2.getAdresse() << ", " << temp2.getEmailadresse() << std::endl;
//
//   Absender temp = db.getErstenAbsender();
//   std::cout << temp.getName() << ", " << temp.getAdresse() << ", " << temp.getEmailadresse() << std::endl;
//
//   //Hohle die erste Info aus InfoBestellung
//   InfoBestellung temp1 = db.getErsteInfoBestellung();
//   std::cout << temp1.getZieldatum() << ", " << temp1.getZielzeit() << ", " << temp1.getKommentar() << std::endl;



     //übergebe Thunderbird einen Emailtext aus den entsprechenden Tabellendaten
      Absender abs = db.getErstenAbsender();
      Empfaenger empf = db.getErstenEmpfaenger();
      InfoBestellung info = db.getErsteInfoBestellung();
      std::vector<Ware> waren = db.getAlleWaren();

      std::string warentextKg;
      std::string warentextSt;
      warentextKg = "";
      warentextSt = "";
      
      //baue zwei Strings auf; einen für Menge in Gewicht und einen für Menge in Stueck
      for (Ware i : waren)
      {
         if (i.getMengeInStueck() == 0 and i.getMengeInGewicht() == 0) 
         {
            continue;
         }   
         else if (i.getMengeInStueck() != 0 and i.getMengeInGewicht() == 0)
         {
             warentextSt += Helper::toString(i.getMengeInStueck()) + " Stück " + i.getWarenGruppeName() + "-" + i.getWarenName() + ". " + i.getKommentar() + "\n";
         }
         else if (i.getMengeInStueck() == 0 and i.getMengeInGewicht() != 0)
         {
             warentextKg += Helper::toString(i.getMengeInGewicht()) + " kg " + i.getWarenGruppeName() + "-" + i.getWarenName() + ". " + i.getKommentar() + "\n";
         }
         else
         {
             warentextSt += Helper::toString(i.getMengeInStueck()) + " Stück " + i.getWarenGruppeName() + "-" + i.getWarenName() + ". " + i.getKommentar() + "\n";
             warentextKg += Helper::toString(i.getMengeInGewicht()) + " kg " + i.getWarenGruppeName() + "-" + i.getWarenName() + ". " + i.getKommentar() + "\n";
         }
      };

      //baue den emailText-String auf
      std::string emailText;
      emailText =
      "Absender: " + abs.getName() + "\n" + \
      abs.getAdresse() + "\n\n" + \
      "Empfänger: " + empf.getName() + "\n" +
      empf.getAdresse() + "\n\n" + \
      "Bestellung für " + info.getZieldatum() + " " + info.getZielzeit() + "\n\n" + \
      warentextKg + "\n" + \
      warentextSt + "\n" + \
      info.getKommentar() + "\n\n" + \
      "Mit freundlichen Grüßen" + "\n" + \
      abs.getName() + "\n";
      
      //baue den Thunderbirdstring auf, der in der Kommandozeile ausgeführt wird. 
      std::string thunderbirdString = "thunderbird -compose to=" + empf.getEmailadresse() + ",subject='Bestellung für " + abs.getName() + " für " + info.getZieldatum() + "',body='" + emailText + "'";
      system(thunderbirdString.c_str());	



//schließe Datenbank
   //Die Datenbank unbedingt schließen, sonst bleibt sie wohl möglich im Speicher!
   db.closeDatabase();
}
