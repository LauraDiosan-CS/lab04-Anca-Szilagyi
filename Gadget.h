#pragma once
#include <string>
#include <iostream>
#include <tuple>

using namespace std;

class Gadget
{
protected:
	const char* numeProd;
	const char* model;
	int unitatiProduse;
public:
	Gadget();
	Gadget(const char* nume, const char* model, int unitati);
	Gadget(Gadget& g);
	virtual ~Gadget();

	const char* getNumeProducator();
	const char* getNumeModel();
	int getUnitati();

	void setNumarProducator(const char* n);
	void setNumeModel(const char* m);
	void setUnitati(int u);

	//friend ostream& operator<<(ostream& os, Gadget* g);
	//friend istream& operator>>(istream& input, Gadget* g);

	bool operator==(const Gadget& g);
	//bool operator!=(const Gadget& g);
	virtual Gadget& operator=(const Gadget& g);




	virtual void read(istream& input);
	virtual void write(ostream& output);
	virtual const char* toString() = 0;
	virtual Gadget* clone() = 0;
};
