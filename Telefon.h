#pragma once
#include "Gadget.h"
#include<vector>
using namespace std;
class Telefon : public Gadget {
private:
	vector<string>operatoriGSM;
public:
	Telefon();
	Telefon(const char*, const string, int, vector<string>);
	Telefon(const Telefon&);
	~Telefon();
	Telefon(string, string);
	string toStringCSV();
	string toStringHTML();
	vector<string> getOperatoriGSM();
	void setOperatoriGSM(vector<string>);
	Telefon& operator=(const Telefon&);
	bool operator==(const Telefon&);
	friend ostream& operator<<(ostream& os, const Telefon& s);

};