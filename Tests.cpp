

#include "Tests.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
using namespace std;
Tests::Tests() {
}

void Tests::testDomain() {
	/*Gadget e1("AncaSzilagyi", "Xiaomi", 5);
	Gadget e2(e1);
	Gadget e3;
	assert(e3.getNumeProducator() == NULL);
	assert(e3.getNumeModel() == NULL);
	e3 = e2;
	assert(strcmp(e3.getNumeProducator(), "AncaSzilagyi") == 0);
	assert(strcmp(e2.getNumeProducator(), "AncaSzilagyi") == 0);
	//assert(e1 == e2);
	e2.setNumeModel("Xiaomi");
	assert(strcmp(e2.getNumeModel(), "Xiaomi") == 0);*/


	Telefon* t = new Telefon();
	*t = Telefon();
	assert(t->getUnitati() == 0);

	Telefon* t1 = new Telefon("Samsung", "galaxy", 23, "operator");
	assert(t1->getUnitati() == 23);
	assert(t1->getNumeProducator() == "Samsung");
	t1->setNumeModel("note 7");
	assert(t1->getNumeModel() == "note 7");

	cout << "Testele pt Telefon functioneaza" << endl;
	Drona d1("Apple", "IDron3", 5, 8);
	d1.setNrRotoare(7);
	assert(d1.getNrRotoare() == 7);
	Drona* d = new Drona();
	*d = Drona();
	assert(d->getUnitati() == 0);
	Drona* d2 = new Drona("Firma", "asdf45", 20, 3);
	assert(d2->getUnitati() == 20);
	assert(d2->getNumeProducator() == "Firma");
	d2->setNrRotoare(6);
	assert(d2->getNrRotoare() == 6);


	cout << "testele pentru Drona functioneaza" << endl;
}

/*void Tests::testRepositoryTemplate() {
	Gadget e1("Ciprian", "BCDTTT", 5);
	Gadget e2("BogdanPop", "RETH", 7);
	Gadget e3("Cristiana", "bc12uui", 3);
	Gadget e4("DianaHum", "VSS45", 8);
	RepositoryTemplate<Gadget> repoGadget;
	repoGadget.addElem(e1);
	repoGadget.addElem(e2);
	repoGadget.addElem(e3);
	repoGadget.addElem(e4);
	assert(repoGadget.getSize() == 4);
	//assert(repoGadget.getAll().front() == e1);
	//assert(repoGadget.getAll().back() == e4);
	//assert(repoGadget.getItemFromPos(0) == e1);



	Gadget e0("Elizaaa", "MS 77 SSA", 5);
	Gadget e01("BogdanPop", "Ciprian", 3);
	assert(repoGadget.findElem(e4) == 3);
	assert(repoGadget.findElem(e0) == -1);
	repoGadget.deleteElem(e3);
	//assert(repoGadget.findElem(e3) == -1);
	//assert(repoGadget.getSize() == 3);
	//Gadget e("BogdanPop", "Ciprian", 9);
	//repoGadget.updateElem(e1, e);
	//assert(repoGadget.getItemFromPos(0) == e01);
}*/

Tests::~Tests() {
}