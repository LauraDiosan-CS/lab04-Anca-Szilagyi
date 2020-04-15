#pragma once
#include "Gadget.h"
class Telefon :
	public Gadget
{
private:
	const char* listaOperatoriGSMCompatibili;
public:
	Telefon();
	Telefon(const char* p, const char* m, int u, const char* o);
	Telefon(Telefon& t);
	~Telefon();
	bool operator==(const Telefon& s);
	Telefon& operator=(const Telefon& sb);

	const char* getListaOperatori();
	void setListaOperatori(const char* o);

	void read(istream& input)override;
	void write(ostream& output)override;
	const char* toString() override;
	Telefon* clone()override;
};