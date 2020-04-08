#pragma once
#include "Aplicatie.h"
#include <list>
#include<iterator>
#include "RepositorySTL.h"

using namespace std;

class RepoFile : public RepositorySTL
{
private:
	int capacitateMaxima = 0;
public:
	RepoFile();
	void loadFromFile(const char* fileName);
	void setCapacitateMaxima(int);
	int getCapacitateMaxima();

	~RepoFile();
};
