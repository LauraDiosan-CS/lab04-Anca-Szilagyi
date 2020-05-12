#include"ValidareDrona.h"
#include "MyException.h"
void ValidareDrona::validareGadget(Gadget& m) {

	Drona& ma = dynamic_cast<Drona&>(m);
	if (m.getUnitati() < 100)
		throw MyException("Numar de unitati sub 100...");


}