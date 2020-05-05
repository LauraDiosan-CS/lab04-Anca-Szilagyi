#include "RepoFile.h"
#include "RepoCSV.h"
#include "RepoHTML.h"
#include "Gadget.h"
#include "Telefon.h"
#include "Drona.h"
#include "Service.h"
#include<assert.h>

void addElemGadget() {

	RepoCSV<Gadget> r("TesteCSV.CSV");
	assert(r.getSize() == 0);
	Gadget c("Apple", "Iphone8", 450);
	r.addElem(c);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
}

void deleteElemGadget() {

	RepoHTML<Gadget> r("TesteHTML.html");
	// TEST FISIER HTML
	assert(r.getSize() == 0);
	Gadget c("Apple", "Iphone8", 450);
	r.addElem(c);
	assert(r.getSize() == 1);
	r.delElem(0);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 0);
	r.clearFile("TesteHMTL.html");
}
void updateElemGadget() {

	RepoHTML<Gadget> r("TesteHTML.html");
	assert(r.getSize() == 0);
	Gadget c("Apple", "Iphone8", 450);
	r.addElem(c);
	assert(r.getSize() == 1);
	Gadget c1("Samsung", "Iphone8", 400);
	r.updateElem(0, c1);
	r.loadFromFile("TesteHtml.html");
	map<int, Gadget> elemente;
	elemente = r.getAll();
	map<int, Gadget> ::iterator itr = elemente.find(0);
	assert(strcmp((itr->second).getProducator(), "Samsung") == 0);
	r.clearFile("TesteHTML.html");
	elemente.clear();
}
void getAllGadget() {
	RepoCSV<Gadget> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	Gadget c("Apple", "Iphone8", 450);
	r.addElem(c);
	Gadget c1("Ionut", "IPhoneX200", 133);
	r.addElem(c1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Gadget> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	assert(elemente[0] == c && elemente[1] == c1);
	r.clearFile("TesteCSV.csv");
	elemente.clear();
}
void addElemDrona() {
	RepoCSV<Drona> r("TesteCSV.csv");
	assert(r.getSize() == 0);

	Drona m("Apple", "Iphone8", 450, 5);
	r.addElem(m);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");


}
void deleteElemDrona() {

	RepoHTML<Drona> r("TesteHTML.html");
	assert(r.getSize() == 0);

	Drona m("Apple", "Iphone8", 450, 9);
	r.addElem(m);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 1);
	r.delElem(0);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 0);
	r.clearFile("TesteHTML.html");


}
void updateElemDrona() {
	RepoHTML<Drona> r("TesteHTML.html");
	assert(r.getSize() == 0);

	Drona m("Apple", "Iphone8", 145, 8);
	r.addElem(m);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 1);

	Drona m1("Samsung", "Strada Pacurari", 123, 9);
	r.updateElem(0, m1);
	r.loadFromFile("TesteHTML.html");
	map<int, Drona> elemente;
	elemente = r.getAll();
	assert(strcmp(elemente[0].getProducator(), "Samsung") == 0);
	r.clearFile("TesteHTML.html");

	elemente.clear();
}
void getAllDrona() {

	RepoCSV<Drona> r("TesteCSV.csv");
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 0);

	Drona m("Apple", "Iphone8", 450, 6);
	r.addElem(m);

	Drona m1("Ionut", "IPhoneX200", 133, 7);
	r.addElem(m1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Drona> elemente;
	elemente = r.getAll();

	assert(r.getSize() == 2);
	assert(elemente[0] == m && elemente[1] == m1);
	r.clearFile("TesteCSV.csv");

	elemente.clear();
}
void addElemTelefon() {

	RepoCSV<Telefon> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Orange6.7");
	lista.push_back("Orange3");
	lista.push_back("Orange8");
	Telefon s("Apple", "Iphone8", 450, lista);
	r.addElem(s);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
	lista.clear();
}
void deleteElemTelefon() {

	RepoCSV<Telefon> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Orange6.7");
	lista.push_back("Orange3");
	lista.push_back("Orange8");
	Telefon s("Apple", "Iphone8", 450, lista);
	r.addElem(s);
	assert(r.getSize() == 1);
	r.delElem(0);
	assert(r.getSize() == 0);
	r.clearFile("TesteCSV.csv");
	lista.clear();
}
void updateElemTelefon() {

	RepoCSV<Telefon> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Orange6.7");
	lista.push_back("Orange3");
	lista.push_back("Orange8");
	Telefon s("Apple", "Iphone8", 145, lista);
	r.addElem(s);
	assert(r.getSize() == 1);
	Telefon s1("Ionut", "Strada Pacurari", 133, lista);
	r.updateElem(0, s1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Telefon> elem;
	elem = r.getAll();
	assert(strcmp(elem[0].getProducator(), "Ionut") == 0 && elem[0].getUnitati() == 133);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	elem.clear();
}
void getAllTelefon() {

	RepoCSV<Telefon> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Orange6.7");
	lista.push_back("Vod");
	lista.push_back("Vodafone8");
	Telefon s("Apple", "Iphone8", 145, lista);
	r.addElem(s);
	vector<string>lista1;
	lista1.push_back("Vodafone4");
	lista1.push_back("Orange33");
	Telefon s1("Ionut", "IPhoneX200", 133, lista1);
	r.addElem(s1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Telefon> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	lista1.clear();
	elemente.clear();
}