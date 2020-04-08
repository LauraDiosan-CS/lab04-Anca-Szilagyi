#include "RepoFile.h"
#include <fstream>
#include <string>
using namespace std;


RepoFile::RepoFile()
{
	capacitateMaxima = 0;

}

void RepoFile::loadFromFile(const char* fileName)
{
	//elem.clear();
	//fis = fileName;
	ifstream f(fileName);
	char* nume = new char[20];
	char* numarInmatriculare = new char[10];
	char* status = new char[10];

	while (!f.eof()) {
		f >> nume >> numarInmatriculare>>status;
		if (strcmp(nume, "") != 0) {
			Aplicatie s(nume, numarInmatriculare, status);
			addElem(s);
		}
	}
	delete[] nume;
	delete[] numarInmatriculare;
	delete[] status;
	f.close();
}

void RepoFile::setCapacitateMaxima(int number) {
	capacitateMaxima = number;
}
int RepoFile::getCapacitateMaxima() {
	return capacitateMaxima;
}




RepoFile::~RepoFile()
{

}

