#pragma once
#include <string>
#include<iostream>
#include<vector>
using namespace std;
class Gadget {
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
	char* getProducator();
	string getModel();
	int getUnitati();
	void setProducator(const char* producator);
	void setModel(string model);
	void setUnitati(int unitati);
	Gadget& operator=(const Gadget& c);
	bool operator==(const Gadget&);
	friend ostream& operator<<(ostream& os, const Gadget& c);
	vector<string> readLineFromFile(string, string);

};