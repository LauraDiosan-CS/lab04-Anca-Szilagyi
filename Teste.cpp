#include "Teste.h"
#include "Aplicatie.h"
#include "assert.h"
#include "RepositorySTL.h"
#include "Service.h"
#include <iostream>
#include <iterator>
#include <list>
#include<stdio.h>
using namespace std;

void appTests() {
	Aplicatie app("GheorgheVasile", "BC95SAS", "ocupat");
	Aplicatie app5("AncaSzilagyi", "BC12ASZ", "liber");
	assert((app == app5)==0);

	assert(strcmp(app.getNume(),"GheorgheVasile")==0);
	assert(strcmp(app.getNrInmatriculare(), "BC95SAS") == 0);
	assert(strcmp(app.getStatus(), "ocupat") == 0);

	char* newName = new char[14];

	strcpy_s(newName, 14, "MariaPopovici");
	app.setNume(newName);
	assert(strcmp(app.getNume(),"MariaPopovici")==0);
}

void repositorySTLTests() {
	Aplicatie app1("GheorgheVasile", "BC95SAS", "ocupat");
	Aplicatie app2("MirceaConstantin", "B89RTR", "liber");
	Aplicatie app3("AlinIonescu", "CJ56OOP", "ocupat");
	Aplicatie app4("CiprianPop", "BC12AAS", "liber");

	RepositorySTL repo;

	repo.addElem(app1);
	assert(repo.dim() == 1);
	repo.addElem(app2);
	repo.addElem(app3);
	repo.addElem(app4);
	assert(repo.dim() == 4);

	list<Aplicatie> elem;
	elem = repo.getAll();
	assert(elem.front() == app1);
	assert(elem.back() == app4);
	assert(strcmp(repo.get(elem, 1).getNume(), "MirceaConstantin") == 0);
	assert(strcmp(repo.get(elem, 2).getNume(), "AlinIonescu") == 0);
	assert(strcmp(repo.get(elem, 3).getNrInmatriculare(), "BC12AAS") == 0);

	assert(repo.get(elem, 2) == app3);

	Aplicatie app10("DragosPatraru", "B05DPR", "liber");
	assert(repo.findElem(app2) == 1);
	assert(repo.findElem(app10) == 0);

	repo.updateElem(app1, "DragosPopescu", "B65KJJ", "OCUPAT");
	//assert(strcmp(app1.getNume(), "DragosPopescu") == 0);
	//cout << app1.getNume() << endl;

//sa vedem care e treaba cu update-ul!!!

	//assert(strcmp(app1.getNume(), "DragosPatraru") == 0);
}

void serviceTests() {
	Aplicatie app21("Ancaaa1", "BC95SAS", "ocupat");
	Aplicatie app22("MirceaConstantin", "B89RTR", "liber");
	Aplicatie app23("AlinIonescu", "CJ56OOP", "ocupat");
	Aplicatie app24("CiprianPop", "BC12AAS", "liber");

	Service service;
	assert(service.dim() == 0);
	int ok = 0;
	ok=service.addElem(app21);
	ok=service.addElem(app22);
	ok=service.addElem(app23);
	ok=service.addElem(app24);

	assert(service.dim() == 4);
	assert(service.getAll().back() == app24);

	service.delElem(app23);
	assert(service.dim() == 3);
	assert(service.getItemFromPos(2) == app24);
	service.updateElem(app24, "AncaSzilagyi", "BC12ASZ", "liber");
	assert(strcmp(service.getItemFromPos(2).getNume(), "AncaSzilagyi") == 0);
}
