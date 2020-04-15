#pragma once
#include "Gadget.h"
#include <sstream>
class Drona :
	public Gadget
{
private:
	int numarRotoare;
public:
	Drona();
	Drona(const char* p, const char* m, int u, int r);
	Drona(Drona& d);
	Drona& operator=(const Drona& sb);
	bool operator==(const Drona& s);

	~Drona();

	int getNrRotoare();
	void setNrRotoare(int r);

	void read(istream& input)override;
	void write(ostream& output)override;
	const char* toString() override;
	Drona* clone()override;
};