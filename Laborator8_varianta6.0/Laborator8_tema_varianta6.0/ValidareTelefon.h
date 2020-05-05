#pragma once
#include "Telefon.h"
#include "ValidareGadget.h"
class ValidareTelefon :public ValidareGadget {
public:
	ValidareTelefon() {}
	~ValidareTelefon() {}
	void validareGadget(Gadget& s);
};