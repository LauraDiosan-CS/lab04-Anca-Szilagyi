#pragma once
#include "Aplicatie.h"
#include <list>
#include<iterator>

using namespace std;

class RepositorySTL
{
private:
	list<Aplicatie> elem;

public:
	RepositorySTL();
	void addElem(Aplicatie);
	bool findElem(Aplicatie);
	void delElem(Aplicatie app);
	void updateElem(Aplicatie app, const char* numeNou, const char* numarNou, const char* statusNou);
	Aplicatie getItemFromPos(int i);
	list<Aplicatie> getAll();
	int dim();
	Aplicatie get(list<Aplicatie> elem, int _i);
	~RepositorySTL();
};
