#include <iostream>
#include "TesteEntitati.h"
#include "TesteFunctionalitati.h"
#include "TesteRepo.h"
#include "RepoFile.h"
#include "Drona.h"
#include "Telefon.h"
#include "Service.h"
#include "UI.h"
#include "TesteValidare.h"
#include "ValidareGadget.h"
#include "ValidareDrona.h"
#include "ValidareTelefon.h"
using namespace std;


int main()
{
	cout << "Se verifica testele..." << endl;
	testGadget();
	testDrona();
	testTelefon();
	addElemGadget();
	deleteElemGadget();
	updateElemGadget();
	getAllGadget();
	addElemDrona();
	deleteElemDrona();
	updateElemDrona();
	getAllDrona();
	addElemTelefon();
	deleteElemTelefon();
	updateElemTelefon();
	getAllTelefon();
	searchByName();
	cout << "Testele sunt ok!" << endl << endl;

	//RepoFile<Drona> rm;
	//RepoFile<Telefon> rs;
	ValidareDrona vm;
	RepoFile<Gadget&> r;
	ValidareTelefon vs;
	Service<Gadget&> s(r, vm, vs);
	UI u(s);
	u.showUI();

}