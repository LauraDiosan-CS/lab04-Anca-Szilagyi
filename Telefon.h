#pragma once
#include "Gadget.h"
#include<vector>
class Telefon : public Gadget {
private:
	const char* listaOperatoriGSMCompatibili;
public:
	Telefon();
	~Telefon();

};





/*#pragma once
#include "Gadget.h"
class Telefon :
	public Gadget
{
private:
	char listaOperatoriGSMCompatibili[100];
public:
	Telefon();
	Telefon(const char*, const char*, const char*, char);
	Telefon(const Telefon&);
	~Telefon();
	char getListaOperatori();
	void setListaOperatori(char);
	Telefon& operator=(const Telefon&);
	bool operator==(const Telefon&);
	//friend ostream& operator<<(ostream&, Telefon&);
	//friend istream& operator>>(istream&, Telefon&);
};*/

