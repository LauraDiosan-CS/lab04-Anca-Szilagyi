#include "assert.h"
#include "TesteValidare.h"
#include "RepoFile.h"
#include "Drona.h"
#include "Telefon.h"
#include "ValidareGadget.h"
#include "ValidareDrona.h"
#include "ValidareTelefon.h"
#include "Service.h"
#include "RepoHTML.h"
#include "RepoCSV.h"
#include "MyException.h"
void testValidareGadget() {
	RepoHTML<Drona> r1("Teste.html");
	RepoHTML<Telefon> r2("Teste.html");
	ValidareDrona v;
	ValidareTelefon sv;
	Service<Drona, Telefon> s(r1, r2, v, sv);
	//assert(s.getSize1() == 0);
	//assert(s.getSize2() == 0);
	vector<string> lista;
	lista.push_back("Orange6.7");
	lista.push_back("Vod");
	lista.push_back("Vodafone8");
	Drona m1("Apple", "Iphone8", 119, 7);
	bool exceptionThrown = false;
	try {
		s.addElem1(m1);
	}
	catch (MyException e)
	{
		exceptionThrown = false;
	}
	assert(exceptionThrown==false);
	//vector<string> lista1;
	Drona m2("Apple", "Iphone8", 23, 5);
	bool exceptionThrown1 = false;
	try {
		s.addElem1(m2);
	}
	catch (MyException e)
	{
		exceptionThrown1 = false;
	}
	assert(exceptionThrown1==false);
	vector<string> lista2;
	lista.push_back("Orange6.7");
	lista.push_back("Orange3");
	lista.push_back("Orange8");
	Telefon sp("Apple", "Iphone8", 19, lista2);
	bool exceptionThrown2 = false;
	try {
		s.addElem2(sp);
	}
	catch (MyException e)
	{
		exceptionThrown2 = true;
	}
	assert(exceptionThrown2);
	vector<string> lista3;
	Telefon sp1("Apple", "Iphone8", 23, lista3);
	bool exceptionThrown3 = false;
	try {
		s.addElem2(sp1);
	}
	catch (MyException e)
	{
		exceptionThrown3 = true;
	}
	assert(exceptionThrown3);
}