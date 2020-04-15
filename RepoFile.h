#pragma once
#include <list>
#include <iostream>
#include<fstream>
#include "Gadget.h"
#include "RepositoryTemplate.h"
using namespace std;


template<class T>class RepositoryFile :public RepositoryTemplate<T>
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
RepositoryFile<T>::RepositoryFile() :RepositoryTemplate<T>()
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
	char* numeProducator = new char[20];
	char* numeModel = new char[20];
	int unitatiProduse = new int[10];
	while (!f.eof())
	{
		f >> numeProducator >> numeModel >> unitatiProduse;
		if (strcmp(numeProducator, "") != 0)
		{
			T e(numeProducator, numeModel, unitatiProduse);
			//elem.push_back(e);
			RepositoryTemplate::addElem(e);
		}
	}
	delete[] numeProducator;
	delete[] numeModel;
	delete[] unitatiProduse;
	f.close();
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
	ofstream f(fis);
	typename list<T>::iterator it;
	list<T>elem = RepositoryTemplate::getAll();
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
