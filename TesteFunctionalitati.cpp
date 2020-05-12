#include "Service.h"
#include "RepoCSV.h"
#include <assert.h>
#include "ValidareGadget.h"
#include "ValidareDrona.h"
#include "ValidareTelefon.h"
#include "Login.h"
void searchByName() {

	RepoCSV<Gadget&> r("Teste.CSV");
	ValidareDrona v1;
	ValidareTelefon v2;
	Service<Gadget&> s(r, v1, v2);
	assert(s.getSize() == 0);

	Drona* m = new Drona("Apple", "IphoneX", 123, 5);
	s.addElem(*m);
	vector<string> lista;
	lista.push_back("Orange");
	lista.push_back("Vodafone");
	lista.push_back("Cosmote");
	Telefon* so = new Telefon("Samsung", "CevaAndroid", 143, lista);
	s.addElem(*so);

	Drona* m1 = new Drona("AppleUpgraded", "IphoneX21", 165, 5);
	s.addElem(*m1);
	map<int, Gadget&> res;
	res = s.show("Samsung");
	assert(res.find(0)->second == *so);
	r.clearFile("Teste.CSV");
}
void loginTest() {

	LoginManager lo;
	bool lol = false;
	lol = lo.login("Ana", "123");
	assert(lol == true);
	lol = lo.login("Samsung", "123");
	assert(lol == false);
}