#pragma once
#include"RepositoryTemplate.h"
#include"Telefon.h"
#include"Drona.h"
#include "Gadget.h"
class Tests {
private:
	RepositoryTemplate<Gadget> repoGadget;
	RepositoryTemplate<Telefon> repoTelefon;
	RepositoryTemplate<Drona> repoDrona;

public:
	Tests();
	void testDomain();
	void testRepositoryTemplate();
	~Tests();
};