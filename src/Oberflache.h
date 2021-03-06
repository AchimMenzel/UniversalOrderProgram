//--- Oberfläche.h - start ---

#ifndef OBERFLACHE_H
#define OBEFLACHE_H

#include "ui_Oberflache.h"
#include <vector>
#include <string>
#include "Ware.h"
#include "Warengruppe.h"
#include "DB.h"

using namespace std;

class Oberflache : public QMainWindow, public Ui::MainWindow{
  	Q_OBJECT

 	public:
 		Oberflache (QMainWindow *parent = 0);
 		~Oberflache();
		void aktualisiereOberflaeche();
		
	private slots:
		void generiereWare();
		void beenden();
		void versendeEmail();
		void generiereWarenGruppe();
		void entferneWare();
		void zelleaktualisiert(QTableWidgetItem* x);
		void entferneWarenGruppe();
		void aktualisiereEinstellungen();
		void aktualisiereZielDatum(QDate d);
		void aktualisiereZielZeit(QTime t);
		void aktualisiereZielKommentar();
		
		
	private:
		vector<string> warenNameVector;
		vector<Ware> warenVector;
		vector<Ware> bestelltWarenVector;
		vector<Warengruppe> warenGruppeVector;
		//vector<int> second = vector<int> (4,100); 
		//vector< vector<string> > second;
		
};
#endif