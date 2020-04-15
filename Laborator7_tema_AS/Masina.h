#pragma once
#include<iostream>
#include<string>
using namespace std;
class Masina {
private:
	char* nume;
	char* numar;
	char* status;
public:
	Masina();
	Masina(const char*, const char*, const char*);
	Masina(const Masina&);
	Masina& operator= (const Masina&);
	Masina(string); //conversion

	char* getNume();
	char* getNumar();
	char* getStatus();
	void setNume(const char*);
	void setNumar(const char*);
	void setStatus(const char*);

	bool operator ==(const Masina&);
	bool operator <(const Masina&);

	friend ostream& operator <<(ostream& os, Masina e);
	friend istream& operator >>(istream& is, Masina& e);

	~Masina();
};