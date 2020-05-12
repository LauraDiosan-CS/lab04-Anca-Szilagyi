#include "UI.h"
#include "Service.h"
#include "Drona.h"
#include "Telefon.h" 
#include"ValidareGadget.h"
#include "ValidareDrona.h"
#include "ValidareTelefon.h"
#include "Login.h"
#include "RepoCSV.h"
#include "RepoHTML.h"
#include "MyException.h"
void UI::choseFile() {
	int o;
	cout << "Alegeti tipul de fisier cu care doriti sa lucrati (csv/html): \n";
	cout << "1.Fisier CSV \n";
	cout << "2.Fisier HTML" << endl;
	cin >> o;
	if (o == 1) {
		cout << "Ati ales fisierul de tip CSV." << endl;
		cout << "Ne bucuram de aceasta alegere..." << endl;
		
		RepoCSV<Gadget&>& r = *new RepoCSV<Gadget&>("Gadgets.csv");
		ValidareDrona& vm = *new ValidareDrona;
		ValidareTelefon& vs = *new ValidareTelefon;
		Service<Gadget&>* s = new Service<Gadget&>(r, vm, vs);
		this->s = s;
	}
	else if (o == 2) {
		RepoHTML<Gadget&>& r = *new RepoHTML<Gadget&>("Gadgets.html");
		ValidareDrona& vm = *new ValidareDrona;
		ValidareTelefon& vs = *new ValidareTelefon;
		Service<Gadget&>* s = new Service<Gadget&>(r, vm, vs);
		this->s = s;
	}
	else if (o == 11) exit(0);
	else {
		cout << "Optiune invalida!" << endl;
		choseFile();
	}
}
void UI::addGadgetDrona() {

	char producator[10];
	string model;
	string cuv;
	int unitati, rotoare;
	cout << "Producator: "; cin >> producator;
	cout << "Model: "; std::getline(std::cin >> std::ws, model);
	cout << "Unitati: "; cin >> unitati;
	cout << "Rotoare: "; cin >> rotoare;

	Drona* m = new Drona(producator, model, unitati, rotoare);
	s->addElem(*m);

}

void UI::addGadgetTelefon() {

	char producator[10];
	string model;
	string cuv;
	int unitati;
	vector<string> operatoriGSM;
	int n;
	cout << "Producator: "; cin >> producator;
	cout << "Model: "; std::getline(std::cin >> std::ws, model);
	cout << "Unitati: "; cin >> unitati;
	cout << "- Lista operatori GSM compatibili - \n";
	cout << "Numar operatori: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Operator " << " " << i + 1 << ":";
		cin >> cuv;
		operatoriGSM.push_back(cuv);
	}

	Telefon* sp = new Telefon(producator, model, unitati, operatoriGSM);
	s->addElem(*sp);
}
void UI::showGadgets() {

	map<int, Gadget&> elem;
	elem = s->showElem();
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << " " << endl;
		cout << "GADGET" << " " << (i->first)+1<<": ";
		cout << (i->second).toStringCSV() << endl;
		//cout << (i->second).toStringCSV() << endl;
	}
}


