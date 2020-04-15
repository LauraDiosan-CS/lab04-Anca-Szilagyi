#pragma once
#include"RepoFile.h"
#include "RepoTemplate.h"
#include "Masina.h"
using namespace std;

class Service
{
private:
	RepositoryTemplate<Masina>& repo;
	int psize;
	int maxc;
	int cars;
public:
	int max;

	Service(RepositoryTemplate<Masina>& r) :repo(r) { repo = r; max = 2; psize = 0; maxc = 0; cars = 0; };
	//void setRepo(const RepositoryTemplate<Masina>&);
	void addCar(Masina&);
	int delCar(Masina&);
	list<Masina> getAll();
	Masina updateCar(Masina, const char*, const char*, const char*);
	int findElem(Masina);
	Masina getItemFromPos(int);
	int getSize();
	int size();
	void intrare(Masina&);
	void iesire(Masina&);
	int maxCars();
	void setMax(int);
	~Service();
};
