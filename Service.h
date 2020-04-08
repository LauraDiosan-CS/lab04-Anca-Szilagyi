#pragma once
#include "RepositorySTL.h"
#include "RepoFile.h"
#include <list>
#include<iterator>

using namespace std;

class Service{
private:
	RepoFile depozit;
public:
	Service();
	int addElem(Aplicatie);
	bool findElem(Aplicatie);
	void delElem(Aplicatie app);
	void updateElem(Aplicatie app, const char* numeNou, const char* numarNou, const char* statusNou);
	Aplicatie getItemFromPos(int i);
	list<Aplicatie> getAll();
	int dim();
	int getCapMax();

	int intrare(const char* numarInmatriculare);
	Aplicatie get(list<Aplicatie> elem, int _i);
	int capacitate();
	int areLoc();
	void setCapacitateMaxima(int);

	~Service();
};
