#pragma once
#include "Drona.h"
#include "ValidareGadget.h"
class ValidareDrona : public ValidareGadget {
public:
	ValidareDrona() {}
	~ValidareDrona() {}
	void validareGadget(Gadget& m);
};