#include "ValidareTelefon.h"
#include "MyException.h"
void ValidareTelefon::validareGadget(Gadget& s) {

	Telefon& sa = dynamic_cast<Telefon&>(s);
	ValidareGadget::validareGadget(s);
	if (sa.getOperatoriGSM().size() < 1) {

		throw MyException("Lista de operatori GSM compatibili trebuie sa contina cel putin un operator.");
	}
}