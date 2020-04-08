#include "Service.h"
#include <stdio.h>
#include<iostream>
#include <list>

using namespace std;

Service::Service()
{
}

int Service::addElem(Aplicatie s) {
	if (depozit.dim() == 0) {
		//depozit.addElem(s);
		if (strcmp(s.getStatus(), "liber") == 0) {
			depozit.addElem(s);
			return 1;
		}
		else if (strcmp(s.getStatus(), "ocupat") == 0) {
			depozit.addElem(s);
			return 1;
		}
		else return 0;
	}
	for (int i = 0; i < depozit.dim(); i++)
		if (strcmp(depozit.getItemFromPos(i).getNrInmatriculare(), s.getNrInmatriculare())==0) return 0;
	if (strcmp(s.getStatus(), "liber") == 0) {
		depozit.addElem(s);
		return 1;
	}
	if (strcmp(s.getStatus(), "ocupat") == 0) {
		depozit.addElem(s);
		return 1;
	}

	return 0;
}

list<Aplicatie> Service::getAll() {
	return depozit.getAll();
}

int Service::dim() {
	return depozit.dim();
}

Aplicatie Service::get(list<Aplicatie> elem, int _i) {
	return depozit.get(elem, _i);
}


void Service::delElem(Aplicatie app) {
	depozit.delElem(app);

}

void Service::updateElem(Aplicatie app, const char* numeNou, const char* numarNou, const char* statusNou) {
	depozit.updateElem(app, numeNou, numarNou, statusNou);
}

bool Service::findElem(Aplicatie s) {
	return depozit.findElem(s);
}

Aplicatie Service::getItemFromPos(int i) {
	return depozit.getItemFromPos(i);
}


Service::~Service()
{}



