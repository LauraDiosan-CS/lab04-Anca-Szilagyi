#include "ValidareGadget.h"
#include "MyException.h"
void ValidareGadget::validareGadget(Gadget& c) {

	if (strlen(c.getProducator()) <= 2) {

		throw MyException("Numele producatorului trebuie sa aiba mai mult de 2 litere.");
	}


	if (c.getUnitati() <= 100) {

		throw MyException("Pretul total trebuie sa fie strict pozitiv.");
	}

}