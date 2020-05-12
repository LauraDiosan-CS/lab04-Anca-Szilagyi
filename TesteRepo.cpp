#include "RepoFile.h"
#include "RepoCSV.h"
#include "RepoHTML.h"
#include "Gadget.h"
#include "Telefon.h"
#include "Drona.h"
#include "Service.h"
#include<assert.h>

void addElemGadget() {

	RepoCSV<Gadget&> r("TesteCSV.CSV");
	assert(r.getSize() == 0);
	Gadget* c = new Gadget("Apple2", "Iphone5 nici nu mai exista", 450);
	r.addElem(*c);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
}
void deleteElemGadget() {

	RepoHTML<Gadget&> r("TesteHTML.html");
	// TEST FISIER HTML
	assert(r.getSize() == 0);
	Gadget* c = new Gadget("Apple2", "Iphone5 nici nu mai exista", 450);
	r.addElem(*c);
	assert(r.getSize() == 1);
	r.delElem(0);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 0);
	r.clearFile("TesteHMTL.html");
}
void updateElemGadget() {

	RepoHTML<Gadget&> r("TesteHTML.html");
	assert(r.getSize() == 0);
	Gadget* c = new Gadget("Apple2", "Iphone5 nici nu mai exista", 450);
	r.addElem(*c);
	assert(r.getSize() == 1);
	Gadget* c1 = new Gadget("Apple", "Iphone5 nici nu mai exista", 400);
	r.updateElem(0, *c1);
	r.loadFromFile("TesteHtml.html");
	map<int, Gadget&> elemente;
	elemente = r.getAll();
	map<int, Gadget&> ::iterator itr = elemente.find(0);
	assert(strcmp((itr->second).getProducator(), "Apple") == 0);
	r.clearFile("TesteHTML.html");
	elemente.clear();
}
void getAllGadget() {
	RepoCSV<Gadget&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	Gadget* c = new Gadget("Apple2", "Iphone5 nici nu mai exista", 450);
	r.addElem(*c);
	Gadget* c1 = new Gadget("AppleUpgraded", "IphoneX Nr.12", 133);
	r.addElem(*c1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Gadget&> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	assert(elemente.find(0)->second == *c && (elemente.find(1)->second) == *c1);
	r.clearFile("TesteCSV.csv");
	elemente.clear();
}
void addElemDrona() {

	RepoCSV<Gadget&> r("TesteCSV.csv");
	assert(r.getSize() == 0);

	Drona* m = new Drona("Apple2", "Iphone5 nici nu mai exista", 450, 3);
	r.addElem(*m);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");

}
void deleteElemDrona() {

	RepoHTML<Gadget&> r("TesteHTML.html");
	assert(r.getSize() == 0);

	Drona* m = new Drona("Apple2", "Iphone5 nici nu mai exista", 450, 5);
	r.addElem(*m);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 1);
	r.delElem(0);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 0);
	r.clearFile("TesteHTML.html");
}
void updateElemDrona() {
	RepoHTML<Gadget&> r("TesteHTML.html");
	assert(r.getSize() == 0);

	Drona* m = new Drona("Apple2", "Iphone5 nici nu mai exista", 145, 7);
	r.addElem(*m);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 1);

	Drona* m1 = new Drona("Apple", "IphoneX", 123, 7);
	r.updateElem(0, *m1);
	r.loadFromFile("TesteHTML.html");
	map<int, Gadget&> elemente;
	elemente = r.getAll();
	Drona& ma = dynamic_cast<Drona&>(elemente.find(0)->second); // cast teste
	assert(strcmp(ma.getProducator(), "Apple") == 0);
	assert(ma.getRotoare() == 7);
	r.clearFile("TesteHTML.html");

	elemente.clear();
}
void getAllDrona() {

	RepoCSV<Gadget&> r("TesteCSV.csv");
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 0);

	Drona* m = new Drona("Apple2", "Iphone5 nici nu mai exista", 450, 7);
	r.addElem(*m);

	Drona* m1 = new Drona("AppleUpgraded", "IphoneX Nr.12", 133, 9);
	r.addElem(*m1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Gadget&> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	assert(elemente.find(0)->second == *m && elemente.find(1)->second == *m1);
	r.clearFile("TesteCSV.csv");

	elemente.clear();
}
void addElemTelefon() {

	RepoCSV<Gadget&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Orange");
	lista.push_back("Vodafone");
	lista.push_back("Cosmote");
	Telefon* s = new Telefon("Apple2", "Iphone5 nici nu mai exista", 450, lista);
	r.addElem(*s);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
	lista.clear();
}
void deleteElemTelefon() {

	RepoCSV<Gadget&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Orange");
	lista.push_back("Vodafone");
	lista.push_back("Cosmote");
	Telefon* s = new Telefon("Apple2", "Iphone5 nici nu mai exista", 450, lista);
	r.addElem(*s);
	assert(r.getSize() == 1);
	r.delElem(0);
	assert(r.getSize() == 0);
	r.clearFile("TesteCSV.csv");
	lista.clear();
}
void updateElemTelefon() {

	RepoCSV<Gadget&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Orange");
	lista.push_back("Vodafone");
	lista.push_back("Cosmote");
	Telefon* s = new Telefon("Apple2", "Iphone5 nici nu mai exista", 145, lista);
	r.addElem(*s);
	assert(r.getSize() == 1);
	Telefon* s1 = new Telefon("AppleUpgraded", "IphoneX", 133, lista);
	r.updateElem(0, *s1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Gadget&> elem;
	elem = r.getAll();
	assert(strcmp(elem.find(0)->second.getProducator(), "AppleUpgraded") == 0 && elem.find(0)->second.getUnitati() == 133);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	elem.clear();
}

void getAllTelefon() {

	RepoCSV<Gadget&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Orange");
	lista.push_back("Digi");
	lista.push_back("RDS");
	Telefon* s = new Telefon("Apple2", "Iphone5 nici nu mai exista", 145, lista);
	r.addElem(*s);
	vector<string>lista1;
	lista1.push_back("Vodf");
	lista1.push_back("Unix");
	Telefon* s1 = new Telefon("AppleUpgraded", "IphoneX Nr.12", 133, lista1);
	r.addElem(*s1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Gadget&> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	lista1.clear();
	elemente.clear();
}