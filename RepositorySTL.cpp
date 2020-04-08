#include "RepositorySTL.h"
#include <stdio.h>
#include<iostream>
using namespace std;

RepositorySTL::RepositorySTL()
{
}

void RepositorySTL::addElem(Aplicatie s) {
	//int ok = 1;
	//for (int i = 0; i < elem.size(); i++) 
		//if (strcmp(s.getNume(), elem[i].getNume()) == 0) ok = 0;
	elem.push_back(s);
	//aici de adaugat o eroare daca nu se adauga in lista.
	//va adauga la sf vectorului, elementul s;
}

list<Aplicatie> RepositorySTL::getAll() {
		return elem;
	}
int RepositorySTL::dim() {
		return elem.size();
	}

Aplicatie RepositorySTL::get(list<Aplicatie> elem, int _i) {
	list<Aplicatie>::iterator it = elem.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}

void RepositorySTL::delElem(Aplicatie app) {
	list<Aplicatie>::iterator it;
	//imi permite sa decuplez felul in care se parcurge o struct de date
	it = find(elem.begin(), elem.end(), app);
	//de la inceput pana la sfarsit il caut pe app
	//it va fi pozitia lui app daca exista. altfel - NULL.
	if (it != elem.end()) elem.erase(it);
	//daca il gasesc, il sterg
}

void RepositorySTL::updateElem(Aplicatie app, const char* numeNou, const char* numarNou, const char* statusNou) {
	list<Aplicatie>::iterator it;
	it = find(elem.begin(), elem.end(), app);
	if (it != elem.end()) {
		it->setNume(numeNou);
		it->setNrInmatriculare(numarNou);
		it->setStatus(statusNou);
	}
	
	/*int i = findElem(app);
	if (i != -1) {
		list<Aplicatie>::iterator it = next(elem.begin(), i);
		it->setNume(numeNou);
		it->setNrInmatriculare(numarNou);
		it->setStatus(statusNou);
	}*/
}

bool RepositorySTL::findElem(Aplicatie s) {
	list<Aplicatie>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) return true;
	return false;
}

Aplicatie RepositorySTL::getItemFromPos(int i) {
	return get(elem, i);
}


RepositorySTL::~RepositorySTL()
{}



