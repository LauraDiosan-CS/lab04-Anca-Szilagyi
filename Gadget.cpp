#include"Gadget.h"
#include<sstream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include "Drona.h"
#include "Telefon.h"
Gadget::Gadget() {
	this->producator = NULL;
	this->model = "";
	this->unitati = 0;
}
Gadget::Gadget(const char* producator, string  model, int unitati) {
	this->producator = new char[strlen(producator) + 1];
	strcpy_s(this->producator, strlen(producator) + 1, producator);
	this->model = model;
	this->unitati = unitati;
}
Gadget::Gadget(const Gadget& c) {
	//cout << "copy constructor" << endl;
	this->producator = new char[strlen(c.producator) + 1];
	strcpy_s(this->producator, strlen(c.producator) + 1, c.producator);
	this->model = c.model;
	this->unitati = c.unitati;
}
Gadget::~Gadget() {
	//cout << "Destructor";
	if (this->producator) {
		delete[] this->producator;
		this->producator = NULL;
	}
	this->model = "";
	this->unitati = 0;
}
vector<string> Gadget::readLineFromFile(string linie, string fileName) {

	string parsed, parsed1;
	string tok1, tok2, tok3;
	stringstream input_stringstream(linie);
	stringstream input_stringstream1(fileName);
	vector<string> s;
	vector<string> v;
	while (getline(input_stringstream1, parsed1, '.')) {

		v.push_back(parsed1);
	}
	if (v[v.size() - 1].compare("csv") == 0) {


		while (getline(input_stringstream, parsed, ',')) {

			s.push_back(parsed);
		}
	}
	else if (v[v.size() - 1].compare("html") == 0)
		while (getline(input_stringstream, parsed, '/')) {
			s.push_back(parsed);
		}
	else
		while (getline(input_stringstream, parsed, ',')) {
			s.push_back(parsed);
		}
	v.clear();
	return s;


}
Gadget::Gadget(string linie, string fileName) {

	string tok1, tok2, tok3;
	vector<string> s;
	s = readLineFromFile(linie, fileName);
	tok1 = s[0];
	tok2 = s[1];
	tok3 = s[2];
	this->producator = new char[tok1.length() + 1];
	strcpy_s(this->producator, tok1.length() + 1, tok1.c_str());
	this->model = tok2;
	this->unitati = stoi(tok3);
	s.clear();
}
Gadget& Gadget::fromString(string linie, string fileName) {

	vector<string> s;
	s = readLineFromFile(linie, fileName);
	try {
		Drona* m = new Drona(linie, fileName);
		return *m;
	}
	catch(...) {
		Telefon* phone = new Telefon(linie, fileName);
		return *phone;
	};
}
string Gadget::toStringCSV()
{
	char* array = this->producator;
	int pret = this->unitati;
	string adresaS = this->model;
	std::string producatorS(array); // CONVERT CHAR* TO STRING
	std::string unit = std::to_string(pret);
	vector<string> atr;
	atr.push_back(producatorS);
	atr.push_back(adresaS);
	atr.push_back(unit);
	string outstring;
	for (unsigned int i = 0; i < atr.size(); i++) {

		outstring += atr[i];
		if (i < atr.size() - 1) {

			outstring += ",";
		}
	}
	return outstring;
}
string Gadget::toStringHTML()
{
	char* array = this->producator;
	int unitati = this->unitati;
	string adresaS = this->model;
	std::string producatorS(array); // CONVERT CHAR TO STRING
	std::string unit = std::to_string(unitati);
	vector<string> atr;
	atr.push_back(producatorS);
	atr.push_back(adresaS);
	atr.push_back(unit);
	string outstring;
	for (unsigned int i = 0; i < atr.size(); i++) {

		outstring += atr[i];
		if (i < atr.size() - 1) {

			outstring += "/";
		}
	}
	return outstring;


}
char* Gadget::getProducator() {
	return this->producator;
}
string Gadget::getModel() {
	return this->model;
}
int Gadget::getUnitati() {
	return this->unitati;
}
void Gadget::setProducator(const char* producator) {
	if (this->producator) {
		delete[] this->producator;
	}
	this->producator = new char[strlen(producator) + 1];

	strcpy_s(this->producator, strlen(producator) + 1, producator);
}
void Gadget::setModel(const string model) {

	this->model = model;
}
void Gadget::setUnitati(int unitati) {
	this->unitati = unitati;
}
Gadget& Gadget::operator=(const Gadget& c) {
	this->setProducator(c.producator);
	this->setModel(c.model);
	this->setUnitati(c.unitati);
	return *this;
}
bool Gadget::operator==(const Gadget& c) {
	return (strcmp(this->producator, c.producator) == 0) && (this->model.compare(c.model) == 0) && (this->unitati == c.unitati);
}
ostream& operator<<(ostream& os, const Gadget& c) {

	os << "Producator: " << c.producator << "|" << " Model: " << c.model << "|" << " Unitati: " << c.unitati;
	return os;
}
/*

#include"Gadget.h"
#include<sstream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include "Drona.h"
#include "Telefon.h"
//#include <memory>
Gadget::Gadget() {
	//cout << "const implicit";
	this->producator = NULL;
	this->model = "";
	this->unitati = 0;
}
Gadget::Gadget(const char* producator, string  model, int unitati) {
	//cout << "constructor with param" << endl;
	this->producator = new char[strlen(producator) + 1];
	strcpy_s(this->producator, strlen(producator) + 1, producator);
	this->model = model;
	this->unitati = unitati;
}
Gadget::Gadget(const Gadget& c) {
	//cout << "copy constructor" << endl;
	this->producator = new char[strlen(c.producator) + 1];
	strcpy_s(this->producator, strlen(c.producator) + 1, c.producator);
	this->model = c.model;
	this->unitati = c.unitati;
}
Gadget::~Gadget() {
	//cout << "Destructor";
	if (this->producator) {
		delete[] this->producator;
		this->producator = NULL;
	}
	this->model = "";
	this->unitati = 0;
}
vector<string> Gadget::readLineFromFile(string linie, string fileName) {

	string parsed, parsed1;
	stringstream input_stringstream(linie);
	stringstream input_stringstream1(fileName);
	vector<string> s;
	vector<string> v;
	while (getline(input_stringstream1, parsed1, '.')) {

		v.push_back(parsed1);
	}
	if (v[v.size() - 1].compare("csv") == 0) {


		while (getline(input_stringstream, parsed, ',')) {

			s.push_back(parsed);
		}
	}
	else if (v[v.size() - 1].compare("html") == 0)
		while (getline(input_stringstream, parsed, '/')) {
			s.push_back(parsed);
		}
	else
		while (getline(input_stringstream, parsed, ',')) {
			s.push_back(parsed);
		}
	v.clear();
	return s;

}
Gadget::Gadget(string linie, string fileName) {

	string tok1, tok2, tok3;
	vector<string> s;
	s = readLineFromFile(linie, fileName);
	tok1 = s[0];
	tok2 = s[1];
	tok3 = s[2];
	this->producator = new char[tok1.length() + 1];
	strcpy_s(this->producator, tok1.length() + 1, tok1.c_str());
	this->model = tok2;
	this->unitati = stoi(tok3);
	s.clear();
}
Gadget& Gadget::fromString(string linie, string fileName) {

	vector<string> s;
	s = readLineFromFile(linie, fileName);
	try  {
		//unique_ptr<Drona> m(new Drona(linie, fileName));
		Drona* m = new Drona(linie, fileName);
		return *m;
	}
	catch(...) {
		//unique_ptr<Telefon> s(new Telefon(linie, fileName));
		Telefon* s = new Telefon(linie, fileName);
		return *s;
	}
}
string Gadget::toStringCSV()
{
	char* array = this->producator;
	int pret = this->unitati;
	string adresaS = this->model;
	std::string producatorS(array); // CONVERT CHAR* TO STRING
	std::string unitP = std::to_string(pret);
	vector<string> atr;
	atr.push_back(producatorS);
	atr.push_back(adresaS);
	atr.push_back(unitP);
	string outstring;
	for (unsigned int i = 0; i < atr.size(); i++) {

		outstring += atr[i];
		if (i < atr.size() - 1) {

			outstring += ",";
		}
	}
	return outstring;

}
string Gadget::toStringHTML()
{
	char* array = this->producator;
	int pret = this->unitati;
	string adresaS = this->model;
	std::string producatorS(array); // CONVERT CHAR TO STRING
	std::string unitP = std::to_string(pret);
	vector<string> atr;
	atr.push_back(producatorS);
	atr.push_back(adresaS);
	atr.push_back(unitP);
	string outstring;
	for (unsigned int i = 0; i < atr.size(); i++) {

		outstring += atr[i];
		if (i < atr.size() - 1) {

			outstring += "/";
		}
	}
	return outstring;

}
char* Gadget::getProducator() {

	return this->producator;
}
string Gadget::getModel() {

	return this->model;
}
int Gadget::getUnitati() {

	return this->unitati;
}
void Gadget::setProducator(const char* producator) {

	if (this->producator) {
		delete[] this->producator;
	}
	this->producator = new char[strlen(producator) + 1];
	strcpy_s(this->producator, strlen(producator) + 1, producator);
}
void Gadget::setModel(const string model) {

	this->model = model;
}
void Gadget::setUnitati(int unitati) {

	this->unitati = unitati;
}

Gadget& Gadget::operator=(const Gadget& c) {

	this->setProducator(c.producator);
	this->setModel(c.model);
	this->setUnitati(c.unitati);
	return *this;
}

bool Gadget::operator==(const Gadget& c) {

	return (strcmp(this->producator, c.producator) == 0) && (this->model.compare(c.model) == 0) && (this->unitati == c.unitati);
}
ostream& operator<<(ostream& os, const Gadget& c) {

	os << "Nume client: " << c.producator << "|" << " Adresa client: " << c.model << "|" << " Pret total: " << c.unitati;
	return os;
}*/
