#pragma once
#include <list>
#include <iostream>
#include<fstream>
#include "Masina.h"
#include "RepoTemplate.h"
using namespace std;


template<class T>class RepositoryFile :public RepositoryTemplate<Masina>
{
private:
	const char* fis;
public:
	RepositoryFile();
	RepositoryFile(const char*);
	int addElem(const T&);
	int deleteElem(const T&);
	void updateElem(const T&, const T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepositoryFile();
};

template<class T>
RepositoryFile<T>::RepositoryFile() :RepositoryTemplate<Masina>()
{
	fis = "";
}
template<class T>
RepositoryFile<T>::RepositoryFile(const char* fileName)
{
	loadFromFile(fileName);
	
}

template<class T>
void RepositoryFile<T>::loadFromFile(const char* fileName)
{
	//elem.clear();
	RepositoryTemplate::clearElem();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[20];
	char* numar = new char[20];
	char* status = new char[10];
	while (!f.eof())
	{
		f >> nume >> numar >> status;
		if (strcmp(nume, "") != 0)
		{
			Masina e(nume, numar, status);
			//elem.push_back(e);
			RepositoryTemplate::addElem(e);
		}
	}
	delete[] nume;
	delete[] numar;
	delete[] status;
	f.close();
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
	ofstream f(fis);
	list<Masina>::iterator it;
	list<Masina>elem = RepositoryTemplate::getAll();
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		f << *it;
	}
	f.close();
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
{

}

template<class T>
int RepositoryFile<T>::addElem(const T& e) {
	int r = RepositoryTemplate::addElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryFile<T>::deleteElem(const T& e) {
	int r = RepositoryTemplate::deleteElem(e);
	if (r != 0) {
		saveToFile();
		return 0;
	}
	else
		return -1;
}
template<class T>
void RepositoryFile<T>::updateElem(const T& e, const T n)
{
	RepositoryTemplate::updateElem(e, n);
	saveToFile();
}
