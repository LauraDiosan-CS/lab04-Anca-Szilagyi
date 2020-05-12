#pragma once
#include <string>
#include<iostream>
#include<vector>
#include "Serializable.h"
using namespace std;
class Gadget :Serializable {
protected:
	char* producator;
	string model;
	int unitati;
public:
	Gadget();
	Gadget(const char* producator, string model, int unitati);
	Gadget(const Gadget& c);
	~Gadget();
	Gadget(string, string);
	virtual string toStringCSV();
	virtual string toStringHTML();
	static Gadget& fromString(string linie, string fileName);
	char* getProducator();
	string getModel();
	int getUnitati();
	void setProducator(const char* producator);
	void setModel(string model);
	void setUnitati(int unitati);
	Gadget& operator=(const Gadget& c);
	bool operator==(const Gadget&);
	friend ostream& operator<<(ostream& os, const Gadget& c);
	static vector<string> readLineFromFile(string, string);


};