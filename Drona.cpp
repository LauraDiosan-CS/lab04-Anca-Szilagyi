#include "Drona.h"
#include<algorithm>
using namespace std;

Drona::Drona() :Gadget(){
}

Drona::Drona(const char* p, const char* m, int u, int r) : Gadget(p, m, u){
	numarRotoare = r;
}

Drona::Drona(Drona& d) : Gadget(d){
	numarRotoare = d.numarRotoare;
}

Drona::~Drona(){
}

int Drona::getNrRotoare(){
	return numarRotoare;
}

void Drona::setNrRotoare(int r){
	numarRotoare = r;
}

Drona& Drona::operator=(const Drona& sb)
{
	this->Gadget::operator=(sb);
	this->numarRotoare = sb.numarRotoare;
	return *this;
}

bool Drona::operator==(const Drona& s)
{
	return (Gadget::operator==(s) && (numarRotoare == s.numarRotoare));
}


