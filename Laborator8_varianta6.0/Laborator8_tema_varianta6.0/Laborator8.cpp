#include <iostream>
#include "TesteEntitati.h"
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
	testValidareGadget();

	RepoFile<Drona> rm;
	RepoFile<Telefon> rs;
	ValidareDrona vm;
	ValidareTelefon vs;
	Service<Drona, Telefon> s(rm, rs, vm, vs);
	UI u(s);
	u.showUI();

}