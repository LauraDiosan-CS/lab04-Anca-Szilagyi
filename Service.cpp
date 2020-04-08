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

int Service::capacitate() {
	int cap = 0;
	if (depozit.dim() == 0) return 0;
	for (int i = 0; i < depozit.dim(); i++) 
		if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0) cap++;
	return cap;
}

int Service::areLoc() {
	int masiniInParcare = capacitate();
	if (masiniInParcare < depozit.getCapacitateMaxima()) return 1;
	return 0;
}

void Service::setCapacitateMaxima(int number) {
	depozit.setCapacitateMaxima(number);
}
int Service::getCapMax() {
	return depozit.getCapacitateMaxima();
}

int Service::intrare(const char* numarInmatriculare) {
	int ok = 0;
	for (int i = 0; i < depozit.dim(); i++) 
		if (strcmp(getItemFromPos(i).getNrInmatriculare(), numarInmatriculare) == 0) {
			if (strcmp(getItemFromPos(i).getStatus(), "liber") == 0) {
				updateElem(getItemFromPos(i), getItemFromPos(i).getNume(), numarInmatriculare, "ocupat");
				ok = 1;
			}
			else ok = 0;
		}	
	return ok;
}

Service::~Service()
{}



