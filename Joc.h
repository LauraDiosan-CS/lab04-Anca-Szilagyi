#pragma once
#include<string>
#include <vector>
#include<iostream>
#include "Tabla.h"
#include "Avion.h"
using namespace std;
class Joc {
private:
	Tabla tablaJoc;
	vector<Avion> avioane;
public:
	Joc();
	Joc(Tabla tabla, vector<Avion> avioane);
	~Joc();
	void addAvion(Avion);
	int getItemFromPos(int i, int j);
	int getLin();
	int getCol();
	friend ostream& operator<<(ostream& os, const Joc& c);
};