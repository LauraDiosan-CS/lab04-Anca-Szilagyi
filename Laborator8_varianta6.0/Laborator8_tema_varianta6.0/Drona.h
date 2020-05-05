#pragma once
#include "Gadget.h"
#include<vector>
using namespace std;
class Drona : public Gadget {
private:
	int rotoare;
public:
	Drona();
	Drona(const char*, const string, int, int);
	Drona(const Drona&);
	~Drona();
	Drona(string, string);
	string toStringCSV();
	string toStringHTML();
	int getRotoare();
	void setRotoare(int);
	Drona& operator=(const Drona&);
	bool operator==(const Drona&);
	friend ostream& operator<<(ostream& os, const Drona& c);


};