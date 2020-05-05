#include"Telefon.h"
#include<sstream>
#include<string.h>
Telefon::Telefon() {

}
Telefon::Telefon(const char* n, const string a, int p, vector<string> l) :Gadget(n, a, p) {

	operatoriGSM = l;

}
Telefon::Telefon(const Telefon& s) : Gadget(s) {

	operatoriGSM = s.operatoriGSM;

}
Telefon::~Telefon() {
}
Telefon::Telefon(string linie, string fileName) :Gadget(linie, fileName) {

	vector<string> s = Gadget::readLineFromFile(linie, fileName);
	string tok4, tok5;
	tok4 = s[s.size() - 2];
	tok5 = s[s.size() - 1];
	vector<string> lista;
	string pars;
	stringstream iss(tok4);
	while (getline(iss, pars, ' ')) {

		lista.push_back(pars);
	}
	this->operatoriGSM = lista;

}
string Telefon::toStringCSV() {

	string outstring;
	outstring = Gadget::toStringCSV();
	vector<string>lista = this->operatoriGSM;

	outstring += ",";
	for (unsigned int i = 0; i < lista.size(); i++) {

		outstring += lista[i];
		if (i < lista.size() - 1) {

			outstring += " ";
		}
	}

	outstring += " ";

	return outstring;
}
string Telefon::toStringHTML() {

	string outstring;
	outstring = Gadget::toStringHTML();
	vector<string>lista = this->operatoriGSM;

	outstring += "/";
	for (unsigned int i = 0; i < lista.size(); i++) {

		outstring += lista[i];
		if (i < lista.size() - 1) {

			outstring += " ";
		}
	}

	outstring += " ";

	return outstring;
}

vector<string>Telefon::getOperatoriGSM() {

	return operatoriGSM;
}
void Telefon::setOperatoriGSM(vector<string> l) {

	operatoriGSM = l;
}

Telefon& Telefon::operator=(const Telefon& s) {

	this->Gadget::operator=(s);
	this->setOperatoriGSM(s.operatoriGSM);

	return *this;
}

bool Telefon::operator==(const Telefon& s) {

	return (Gadget::operator==(s) && (this->operatoriGSM == s.operatoriGSM));
}
ostream& operator<<(ostream& os, const Telefon& s) {

	os <<  s.producator << " ";
	os <<  s.model << " ";
	os <<  s.unitati << " ";
	os << " Operatori GSM: ";
	for (int i = 0; i < s.operatoriGSM.size(); i++)
		os << s.operatoriGSM[i] << " ";
	os << endl;

	return os;
}