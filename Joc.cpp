#include"Joc.h"
#include <string.h>

Joc::Joc() {
}
Joc::~Joc() {
	
}
Joc::Joc(Tabla tabla, vector<Avion> av) {
	this->tablaJoc = tabla;
	Avion a;
	do {
		a = av.back();
		this->avioane.push_back(a);
		av.pop_back();
	} while (av.size()>0);
	//planes integrations part;
	
	Avion thisOne;
	do {
		thisOne = this->avioane.back();
		this->tablaJoc.setPatrat(thisOne.getX(), thisOne.getY(), 7);
		if (thisOne.getOrientareCoada() == "l") {
			tablaJoc.setPatrat(thisOne.getX(), thisOne.getY() + 1, 7);
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY() + 1, 7);
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY() + 1, 7);
			tablaJoc.setPatrat(thisOne.getX() - 2, thisOne.getY() + 1, 7);
			tablaJoc.setPatrat(thisOne.getX() + 2, thisOne.getY() + 1, 7);
			tablaJoc.setPatrat(thisOne.getX(), thisOne.getY() + 2, 7);
			tablaJoc.setPatrat(thisOne.getX(), thisOne.getY() + 3, 7);
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY() + 3, 7);
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY() + 3, 7);
		}
		else if (thisOne.getOrientareCoada() == "r") {
			tablaJoc.setPatrat(thisOne.getX(), thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX() - 2, thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX() + 2, thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX(), thisOne.getY() - 2, 7);
			tablaJoc.setPatrat(thisOne.getX(), thisOne.getY() - 3, 7);
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY() - 3, 7);
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY() - 3, 7);
		}
		else if (thisOne.getOrientareCoada() == "u") {
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY(), 7);
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY()+ 1, 7);
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY()-2, 7);
			tablaJoc.setPatrat(thisOne.getX() - 1, thisOne.getY()+2, 7);
			tablaJoc.setPatrat(thisOne.getX()-2, thisOne.getY(), 7);
			tablaJoc.setPatrat(thisOne.getX()-3, thisOne.getY(), 7);
			tablaJoc.setPatrat(thisOne.getX() - 3, thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX() -3, thisOne.getY() +1, 7);
		}
		else if (thisOne.getOrientareCoada() == "d") {
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY(), 7);
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY() + 1, 7);
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY() - 2, 7);
			tablaJoc.setPatrat(thisOne.getX() + 1, thisOne.getY() + 2, 7);
			tablaJoc.setPatrat(thisOne.getX() + 2, thisOne.getY(), 7);
			tablaJoc.setPatrat(thisOne.getX() + 3, thisOne.getY(), 7);
			tablaJoc.setPatrat(thisOne.getX() + 3, thisOne.getY() - 1, 7);
			tablaJoc.setPatrat(thisOne.getX() + 3, thisOne.getY() + 1, 7);
		}

		avioane.pop_back();
	} while (this->avioane.size()>0);

}

void Joc::addAvion(Avion a) {
	this->avioane.push_back(a);
}

int Joc::getItemFromPos(int i, int j) {
	return this->tablaJoc.getPatrat(i, j);
}

int Joc::getLin() {
	return this->tablaJoc.getLinii();
}
int Joc::getCol() {
	return this->tablaJoc.getColoane();
}
ostream& operator<<(ostream& os, const Joc& a) {
	os << a.tablaJoc;
	//os << "Coordonata X: " << a.xVarf << "|" << " Coordonata Y: " << a.yVarf << "|" << " Orientare coada:" << a.orientare;
	return os;
}