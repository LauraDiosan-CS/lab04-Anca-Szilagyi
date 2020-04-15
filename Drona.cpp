#include "Drona.h"
Drona::Drona() {
	this->numeProducator = NULL;
	this->numeModel = NULL;
	this->numarRotoare = 0;
	this->unitatiProduse = 0;
}
void Drona::setNumarRotoare(int number) {
	numarRotoare = number;
}
Drona::Drona(const char* numeProducator, const char* model, int unitati, int nr) :Gadget(numeProducator, model, unitati)
{
	numarRotoare = nr;
}
int Drona::getNumarRotoare() {
	return numarRotoare;
}
Drona::~Drona() {

}