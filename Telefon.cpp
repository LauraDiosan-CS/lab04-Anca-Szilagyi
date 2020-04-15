#include "Telefon.h"
Telefon::Telefon() {
	this->numeProducator = NULL;
	this->numeModel = NULL;
	this->listaOperatoriGSMCompatibili = NULL;
	this->unitatiProduse = 0;
}
Telefon::~Telefon() {

}



/*#include "Telefon.h"
#include <iomanip>
#include <algorithm>

using namespace std;



Telefon::Telefon()
{
}

Telefon::Telefon(const char* numeProducator, const char* model, const char* unitati, char operatori) :Gadget(numeProducator, model, unitati)
{
	listaOperatoriGSMCompatibili = operatori;
}

Telefon::Telefon(const Telefon& phone) : Gadget(phone)
{
	listaOperatoriGSMCompatibili = phone.listaOperatoriGSMCompatibili;
}


Telefon::~Telefon()
{
}

char Telefon::getlistaOperatoriGSMCompatibili()
{
	return listaOperatoriGSMCompatibili;
}

void Telefon::setlistaOperatoriGSMCompatibili(char ib)
{
	listaOperatoriGSMCompatibili = ib;
}

Telefon& Telefon::operator=(const Telefon& phone)
{
	this->Gadget::operator=(phone);
	this->listaOperatoriGSMCompatibili = phone.listaOperatoriGSMCompatibili;
	return *this;
}

bool Telefon::operator==(const Telefon& s)
{
	return (Gadget::operator==(s) && (listaOperatoriGSMCompatibili == s.listaOperatoriGSMCompatibili));
}

istream& operator>>(istream& is, Telefon& phone) {
	cout << "Dati numele: ";
	char* numeProducator = new char[10];
	is >> numeProducator;
	cout << "Dati unitatiProduse: ";
	int v;
	is >> v;
	cout << "Dati listaOperatoriGSMCompatibili:";
	char iban;
	is >> iban;
	phone.setNumeProducator(numeProducator);
	phone.setUnitatiProduse(v);
	phone.setlistaOperatoriGSMCompatibili(iban);
	delete[] numeProducator;
	return is;
}


ostream& operator<<(ostream& os, Telefon& phone) {
	os << "|-----------------------------|" << endl;
	std::transform(phone.listaOperatoriGSMCompatibili.begin(), phone.listaOperatoriGSMCompatibili.end(), phone.listaOperatoriGSMCompatibili.begin(), ::toupper);
	os << "|" << std::left << setw(10) << setfill(' ') << phone.numeProducator << "|" << setw(4) << phone.unitatiProduse << "|" << setw(15) << setfill(' ') << phone.listaOperatoriGSMCompatibili << "|" << endl;
	//os << "| ----------------------------|" << endl;
	return os;
}*/