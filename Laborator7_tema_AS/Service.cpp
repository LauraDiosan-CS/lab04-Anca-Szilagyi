#include "Service.h"


void Service::addCar(Masina& p)
{
	list<Masina> el;
	el = repo.getAll();
	list<Masina>::iterator it;
	for (it = el.begin(); it != el.end(); ++it) {
		if (strcmp((*it).getNumar(), p.getNumar()) == 0) {
			throw exception("Exista deja acest nr de inmatriculare.");
		}
	}
	psize = size();
	if (strcmp(p.getStatus(), "ocupat") == 0 and max == psize) {
		throw exception("Nu mai sunt locuri in parcare");
	}
	repo.addElem(p);
}

int Service::delCar(Masina& p)
{
	if (findElem(p) == -1) {
		throw exception("Masina nu exista.");
	}
	//undo[size++] = repo;
	else {
		if (strcmp(p.getStatus(), "ocupat") == 0) { throw exception("Nu se paote sterge o masina cu statusul OCUPAT."); }
		else {
			repo.deleteElem(p);
			return 0;
		}
	}
	return -1;
}

list<Masina> Service::getAll()
{
	return repo.getAll();
}

Masina Service::updateCar(Masina p, const char* nameToIntro, const char* nu, const char* st)
{
	//undo[size++] = repo;
	Masina c(nameToIntro, nu, st);
	repo.updateElem(p, c);
	return p;
}

int Service::findElem(Masina p)
{
	return repo.findElem(p);
}
Masina Service::getItemFromPos(int i) {
	if (i >= 0 and i < repo.getSize())
		return repo.getItemFromPos(i);
	Masina p;
	return p;
}

int Service::getSize() {
	return repo.getSize();
}
int Service::size() {
	psize = 0;
	list<Masina> el;
	el = repo.getAll();
	list<Masina>::iterator it;
	for (it = el.begin(); it != el.end(); ++it) {
		if (strcmp((*it).getStatus(), "ocupat") == 0) {
			psize++;
		}
	}
	return psize;
}
void Service::intrare(Masina& c) {
	list<Masina> el;
	el = repo.getAll();
	list<Masina>::iterator it;
	int ok = 0;
	for (it = el.begin(); it != el.end(); ++it)
	{
		if (strcmp((*it).getNumar(), c.getNumar()) == 0)
		{
			ok++;
		}
	}
	if (ok == 0) {
		throw exception("Masina nu a fost gasita.");
	}
	if (strcmp(c.getStatus(), "ocupat") == 0) {
		throw exception("Masina este deja in parcare. :)");
	}
	psize = size();
	if (max == psize) {
		cars++;
		throw exception("Nu mai sunt locuri in parcare");
	}
	Masina newc(c.getNume(), c.getNumar(), "ocupat");
	repo.updateElem(c, newc);
}

void Service::iesire(Masina& c) {
	list<Masina> el;
	el = repo.getAll();
	list<Masina>::iterator it;
	int ok = 0;
	for (it = el.begin(); it != el.end(); ++it)
	{
		if (strcmp((*it).getNumar(), c.getNumar()) == 0)
		{
			ok++;
		}
	}
	if (ok == 0) {
		throw exception("Masina nu a fost gasita.");
	}
	if (strcmp(c.getStatus(), "liber") == 0) {
		throw exception("Masina nu este in parcare (deci nu poate iesi...).");
	}
	if (cars > maxc) { maxc = cars; }
	cars = 0;
	Masina newc(c.getNume(), c.getNumar(), "liber");
	repo.updateElem(c, newc);
}
int Service::maxCars() {
	return maxc;
}
void Service::setMax(int i)
{
	//cout << max << endl;
	//if (i > size())
		//throw exception("Nu se poate!");
	
	if (i > 0) {
		max = i;
		cout << max << endl;
	}
	
}


Service::~Service()
{
}