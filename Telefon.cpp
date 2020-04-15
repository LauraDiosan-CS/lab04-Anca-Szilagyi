#include "Telefon.h"
#include<algorithm>
using namespace std;

Telefon::Telefon() :Gadget() {
}

Telefon::Telefon(const char* p, const char* m, int u, const char* r) : Gadget(p, m, u) {
	listaOperatoriGSMCompatibili= r;
}

Telefon::Telefon(Telefon& d) : Gadget(d) {
	listaOperatoriGSMCompatibili = d.listaOperatoriGSMCompatibili;
}

Telefon::~Telefon() {
}

const char* Telefon::getListaOperatori() {
	return listaOperatoriGSMCompatibili;
}

void Telefon::setListaOperatori(const char* r) {
	listaOperatoriGSMCompatibili = r;
}

Telefon& Telefon::operator=(const Telefon& sb)
{
	this->Gadget::operator=(sb);
	this->listaOperatoriGSMCompatibili = sb.listaOperatoriGSMCompatibili;
	return *this;
}

bool Telefon::operator==(const Telefon& s)
{
	return (Gadget::operator==(s) && (strcmp(listaOperatoriGSMCompatibili, s.listaOperatoriGSMCompatibili)==0));
}





Telefon* Telefon::clone()
{
	Telefon* newT = new Telefon();
	newT->setNumarProducator(numeProd);
	newT->setNumeModel(model);
	newT->setUnitati(unitatiProduse);
	newT->listaOperatoriGSMCompatibili = listaOperatoriGSMCompatibili;
	return newT;
}

