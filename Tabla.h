#pragma once
#include<vector>
#include <iostream>
using namespace std;
class Tabla {
private:
	int linii;
	int coloane;
	int tabla[100][100];
public:
	Tabla();
	Tabla(int l, int c, int p[100][100]);
	//Tabla(const Tabla&);
	~Tabla();
	//Tabla(string, string);
	//string toStringCSV();
	//string toStringHTML();
	int getPatrat(int linie, int coloana);
	int getLinii();
	int getColoane();
	//int getTabla();
	void setPatrat(int, int, const int);
	void setLinii(int);
	void setTabla(const int tablaDeJoc[100][100], int l, int c);
	void setColoane(int);
	Tabla& operator=(const Tabla&);
	bool operator==(const Tabla&);
	friend ostream& operator<<(ostream& os, const Tabla& c);
};