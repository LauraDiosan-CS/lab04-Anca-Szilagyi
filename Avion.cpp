#include"Avion.h"

Avion::Avion() {
	//cout << "const implicit";
	this->xVarf = 0;
	this->yVarf = 0;
	this->orientare = { '\0' };
}
Avion::Avion(int x, int y, string orientare) {
	//cout << "constructor with param" << endl;
	this->xVarf = x;
	this->yVarf = y;
	this->orientare = orientare;
}
Avion::Avion(const Avion& a) {
	//cout << "copy constructor" << endl;
	this->xVarf = a.xVarf;
	this->yVarf = a.yVarf;
	this->orientare = a.orientare;
}
Avion::~Avion() {
	//cout << "Destructor";
	this->xVarf = 0;
	this->yVarf = 0;
	this->orientare = { '\0' };
}
int Avion::getX() {

	return this->xVarf;
}
int Avion::getY() {

	return this->yVarf;
}
string Avion::getOrientareCoada() {

	return this->orientare;
}
void Avion::setX(int x) {

	this->xVarf = x;
}
void Avion::setY(int y) {
	this->yVarf = y;
}
void Avion::setOrientareCoada(string orientare) {

	this->orientare = orientare;
}Avion& Avion::operator=(const Avion& a) {

	this->setX(a.xVarf);
	this->setY(a.yVarf);
	this->setOrientareCoada(a.orientare);
	return *this;
}
bool Avion::operator==(const Avion& a) {

	return (this->xVarf == a.xVarf) && (this->yVarf == a.yVarf) && (this->orientare.compare(a.orientare) == 0);
}
ostream& operator<<(ostream& os, const Avion& a) {

	os << "Coordonata X: " << a.xVarf << "|" << " Coordonata Y: " << a.yVarf << "|" << " Orientare coada:" << a.orientare;
	return os;
}