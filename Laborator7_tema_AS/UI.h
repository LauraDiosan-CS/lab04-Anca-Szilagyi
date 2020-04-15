#pragma once
#include "Service.h"
class UI {
private:
	Service s;
public:
	UI(Service& serv) : s(serv) {};
	void adaugareMasina();
	void gasireMasina();
	void showUI();
	void stergereMasina();
	void showThemAll();
	void updateMasina();
	void intrareMasina();
	void iesireMasina();
	void set();
	~UI();
};