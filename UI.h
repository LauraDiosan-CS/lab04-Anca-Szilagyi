#pragma once
#include "Service.h"
#include "Drona.h"
#include "Telefon.h" 
class UI {
private:
	bool logIn = false;
	Service<Gadget&>* s;
	void addGadgetDrona();
	void showGadgets();
	void deleteGadgetDrona();
	void updateGadgetDrona();
	void addGadgetTelefon();
	void deleteGadgetTelefon();
	void updateGadgetTelefon();
	void choseFile();
	void login();
	void searchByName();
	void Logout();
	void PrintMenu();

public:
	UI(Service<Gadget&>& serv) :s(&serv) {  };
	~UI() {}
	void showUI();

};