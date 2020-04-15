#pragma once
#include "Gadget.h"
#include<vector>
class Drona : public Gadget {
private:
	int numarRotoare;
public:
	Drona();
	Drona(const char*, const char*, int, int);

	void setNumarRotoare(int number);
	int getNumarRotoare();

	~Drona();

};