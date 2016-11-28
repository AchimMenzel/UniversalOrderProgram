//--- Oberflache.cpp - start ---
#include "Oberflache.h"
#include "Ware.h"
#include <iostream>
#include <QString>
#include <vector>
#include <string> 
#include <Warengruppe.h>

#include <sstream>

Oberflache::Oberflache(QMainWindow *parent) : QMainWindow(parent){
//Constructor

//lädt UI
 	setupUi(this);
	
//Daten aus Datenbank lesen	sortiert
	
	Ware Schinken = Ware("Schinken","Fleisch",3.3,3.4,3.5,3.6,"kommentar Schinken");//debugging
	Ware Banane = Ware("Banane","Obst",2.5,2.6,2.7,2.8,"kommentar Banane");//debugging
	Ware Paprika = Ware("Paprika","Gemuese",2.4,2.5,2.6,2.7,"kommentar Paprika");//debugging
	Ware Salami = Ware("Salami","Fleisch",2.2,2.3,2.4,2.5,"kommentar Salami");//debugging
	
	warenVector.push_back(Salami);//debugging
	warenVector.push_back(Schinken);//debugging
	warenVector.push_back(Paprika);//debugging
	warenVector.push_back(Banane);//debugging
	
//Daten werden auf Oberfläche geladen	
	for(unsigned i3 = 0;i3<warenVector.size();++i3){		
		warenNameVector.push_back(warenVector[i3].getWarenGruppeName() + " " + warenVector[i3].getWarenName());
		warenGruppeVector.push_back(Warengruppe(warenVector[i3].getWarenGruppeName(), ""));
	}

	WarenTW->sortItems(0);
	this -> aktualisiereOberflaeche();
	
	
	connect(WareHinzuPB, SIGNAL(clicked()), this, SLOT(generiereWare()));
	connect(schliesenButton, SIGNAL(clicked()), this, SLOT(beenden()));
	connect(versendenButton, SIGNAL(clicked()), this, SLOT(versendeEmail()));
	connect(WarenGruppeHinzuPB, SIGNAL(clicked()), this, SLOT(generiereWarenGruppe()));	
	connect(WarEntfernenPB, SIGNAL(clicked()), this, SLOT(entferneWare()));
	connect(WarenTW, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(zelleaktualisiert(QTableWidgetItem*)));
	
}

Oberflache::~Oberflache() {
//Deconstructor	

}

