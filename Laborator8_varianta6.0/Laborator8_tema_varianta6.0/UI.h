#pragma once
#include "Service.h"
#include "Drona.h"
#include "Telefon.h" 
class UI {
private:
	bool logIn = false;
	Service<Drona, Telefon>* s;
	void addGadgetDrona();
	void showDrone();
	void deleteGadgetDrona();
	void updateGadgetDrona();
	void addGadgetTelefon();
	void showPhones();
	void deleteGadgetTelefon();
	void updateGadgetTelefon();
	void choseFile();
	void login();
	void searchByName();
	void Logout();
	void PrintMenu();

public:
	UI(Service<Drona, Telefon>& serv) :s(&serv) {  };
	~UI() {}
	void showUI();

};