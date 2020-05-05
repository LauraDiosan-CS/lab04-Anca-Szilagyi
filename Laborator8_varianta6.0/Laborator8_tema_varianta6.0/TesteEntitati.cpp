#include"assert.h"
#include<vector>
#include "TesteEntitati.h"
#include "Gadget.h"
#include "Drona.h"
#include "Telefon.h"
#include<string>
void testGadget() {
	Gadget c("Apple", "IPhoneX200", 197);
	c.setProducator("Samsung");
	assert(strcmp(c.getProducator(), "Samsung") == 0);
	c.setModel("GalaxyA60");
	string adresa = "GalaxyA60";
	assert(c.getModel().compare(adresa) == 0);
	c.setUnitati(200);
	assert(c.getUnitati() == 200);
	Gadget c2 = c;
	Gadget c3;
	c3 = c2;
	assert(c3 == c2);

}
void testDrona() {
	Drona m("Apple", "Iphone1.8", 22, 3);
	m.setProducator("Samsung");
	assert(strcmp(m.getProducator(), "Samsung") == 0);
	m.setRotoare(5);
	assert(m.getRotoare() == 5);
	Drona m2 = m;
	Drona m3;
	m3 = m2;
	assert(m3 == m2);

}
void testTelefon() {
	vector<string> lista;
	lista.push_back("Vod");
	lista.push_back("Samsung324");
	lista.push_back("Orange2");
	Telefon s("Apple", "Iphone1.8", 218, lista);
	vector<string>lista1;
	lista1.push_back("Vodafone2");
	lista1.push_back("Orange3");
	s.setProducator("Samsung");
	assert(strcmp(s.getProducator(), "Samsung") == 0);
	s.setOperatoriGSM(lista1);
	assert(s.getOperatoriGSM()[0].compare("Vodafone2") == 0 && s.getOperatoriGSM()[1].compare("Orange3") == 0);
}