void Oberflache::generiereWare(){
//erstellt neue Ware mit Daten aus Oberfläche

	//WarenGruppeCB

	Ware w1 = Ware((WarenNameHinzuEdit -> text()).toStdString(),WarenGruppeCB -> currentText().toStdString(),0,0,0,0,"");
	string s = w1.getWarenName() + " " + w1.getWarenGruppeName();
	
	//std::cout << warenVector.size() << std::endl;
	
	warenVector.push_back(w1);
	warenNameVector.push_back(s);
	
	//std::cout << warenVector.size() << std::endl;
	
	/*WarenTW->insertRow( WarenTW->rowCount() );
	
	std::stringstream ppgss;
			ppgss<<w1.getPreisProGewicht();
			std::string ppg = ppgss.str();
			
		std::stringstream ppsss;
			ppsss<<w1.getPreisProStueck();
			std::string pps = ppsss.str();
			
		std::stringstream migss;
			migss<<w1.getMengeInGewicht();
			std::string mig = migss.str();
			
		std::stringstream misss;
			misss<<w1.getMengeInStueck();
			std::string mis = misss.str();
		
		WarenTW->setItem(warenVector.size()-1, 1, new QTableWidgetItem(QString::fromStdString(w1.getWarenName())));
		WarenTW->setItem(warenVector.size()-1, 0, new QTableWidgetItem(QString::fromStdString(w1.getWarenGruppeName())));
		WarenTW->setItem(warenVector.size()-1, 2, new QTableWidgetItem(QString::fromStdString(ppg)));
		WarenTW->setItem(warenVector.size()-1, 3, new QTableWidgetItem(QString::fromStdString(pps)));
		WarenTW->setItem(warenVector.size()-1, 4, new QTableWidgetItem(QString::fromStdString(mig)));
		WarenTW->setItem(warenVector.size()-1, 5, new QTableWidgetItem(QString::fromStdString(mis)));
		
//setzt bestimmte Zellen auf nicht editierbar
		Qt::ItemFlags flags;
		
		flags = WarenTW->item(warenVector.size()-1, 0)->flags();
		flags |= Qt::ItemIsSelectable;
		flags &= ~Qt::ItemIsEditable; 
		WarenTW->item(warenVector.size()-1, 0)->setFlags(flags);
		
		flags = WarenTW->item(warenVector.size()-1, 1)->flags();
		flags |= Qt::ItemIsSelectable;
		flags &= ~Qt::ItemIsEditable; 
		WarenTW->item(warenVector.size()-1, 1)->setFlags(flags);*/
		
		WarenTW->sortItems(0);
		this -> aktualisiereOberflaeche();
		
	//ALT
	//Ware w1 = Ware(1,(WarenNameHinzuEdit -> text()).toStdString(),"WarenGruppe",0);

	/*Ware w1 = Ware(
	1,
	(WarenNameHinzuEdit -> text()).toStdString(),
	(WarenGruppeEdit -> text()).toStdString(),
	(Preis2Edit -> text()).toDouble()
	);*/
	
	
	
	//ALT
	//new QListWidgetItem(QString::fromStdString( w1.getWarenName() ), WarenList);
	
	
	//std::cout << w1.getWarenName() << std::endl;//debugging
	//std::cout << w1.getWarenGruppeName() << std::endl;//debugging
	//std::cout << w1.getPreisProGewicht() << std::endl;//debugging
	
	
	//std::cout << "" << std::endl;//debugging
	//std::cout << "Laegne der Liste" << std::endl;//debugging
	//std::cout << warenVector.size() << std::endl;//debugging
	}
	
	
	/*void Oberflache::WareZuBestellListe(){
		bestelltWarenVector.push_back(warenVector[WarenList->currentRow()]);
		vector<string> vecStr;
		string str;
		
		
		
		
		for(unsigned i1 = 0;i1<bestelltWarenVector.size();++i1){
			//itoa(bestelltWarenVector[i1].getMenge(),menge,10); 
			//itoa(bestelltWarenVector[i1].getPreis(),preis,10); 
			
			
			std::stringstream mengess;
			mengess<<bestelltWarenVector[i1].getMenge();
			std::string menge = mengess.str();
			
			std::stringstream preisss;
			preisss<<bestelltWarenVector[i1].getPreis();
			std::string preis = preisss.str();
			
			if(str.find(bestelltWarenVector[i1].getWarenGruppeName() + " " + bestelltWarenVector[i1].getWarenName() + " Menge:" + menge + " Preis:" + preis) == string::npos){
				//vector zum sortieren
				vecStr.push_back(bestelltWarenVector[i1].getWarenGruppeName() + " " + bestelltWarenVector[i1].getWarenName() + " Menge:" + menge + " Preis:" + preis);	
			}
		}
		
		std::sort(vecStr.begin(), vecStr.end());
		
		//vector in string geschrieben
		EinkaufswagenListe -> clear();
		for(unsigned i2 = 0;i2<vecStr.size();++i2){
					
					new QListWidgetItem(QString::fromStdString( vecStr[i2] ), EinkaufswagenListe);
					
					
					str += vecStr[i2];
					str += "\n";
				}
		
		std::cout << str << std::endl;
	
	}*/
	
	void Oberflache::beenden(){
		 qApp->quit();
	}
	
	void Oberflache::versendeEmail(){
		std::cout << "versendeEmail" << std::endl;//debugging
	//JÖRG!!!!
	//hier soll die email generiert werden und dann mit einem EmailProgramm(Thunderbird) verschickt werden
	}
	
	void Oberflache::generiereWarenGruppe(){
		Warengruppe wp = Warengruppe(WarenGruppeHinzuEdit -> text().toStdString(),WarenGruppeInfoEdit -> toPlainText().toStdString());
		
		warenGruppeVector.push_back(wp);
		
		vector<string> v;
		
		for(unsigned i1 = 0;i1<warenGruppeVector.size();++i1){
		string s = warenGruppeVector[i1].getWarenGruppeName();
		v.push_back(s);
		}
		
		std::sort(v.begin(), v.end());
	
		//for(unsigned i2 = 0;i2<v.size();++i2){
		//	WarenGruppeCB -> addItem(QString::fromStdString( v[i2] ));
		//}
		this -> aktualisiereOberflaeche();
	}
	
	void Oberflache::aktualisiereOberflaeche(){	
		
		
		
			WareEntfCB -> clear();
			WarenGruppeCB -> clear();
			WarenGruppeEntfCB -> clear();
			WarenTW -> setRowCount(0);
			
		//befüllt combo box um waren zu löschen
			for(unsigned i1 = 0;i1<warenNameVector.size();++i1){
				WareEntfCB -> addItem(QString::fromStdString(warenNameVector[i1]));
			}
		//befüllt combo box um warengruppen zu löschen
			for(unsigned i2 = 0;i2<warenGruppeVector.size();++i2){
				WarenGruppeEntfCB -> addItem(QString::fromStdString(warenGruppeVector[i2].getWarenGruppeName()));
				WarenGruppeCB -> addItem(QString::fromStdString(warenGruppeVector[i2].getWarenGruppeName()));
			}
		//befüllt Haupttabelle
			for(unsigned i3 = 0;i3<warenVector.size();++i3){
				WarenTW->insertRow( WarenTW->rowCount() );
					
				std::cout << warenVector[i3].getWarenName() << std::endl;
					
				float gpreisd = 0;
				
				gpreisd = (warenVector[i3].getPreisProGewicht() * warenVector[i3].getMengeInGewicht()) + (warenVector[i3].getPreisProStueck() * warenVector[i3].getMengeInStueck());
				
				
				std::stringstream ppgss;
				ppgss<<(warenVector[i3].getPreisProGewicht());
				std::string ppg = ppgss.str();
				
				std::stringstream ppsss;
				ppsss<<(warenVector[i3].getPreisProStueck());
				std::string pps = ppsss.str();
				
				std::stringstream migss;
				migss<<(warenVector[i3].getMengeInGewicht());
				std::string mig = migss.str();
				
				std::stringstream misss;
				misss<<(warenVector[i3].getMengeInStueck());
				std::string mis = misss.str();
				
				std::stringstream gpreisss;
				gpreisss<<(gpreisd);
				std::string gpreiss = gpreisss.str();
				
				WarenTW->setItem(i3, 1, new QTableWidgetItem(QString::fromStdString(warenVector[i3].getWarenName())));
				WarenTW->setItem(i3, 0, new QTableWidgetItem(QString::fromStdString(warenVector[i3].getWarenGruppeName())));
				WarenTW->setItem(i3, 2, new QTableWidgetItem(QString::fromStdString(ppg)));
				WarenTW->setItem(i3, 3, new QTableWidgetItem(QString::fromStdString(pps)));
				WarenTW->setItem(i3, 4, new QTableWidgetItem(QString::fromStdString(mig)));
				WarenTW->setItem(i3, 5, new QTableWidgetItem(QString::fromStdString(mis)));
				WarenTW->setItem(i3, 6, new QTableWidgetItem(QString::fromStdString(gpreiss)));
			
				Qt::ItemFlags flags;
			
				flags = WarenTW->item(i3, 0)->flags();
				flags |= Qt::ItemIsSelectable;
				flags &= ~Qt::ItemIsEditable; 
				WarenTW->item(i3, 0)->setFlags(flags);
				
				flags = WarenTW->item(i3, 1)->flags();
				flags |= Qt::ItemIsSelectable;
				flags &= ~Qt::ItemIsEditable; 
				WarenTW->item(i3, 1)->setFlags(flags);
				
				
			}
	}
	
	void Oberflache::entferneWare(){
		string s = 	WareEntfCB -> currentText().toStdString();
		
		std::cout << s << std::endl;
	
		for(unsigned i1 = 0;i1<warenVector.size();++i1){
			//if(strcmp(warenVector[i1].getWarenName() + " " + warenVector[i1].getWarenGruppeName(),s) == 0){
				
				//std::cout << warenVector[i1].getWarenGruppeName() + " " + warenVector[i1].getWarenName() << std::endl;
				
			if( (warenVector[i1].getWarenGruppeName()+ " " + warenVector[i1].getWarenName() ).compare(s) == 0){
				warenVector.erase(warenVector.begin()+ i1 );
				break;
			}
		}
		for(unsigned i2 = 0;i2<warenNameVector.size();++i2){
			std::cout << warenNameVector[i2] << std::endl;
			if(warenNameVector[i2].compare(s) == 0){
				warenNameVector.erase(warenNameVector.begin() + i2 );
				break;
			}
		}
		this -> aktualisiereOberflaeche();
		
	}
	
	void Oberflache::zelleaktualisiert(QTableWidgetItem* x){
		disconnect(WarenTW, 0, 0, 0);
		
		  switch ( x -> column() ) { 
			  
				case 0:  
					warenVector[x -> row()].setWarenGruppeName(x -> text().toStdString());
					break;
				case 1:
					warenVector[x -> row()].setWarenName(x -> text().toStdString());
					break;   
				case 2:
					warenVector[x -> row()].setPreisProGewicht(x -> text().toFloat());
					break;
				case 3:
					warenVector[x -> row()].setPreisProStueck(x -> text().toFloat());
					break;
				case 4:
					warenVector[x -> row()].setMengeInGewicht(x -> text().toFloat());
					break;
				case 5:
					warenVector[x -> row()].setMengeInStueck(x -> text().toFloat());
					break;
				case 6:
					warenVector[x -> row()].setKommentar(x -> text().toStdString());
					break;
			}		
	
	  
		
		
		this -> aktualisiereOberflaeche();
		
		connect(WarenTW, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(zelleaktualisiert(QTableWidgetItem*)));
	}
	
	//ALT
	/*void Oberflache::anzeigenWareEigenschaft(){
	//zeigt preis und Menge auf Oberfläche an
		MengenEdit -> clear();
		PreisEdit -> clear();
	
		MengenEdit -> insert(QString::number(warenVector[WarenList->currentRow()].getMenge()));
		PreisEdit -> insert(QString::number(warenVector[WarenList->currentRow()].getPreis()));
	}*/