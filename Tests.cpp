#include "Tests.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
using namespace std;
Tests::Tests() {
}

void Tests::testDomain() {
	Gadget e1("AncaSzilagyi", "Xiaomi", 5);
	Gadget e2(e1);
	Gadget e3;
	assert(e3.getNumeProducator() == NULL);
	assert(e3.getNumeModel() == NULL);
	e3 = e2;
	assert(strcmp(e3.getNumeProducator(), "AncaSzilagyi") == 0);
	assert(strcmp(e2.getNumeProducator(), "AncaSzilagyi") == 0);
	//assert(e1 == e2);
	e2.setNumeModel("Xiaomi");
	assert(strcmp(e2.getNumeModel(), "Xiaomi") == 0);

	Drona d1("Apple", "IDron3", 5, 8);
	d1.setNumarRotoare(7);
	assert(d1.getNumarRotoare() == 7);
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