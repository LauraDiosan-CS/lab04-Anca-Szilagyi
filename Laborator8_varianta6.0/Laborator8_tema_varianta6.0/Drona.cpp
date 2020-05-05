#include"Drona.h"
#include<sstream>
Drona::Drona() {
	this->rotoare = 0;
}

Drona::Drona(const char* n, const string a, int p, int l) :Gadget(n, a, p) {

	this->rotoare = l;

}
Drona::Drona(const Drona& m) : Gadget(m) {

	rotoare = m.rotoare;
}
Drona::~Drona() {
}
Drona::Drona(string linie, string fileName) :Gadget(linie, fileName) {

	vector<string> s = Gadget::readLineFromFile(linie, fileName);
	string tok4;
	tok4 = s[s.size() - 1];

	this->rotoare = stoi(tok4);
}
string Drona::toStringCSV() {

	string outstring;
	int unit = this->unitati;
	std::string pretS = std::to_string(rotoare);
	outstring = Gadget::toStringCSV();

	return outstring + "," + pretS;
}
string Drona::toStringHTML() {

	string outstring;
	outstring = Gadget::toStringHTML();
	int unit = this->unitati;
	std::string pretS = std::to_string(rotoare);
	outstring += "/";
	//for (unsigned int i = 0; i < lista.size(); i++)
	//{
	//	outstring += lista[i];
	//	if (i < lista.size() - 1)
	//	{
		//	outstring += " ";
	//	}
	//}
	return outstring+"/"+pretS;
}

int Drona::getRotoare() {

	return rotoare;
}

void Drona::setRotoare(int l) {

	rotoare = l;

}

Drona& Drona::operator=(const Drona& m) {

	this->Gadget::operator=(m);
	this->setRotoare(m.rotoare);
	return *this;
}

bool Drona::operator==(const Drona& m) {

	return (Gadget::operator==(m) && (this->rotoare == m.rotoare));
}
ostream& operator<<(ostream& os, const Drona& m)
{
	os <<  m.producator << " ";
	os <<  m.model << " ";
	os <<  m.unitati << " ";
	os <<  m.rotoare << endl;;
	//for (auto i = m.rotoare.begin(); i != m.rotoare.end(); ++i)
	//	os << *i << " ";
	//os << endl;
	return os;
}
