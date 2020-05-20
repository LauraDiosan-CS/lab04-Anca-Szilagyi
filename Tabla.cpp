#include"Tabla.h"
#include<sstream>

Tabla::Tabla() {
	this->linii = 0;
	this->coloane = 0;
	for (int i = 1; i <= linii; i++)
		for (int j = 1; j <= coloane; j++)
			this->tabla[i][j] = 0;
}

Tabla::Tabla(int l, int c, int p[100][100]) {
	this->linii = l;
	this->coloane = c;
	for (int i = 1; i <= linii; i++)
		for (int j = 1; j <= coloane; j++)
			this->tabla[i][j] = p[i][j];
}
/*Tabla::Tabla(const Tabla& m) {
	this->linii = m.linii;
	this->coloane = m.coloane;
	for (int i = 1; i <= linii; i++)
		for (int j = 1; j <= coloane; j++)
			this->tabla[i][j] = m.tabla[i][j];
}*/
Tabla::~Tabla() {
}
/*
Tabla::Tabla(string linie, string fileName) :Gadget(linie, fileName) {

	vector<string> s = Gadget::readLineFromFile(linie, fileName);
	string tok4;
	tok4 = s[s.size() - 1];

	this->rotoare = stoi(tok4);
}
string Tabla::toStringCSV() {

	string outstring;
	int unit = this->unitati;
	std::string rot = std::to_string(rotoare);
	outstring = Gadget::toStringCSV();

	return outstring + "," + rot;
}
string Tabla::toStringHTML() {

	string outstring;
	outstring = Gadget::toStringHTML();
	int unit = this->unitati;
	std::string rot = std::to_string(rotoare);
	outstring += "/";
	//for (unsigned int i = 0; i < lista.size(); i++)
	//{
	//	outstring += lista[i];
	//	if (i < lista.size() - 1)
	//	{
		//	outstring += " ";
	//	}
	//}
	return outstring + "/" + rot;
}*/

//returneaza un anumit element de pe tabla
int Tabla::getPatrat(int linie, int coloana) {
	return this->tabla[linie][coloana];
}
int Tabla::getLinii() {
	return this->linii;
}
/*int Tabla::getTabla() {
	return this->tabla;
}*/
int Tabla::getColoane() {
	return this->coloane;
}

void Tabla::setTabla(const int tablaDeJoc[100][100], int l, int c) {
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= c; j++)
			this->tabla[i][j] = tablaDeJoc[i][j];
}

//modifica sau nu un element dintr-un anumit patrat
void Tabla::setPatrat(int l, int c, const int elem) {
	this->tabla[l][c] = elem;
}

void Tabla::setLinii(int nrLinii) {
	this->linii = nrLinii;
}

void Tabla::setColoane(int nrCol) {
	this->coloane = nrCol;
}

Tabla& Tabla::operator=(const Tabla& m) {

	this->setLinii(m.linii);
	this->setColoane(m.coloane);
	this->setTabla(m.tabla, m.linii, m.coloane);

	return *this;
}

bool Tabla::operator==(const Tabla& m) {
	bool ok = true;
	if (this->linii != m.linii) {
		ok = false;
		return ok;
	}
	if (this->coloane != m.coloane) {
		ok = false;
		return ok;
	}
	for (int i = 0; i < this->linii; i++)
		for (int j = 0; j < this->coloane; j++)
			if (this->tabla[i][j] != m.tabla[i][j]) {
				ok = false;
				return ok;
			}
	return true;
}
ostream& operator<<(ostream& os, const Tabla& m)
{
	for (int i = 1; i <= m.linii; i++){
		for (int j = 1; j <= m.coloane; j++) {
			os << m.tabla[i][j] << " ";
		}
		os << endl;
	}
	/*os << m.linii << " ";
	os << m.model << " ";
	os << m.unitati << " ";
	os << m.rotoare << endl;;*/
	//for (auto i = m.rotoare.begin(); i != m.rotoare.end(); ++i)
	//	os << *i << " ";
	//os << endl;
	return os;
}