void UI::deleteGadgetDrona() {
	int pos;
	cout << "Dati pozitia gadgetului pe care doriti sa il stergeti: "; cin >> pos;
	try {
		s->delElem(pos-1);
		cout << "Elementul a fost sters cu succes.";
	}
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

}
void UI::updateGadgetDrona() {
	int pos;
	char producator[10];
	string model;
	string cuv;
	int unitati, rotoare, n;
	cout << "Dati pozitia gadgetului pe care doriti sa il modificati: "; cin >> pos;
	cout << "Producator: "; cin >> producator;
	cout << "Model: "; std::getline(std::cin >> std::ws, model);
	cout << "Unitati: "; cin >> unitati;
	cout << "Lista Preparate \n"; cin >> rotoare;
	cout << "Numar preparate: "; cin >> n;

	Drona *m = new Drona(producator, model, unitati, rotoare);
	try {
		s->updateElem(pos, *m);
		cout << "Elementul a fost modificat cu succes.";
	}
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

}
void UI::updateGadgetTelefon() {

	int pos;
	char producator[10];
	string model;
	string cuv;
	int unitati;
	vector<string> operatoriGSM;
	int n;
	cout << "Dati pozitia comenzii pe care doriti sa o stergeti: " << endl; cin >> pos;
	cout << "Producator: "; cin >> producator;
	cout << "Model: "; std::getline(std::cin >> std::ws, model);
	cout << "Unitati: "; cin >> unitati;
	cout << "Lista de operatori GSM \n";
	cout << "Numar de operatori: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Operatorul " << " " << i+1 << ":";
		cin >> cuv;
		operatoriGSM.push_back(cuv);
	}
	Telefon *sp = new Telefon(producator, model, unitati, operatoriGSM);
	try {
		s->updateElem(pos, *sp);
		cout << "Elementul a fost modificat cu succes.";
	}
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

}
void UI::deleteGadgetTelefon() {
	int pos;
	cout << "Dati pozitia comenzii pe care doriti sa o stergeti: "; cin >> pos;
	try {
		s->delElem(pos);
		cout << "Elementul a fost sters cu succes.";
	}
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

}
void UI::searchByName() {
	string producator;
	cout << "Producator: "; std::getline(std::cin >> std::ws, producator);
	cout << "Gadgeturi: " << endl;
	map<int, Gadget&> elem;
	elem = s->show(producator);
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Gadget" << " " << i->first +1 << endl;
		cout << (i->second).toStringCSV() << endl;
	}



	/*string producator;
	cout << "Producator: "; std::getline(std::cin >> std::ws, producator);
	cout << "Gadgeturi de tip drona:" << endl;
	map<int, Drona&> elem;
	elem = s->show(producator);
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Drona" << " " << i->first << endl;
		cout << i->second << endl;
		//cout << (i->second).toStringCSV() << endl;
	}
	cout << "Gadgeturi de tip telefon:" << endl;
	map<int, Telefon> elem1;
	elem1 = s->show(producator);
	for (auto i = elem1.begin(); i != elem1.end(); i++) {
		cout << "Telefon" << " " << i->first << endl;
		cout << i->second << endl;
	}*/

}
void UI::login() {
	LoginManager lo;
	string username, password;
	while (!logIn) {
		cout << "---Autentificare---" << endl;
		cout << "Username: "; cin >> username;
		cout << "Password: "; cin >> password;
		logIn = lo.login(username, password);
	}
	showGadgets();

	
}
void UI::Logout() {

	logIn = false;
}
void UI::showUI() {

	choseFile();
	login();
	PrintMenu();
}

void UI::PrintMenu()
{
	cout << endl;
	while (true) {
		cout << endl;
		std::cout << "\n";
		std::cout << "--- Main Menu ---" << std::endl;
		std::cout << "Alegeti o optiune: " << std::endl;
		std::cout << "1: Adaugare drona" << std::endl;
		std::cout << "2: Stergere drona" << std::endl;
		std::cout << "3: Modificare drona" << std::endl;
		std::cout << "4: Adaugare telefon" << std::endl;
		std::cout << "5: Stergere telefon" << std::endl;
		std::cout << "6: Modificare telefon" << std::endl;
		std::cout << "7: Afisare gadgets" << std::endl;
		std::cout << "8: Cautare dupa producator" << std::endl;
		std::cout << "9: Logout" << std::endl;
		std::cout << "10: Exit" << std::endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {try { addGadgetDrona(); }
			  catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); } break; }
		case 2: {deleteGadgetDrona(); break; }
		case 3: {updateGadgetDrona(); break; }
		case 4: { try { addGadgetTelefon(); }
			  catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); } break; }
		case 5: {deleteGadgetTelefon(); break; }
		case 6: {updateGadgetTelefon();  break; }
		case 7: { showGadgets(); break; }
		case 8: { searchByName(); break; }
		case 9: {  Logout(); showUI(); break; }
		case 10: {  cout << "O zi minunata! :)" << endl; exit(0); }
		default: {cout << "Optiunea cu exista! Va rugam sa alegeti una dintre cele existente. :)" << endl; }
		}
	}
}
