#include "Gadget.h"
#include <algorithm>
#include<string.h>

Gadget::Gadget()
{
	numeProd = NULL;
	model = NULL;
	unitatiProduse = 0;
}

Gadget::Gadget(const char* nume, const char* mod, int unitati){
	numeProd = nume;
	model = mod;
	unitatiProduse = unitati;
}

Gadget::Gadget(Gadget& g){
	numeProd = g.numeProd;
	model = g.model;
	unitatiProduse = g.unitatiProduse;
}

Gadget::~Gadget() {}

const char* Gadget::getNumeProducator(){
	return numeProd;
}

const char* Gadget::getNumeModel(){
	return model;
}

int Gadget::getUnitati(){
	return unitatiProduse;
}

void Gadget::setNumarProducator(const char* n){
	numeProd = n;
}

void Gadget::setNumeModel(const char* m){
	model = m;
}

void Gadget::setUnitati(int u){
	unitatiProduse = u;
}

bool Gadget::operator==(const Gadget& g)
{
	return (strcmp(numeProd, g.numeProd) == 0) and (strcmp(model, g.model) == 0) and (unitatiProduse == g.unitatiProduse);
}


Gadget& Gadget::operator=(const Gadget& g)
{
	if (this != &g) {
		model = g.numeProd;
		model = g.model;
		unitatiProduse = g.unitatiProduse;
	}
	return *this;
}



