#include "Masina.h"
#include <string.h>
#include <sstream>

Masina::Masina() {
	this->nume = NULL;
	this->numar = NULL;
	this->status = NULL;
}

Masina::Masina(const char* nume, const char* numar, const char* status) {
	if (nume) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	if (status) {
		this->status = new char[strlen(status) + 1];
		strcpy_s(this->status, strlen(status) + 1, status);
	}
	if (numar) {
		this->numar = new char[strlen(numar) + 1];
		strcpy_s(this->numar, strlen(numar) + 1, numar);
	}
}

Masina::Masina(const Masina& e) {
	if (e.nume) {
		this->nume = new char[strlen(e.nume) + 1];
		strcpy_s(this->nume, strlen(e.nume) + 1, e.nume);
	}
	if (e.status) {
		this->status = new char[strlen(e.status) + 1];
		strcpy_s(this->status, strlen(e.status) + 1, e.status);
	}
	if (e.numar) {
		this->numar = new char[strlen(e.numar) + 1];
		strcpy_s(this->numar, strlen(e.numar) + 1, e.numar);
	}
}

Masina::Masina(string line) {
	std::istringstream iss(line);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	this->nume = new char[tok1.length() + 1];
	strcpy_s(this->nume, tok1.length() + 1, tok1.c_str());
	this->numar = new char[tok3.length() + 1];
	strcpy_s(this->numar, tok3.length() + 1, tok3.c_str());
	this->status = new char[tok3.length() + 1];
	strcpy_s(this->status, tok3.length() + 1, tok3.c_str());
}

char* Masina::getNume() {
	return this->nume;
}

char* Masina::getNumar() {
	return this->numar;
}

char* Masina::getStatus() {
	return this->status;
}

void Masina::setNume(const char* nume) {
	if (this->nume) {
		delete[] this->nume;
	}
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

void Masina::setNumar(const char* numar) {
	if (this->numar) {
		delete[] this->numar;
	}
	this->numar = new char[strlen(numar) + 1];
	strcpy_s(this->numar, strlen(numar) + 1, numar);
}

void Masina::setStatus(const char* status) {
	if (this->status) {
		delete[] this->status;
	}
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

Masina::~Masina() {
	if (this->nume) delete[] this->nume;
	if (this->status) delete[] this->status;
	if (this->numar) delete[] this->numar;
}

Masina& Masina::operator =(const Masina& e) {
	if (this == &e) return *this; //in case of self assignment
	if (e.nume) {
		if (this->nume)delete[]this->nume;
		this->nume = new char[strlen(e.nume) + 1];
		strcpy_s(this->nume, strlen(e.nume) + 1, e.nume);
	}
	if (e.status) {
		if (this->status)delete[]this->status;
		this->status = new char[strlen(e.status) + 1];
		strcpy_s(this->status, strlen(e.status) + 1, e.status);
	}
	if (e.numar) {
		if (this->numar)delete[]this->numar;
		this->numar = new char[strlen(e.numar) + 1];
		strcpy_s(this->numar, strlen(e.numar) + 1, e.numar);
	}
	return *this;
}

bool Masina::operator==(const Masina& e) {
	if (this->nume and e.nume and this->status and e.status and this->numar and e.numar) {
		return (strcmp(this->nume, e.nume) == 0) and (strcmp(this->numar, e.numar) == 0) and (strcmp(this->status, e.status) == 0);
	}
	return false;
}

bool Masina::operator<(const Masina& e) {
	return (strcmp(this->nume, e.nume) < 0);
}

ostream& operator<<(ostream& os, Masina e) {
	os << e.nume << " " << e.numar << " " << e.status << endl;
	return os;
}

istream& operator >>(istream& is, Masina& e) {
	cout << "Numele posesorului auto: ";
	char* nume = new char[20];
	is >> nume;
	cout << "Numarul de inmatriculare: ";
	char* numar = new char[20];
	is >> numar;
	char* status = new char[10];
	int ok = 0;
	while (ok == 0) {
		cout << "Status (liber/ocupat): " << endl;
		is >> status;
		if ((strcmp(status, "liber") == 0) or (strcmp(status, "ocupat") == 0)) ok = 1;
	}
	e.setNume(nume);
	e.setNumar(numar);
	e.setStatus(status);
	delete[] nume;
	delete[] numar;
	delete[] status;
	return is;
}