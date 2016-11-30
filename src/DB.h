#ifndef DB_HPP
#define DB_HPP

#include <sqlite3.h> 
#include <string>
#include <vector>
#include <map>

#include "Ware.h"
#include "Empfaenger.h"
#include "Absender.h"

class DB
{
public:

   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char* data = "Callback function called";

    DB(const char* DatabaseName);
    ~DB();

//interne Funktionen
   //keine Ahnung, was die Funktion macht
   static int callback(void *NotUsed, int argc, char **argv, char **azColName);
   
   //keine Ahnung, was die Funktion macht
   static int callback_select(void *data, int argc, char **argv, char **azColName);

   //führt den SQL-Code aus (Insert)
   static void executeSqlInsert(sqlite3 *db, char *sql, char *zErrMsg, int rc, std::string funktionsname);
   
   //führt den SQL-Code aus (Select)
   static void executeSqlSelect(sqlite3 *db, char *sql, char *zErrMsg, int rc, const void* data, std::string funktionsname);

//essentielle Datenbankoperationen
   //erstellt Tabellen nach Maßgabe einer Sql-Datei
   void createTables(std::string sqlFromFile);

   //schließt die Datenbank
   void closeDatabase();


//Inserts
   //fügt einen Datensatz in Tabelle "Warengruppe" ein
   void insertRecordWarengruppe(std::string name, std::string kommentar = "");
   
   //fügt einen Datensatz in Tabelle "Ware" ein
   void insertRecordWare(std::string name, std::string warengruppe);
   
   //fügt einen Datensatz in Tabelle "Absender" ein
   void insertRecordAbsender(std::string name , std::string email, std::string adresse);

   //fügt einen Datensatz in Tabelle "Empfänger" ein
   void insertRecordEmpfaenger(std::string name , std::string email, std::string adresse);   
      
      
//Selects
   //gibt einen Vector aus allen Namen aus der Tabelle "Warengruppe" zurück
   std::vector<std::string> getAlleWarengruppenFromDB();

   //gibt einen Vector aus allen Datensätzen des Typs "Ware" zurück
   std::vector<Ware> getAlleWarenFromDB();
   
   //gibt einen Vector aus allen Namen aus der Tabelle "Emfaenger" zurück
   std::vector<std::string> getAlleEmpfaengerNamen();
   
   //gibt einen Vector aus allen Namen aus der Tabelle "Absender" zurück
   std::vector<std::string> getAlleAbsenderNamen();
   
   //gibt einen Vector aus allen Datensätzen des Typs "Empfaenger" zurück
   std::vector<Empfaenger> getAlleEmpfaenger();
   
   //gibt einen Vector aus allen Datensätzen des Typs "Absender" zurück
   std::vector<Absender> getAlleAbsender();
   
   
//Updates   
   //ändert einen Wert in einem Datensatz der Tabelle "Ware"
   void updatePreisProKg(std::string ware, std::string warengruppe, float preis = 0);

   //ändert einen Wert in einem Datensatz der Tabelle "Ware"
   void updatePreisProSt(std::string ware, std::string warengruppe, float preis = 0);

   //ändert einen Wert in einem Datensatz der Tabelle "Ware"
   void updateKommentar(std::string ware, std::string warengruppe, std::string kommentar);
   

//Deletes
   //löscht eine Ware aud der Tabelle "Ware"
   void deleteWare(std::string ware, std::string warengruppe);
   
   //gibt true zurück, falls die Warengruppe in der Tabelle "Ware" nicht mehr als Fremdschlüssel vorkommt
   bool warengruppeIsDeletable(std::string warengruppe);

   //löscht eine Warengruppe aus der Tabelle "Warengruppe"
   void deleteWarengruppe(std::string warengruppe);
};

#endif // DB_HPP
