#pragma once
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include<sstream>
class Gadget {
protected:
	char* numeProducator;
	char* numeModel;
	int unitatiProduse;
public:
	Gadget();
	Gadget(const char* numeProducator, const char* numeModel, int unitatiProduse);
	Gadget(const Gadget& c);
	virtual ~Gadget();
	bool operator==(const Gadget& s);
	virtual char* getNumeProducator();
	virtual char* getNumeModel();
	virtual int getUnitatiProduse();
	virtual void setNumeProducator(const char* numeProducator);
	virtual void setNumeModel(const char* numeModel);
	virtual void setUnitatiProduse(int unitatiProduse);
	Gadget& operator=(const Gadget& c);
};
Gadget::Gadget() {
	//cout << "const implicit";
	this->numeProducator = NULL;
	this->numeModel = NULL;
	this->unitatiProduse = 0;

}
Gadget::Gadget(const char* numeProducator, const  char* numeModel, int unitatiProduse) {
	//cout << "constructor with param" << endl;
	this->numeProducator = new char[strlen(numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(numeProducator) + 1, numeProducator);

	this->numeModel = new char[strlen(numeModel) + 1];
	strcpy_s(this->numeModel, strlen(numeModel) + 1, numeModel);

	this->unitatiProduse = unitatiProduse;
}
Gadget::Gadget(const Gadget& c) {
	//cout << "copy constructor" << endl;
	this->numeProducator = new char[strlen(c.numeProducator) + 1];
	strcpy_s(this->numeProducator, strlen(c.numeProducator) + 1, c.numeProducator);
	this->numeModel = new char[strlen(c.numeModel) + 1];
	strcpy_s(this->numeModel, strlen(c.numeModel) + 1, c.numeModel);
	this->unitatiProduse = c.unitatiProduse;

}
Gadget::~Gadget() {
	//cout << "Destructor";
	if (this->numeProducator) {
		delete[] this->numeProducator;
		this->numeProducator = NULL;
	}
	if (this->numeModel) {
		delete[] this->numeModel;
		this->numeModel = NULL;
	}
	this->unitatiProduse = 0;

}
char* Gadget::getNumeProducator() {
	return this->numeProducator;
}

char* Gadget::getNumeModel() {
	return this->numeModel;
}
int Gadget::getUnitatiProduse() {
	return this->unitatiProduse;
}
void Gadget::setNumeProducator(const char* numeProducator) {
	if (this->numeProducator) {
		delete[] this->numeProducator;
	}
	this->numeProducator = new char[strlen(numeProducator) + 1];

	strcpy_s(this->numeProducator, strlen(numeProducator) + 1, numeProducator);
}
void Gadget::setNumeModel(const char* numeModel) {

	if (this->numeModel) {
		delete[] this->numeModel;
	}
	this->numeModel = new char[strlen(numeModel) + 1];

	strcpy_s(this->numeModel, strlen(numeModel) + 1, numeModel);
}
void Gadget::setUnitatiProduse(int unitatiProduse) {
	this->unitatiProduse = unitatiProduse;
}
bool Gadget::operator==(const Gadget& s) {
	return (strcmp(numeProducator, s.numeProducator) == 0) and (strcmp(numeModel, s.numeModel) == 0) and (unitatiProduse == s.unitatiProduse);
}

Gadget& Gadget::operator=(const Gadget& c) {
	this->setNumeProducator(c.numeProducator);
	this->setNumeModel(c.numeModel);
	this->setUnitatiProduse(c.unitatiProduse);
	return *this;
}
