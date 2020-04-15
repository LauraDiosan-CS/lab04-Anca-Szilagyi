/*#include "Gadget.h"
#include <string.h>
#include <sstream>
using namespace std;

Gadget::Gadget() {
	numeProducator = NULL;
	numeModel = NULL;
	unitatiProduse = 0;
}

Gadget::Gadget(const char* numeProducator, const char* numeModel, int unitatiProduse) {
	this->numeProducator = new char[strlen(numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(numeProducator) + 1, numeProducator);
	this->numeModel = new char[strlen(numeModel) + 1];
	strcpy_s(this->numeModel, strlen(numeModel) + 1, numeModel);
	this->unitatiProduse = unitatiProduse;
}

Gadget::Gadget(const Gadget& s) {
	this->numeProducator = new char[strlen(s.numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(s.numeProducator) + 1, s.numeProducator);
	this->numeModel = new char[strlen(s.numeModel) + 1];
	strcpy_s(this->numeModel, strlen(s.numeModel) + 1, s.numeModel);
	this->unitatiProduse = s.unitatiProduse;
}


int Gadget::getUnitatiProduse() {
	return unitatiProduse;
}

void Gadget::setUnitatiProduse(int v) {
	unitatiProduse = v;
}

char* Gadget::getNumeProducator() {
	return numeProducator;
}


void Gadget::setNumeProducator(const char* n) {
	if (numeProducator) delete[]numeProducator;
	numeProducator = new char[strlen(n) + 1];
	strcpy_s(numeProducator, strlen(n) + 1, n);
}

char* Gadget::getNumeModel() {
	return numeModel;
}


void Gadget::setNumeModel(const char* n) {
	if (numeModel) delete[]numeModel;
	numeModel = new char[strlen(n) + 1];
	strcpy_s(numeModel, strlen(n) + 1, n);
}

Gadget::~Gadget() {
	if (numeProducator) {
		delete[]numeProducator;
		detele[] numeModel;
	}
	numeModel = NULL;
	numeProducator = NULL;
	unitatiProduse = -1;
}

Gadget& Gadget::operator=(const Gadget& s) {
	if (this == &s) return *this; //self-assignment 

	if (numeProducator) delete[] numeProducator;
	numeProducator = new char[strlen(s.numeProducator) + 1];
	strcpy_s(numeProducator, strlen(s.numeProducator) + 1, s.numeProducator);

	if (numeModel) delete[] numeModel;
	numeModel = new char[strlen(s.numeModel) + 1];
	strcpy_s(numeModel, strlen(s.numeModel) + 1, s.numeModel);
	unitatiProduse = s.unitatiProduse;
	return *this;
}

bool Gadget::operator==(const Gadget& s) {
	return (strcmp(numeProducator, s.numeProducator) == 0) and (strcmp(numeModel, s.numeModel)==0) and (unitatiProduse == s.unitatiProduse);
}

bool Gadget::operator<(const Gadget& s)
{
	return (strcmp(numeProducator, s.numeProducator) < 0);

}

//ostream& operator<<(ostream& os, Gadget s) {
//	os << s.numeProducator << " " << s.unitatiProduse << endl;
//	return os;
//}

//istream & operator>>(istream &is, Gadget &s)
//{
//	cout << "Dati numele: ";
//	char* numeProducator = new char[10];
//	is >> numeProducator;
//	cout << "Dati unitatiProduse: ";
//	int v;
//	is >> v;
//	s.setNume(numeProducator);
//	s.setUnitatiProduse(v);
//	delete[] numeProducator;
//	return is;
//*/
