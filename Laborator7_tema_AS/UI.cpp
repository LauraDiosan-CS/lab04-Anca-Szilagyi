#include "UI.h"
#include <iostream>
#include<string.h>
using namespace std;

void UI::adaugareMasina() {
	Masina masinaMagica;
	cout << "Introduceti informatiile despre masina: "<<endl;
	cin >> masinaMagica;
	try {
		s.addCar(masinaMagica);
		cout << "Masina a fost adaugata cu succes" << endl;
	}
	catch (exception e) { cout << "Am intampinat o eroare..." << "->"; cout << e.what(); }
}



void UI::gasireMasina() {
	Masina masinaMagica;
	cout << "Introduceti informatiile despre masina: " << endl;
	cin >> masinaMagica;
	int rez = s.findElem(masinaMagica);
	if (rez >= 0) cout << "Masina nu a fost gasita!" << endl;
	else cout << "Masina nu a fost gasita!" << endl;
}

void UI::stergereMasina() {
	Masina masinaMagica;
	cout << "Introduceti informatiile despre masina: " << endl;
	cin >> masinaMagica;
	try {
		int rez = s.delCar(masinaMagica);
		if (rez == 0) cout << "Masina a fost stearsa!" << endl;
	}
	catch (exception e) { cout << "Am intampinat o eroare..." << " -> "; cout << e.what(); }
}

void UI::showThemAll() {
	list <Masina>::iterator it;
	for (int i = 0; i < s.getSize(); i++)
	{
		cout << s.getItemFromPos(i).getNume() << " " << s.getItemFromPos(i).getNumar() << " " << s.getItemFromPos(i).getStatus() << endl;
	}
}
void UI::intrareMasina() {
	cout << s.size() << endl;

	char* c = new char[10];
	cout << "Introduceti numarul de inmatriculare:  ";
	cin >> c;
	list<Masina> el = s.getAll();
	list<Masina>::iterator it;
	int ok = 0;
	for (it = el.begin(); it != el.end(); ++it)
	{
		if (strcmp((*it).getNumar(), c) == 0)
		{

			ok++;
			try {
				s.intrare(*it);
			}
			catch (exception e) {
				cout << "Am intampinat o eroare..." << "->"; cout << e.what();
			}
		}
	}
	if (ok == 0) cout << "Masina nu este in repository.";
	delete[] c;
}
void UI::iesireMasina() {
	cout << s.size() << endl;
	char* c = new char[10];
	cout << "Introduceti numarul de inmatriculare:  ";
	cin >> c;
	list<Masina> el = s.getAll();
	list<Masina>::iterator it;
	int ok = 0;
	for (it = el.begin(); it != el.end(); ++it)
	{
		if (strcmp((*it).getNumar(), c) == 0)
		{

			ok++;
			try {
				s.iesire(*it);
			}
			catch (exception e) {
				cout << "Am intampinat o eroare..." << "->"; cout << e.what();
			}
		}
	}
	if (ok == 0) cout << "Masina nu exista.";
	delete[] c;
}

void UI::updateMasina() {
	Masina masinaMagica;
	cout << "Introduceti informatiile curente despre masina: " << endl;
	cin >> masinaMagica;
	char* nameToIntro = new char[10];
	char* nrInmatriculare = new char[10];
	char* st = new char[10];
	int rez = s.findElem(masinaMagica);
	if (rez >= 0) {
		cout << "Numele posesorului: ";
		cin >> nameToIntro;
		cout << "Numarul de inmatriculare: ";
		cin >> nrInmatriculare;
		int ok = 0;
		while (ok == 0) {
			cout << "Status (liber sau ocupat): " << endl;
			cin >> st;
			if ((strcmp(st, "liber") == 0) or (strcmp(st, "ocupat") == 0)) ok = 1;
		}
		s.updateCar(masinaMagica, nameToIntro, nrInmatriculare, st);
		cout << "Masina -> update -> well done!";
	}
	else { cout << "Masina nu a fost gasita!"; }
	delete[] nameToIntro;
	delete[] nrInmatriculare;
	delete[] st;
}

void UI::showUI()
{
	bool gata = false;
	cout << endl;
	cout << "Bine ati venit! :)" << endl;
	cout << endl;
	cout << "1. Adaugare masina" << endl;
	cout << "2. Cautare masina" << endl;
	cout << "3. Stergere masina" << endl;
	cout << "4. Update masina" << endl;
	cout << "5. Vizualizarea tuturor masinilor" << endl;
	cout << "6. Intrare masina in parcare" << endl;
	cout << "7. Iesire masina din parcare" << endl;
	cout << "8. Numarul cu care se depaseste capacitatea de intrare intre o intrare si o iesire cu succes" << endl;
	cout << "9. Setare capacitate maxima in parcare! Este esential de facut la inceput" << endl;
	cout << "0. Iesire din program" << endl;
	while (!gata) {
		cout << endl<<"Optiunea dumneavoastra:  ";

		int yourOption;
		cin >> yourOption;
		cout << endl<<endl;
		switch (yourOption) {
		case 1: {adaugareMasina(); break; }
		case 2: {gasireMasina(); break; }
		case 3: {stergereMasina(); break; }
		case 4: {updateMasina(); break; }
		case 5: {showThemAll(); break; }
		case 6: {intrareMasina(); break; }
		case 7: {iesireMasina(); break; }
		case 8: {cout << "Numarul de masini: " << s.maxCars() << endl; break; }
		case 9: {cout << "Introduceti nr maxim de locuri din parcare: "; int i; cin >> i; try { s.setMax(i); } catch (exception e) { cout << "Am intampinat o eroare..." << "->"; cout << e.what(); } break; }
		case 0: {gata = true; cout << "O zi buna!" << endl; }
		}
	}
}
UI::~UI()
{

}