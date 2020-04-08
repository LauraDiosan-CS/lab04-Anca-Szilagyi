#include "UserInterface.h"
#include <iostream>
using namespace std;

UserInterface::UserInterface() {
}

void UserInterface::menu() {
    cout << "Welcome!" << endl;
    cout << "1. Adaugare masina" << endl;
    cout << "2. Stergere masina" << endl;
    cout << "3. Update masina" << endl;
    cout << "4. Vizualizarea tuturor masinilor" << endl;
    cout << "5. Iesire din program" << endl;
}

void UserInterface::adaugare() {
    cout << "Introduceti informatii despre masina pe care vrei sa o adaugati: " << endl;
    cout << "Numele posesorului autoturismului: ";
    char* nume = new char[10];
    cin >> nume;

    cout << "Numarul de inmatriculare: ";
    char* numarInmatriculare = new char[10];
    cin >> numarInmatriculare;

    cout << "Ocupat sau liber: ";
    char* status = new char[10];
    cin >> status;

    Aplicatie p = Aplicatie(nume, numarInmatriculare, status);
    int ok;
    ok = service.addElem(p);
    if (ok == 0) {
        cout << "Masina nu a fost adaugata din cauza ca exista deja acest numar de inmatriculare ";
        cout << "sau statusul nu este 'liber' sau 'ocupat'." << endl;
    }
    else cout << "The project has been added!" << endl;
    delete[] nume;
    delete[] numarInmatriculare;
    delete[] status;
}

void UserInterface::stergere() {
    cout << "Numele posesorului: ";
    char* nume = new char[10];
    cin >> nume;

    cout << "Numarul de inmatriculare: ";
    char* nrInmatriculare = new char[10];
    cin >> nrInmatriculare;

    cout << "Status: ";
    char* status = new char[10];
    cin >> status;

    Aplicatie p = Aplicatie(nume, nrInmatriculare, status);
    service.delElem(p);
    cout << "Masina a fost stearsa!" << endl;
    delete[] nume;
    delete[] nrInmatriculare;
    delete[] status;
}

void UserInterface::update() {
    cout << "Informatiile curente: " << endl;
    cout << "Nume: ";
    char* nume = new char[10];
    cin >> nume;
    cout << "Numarul de inmatriculare: ";
    char* nrInm = new char[10];
    cin >> nrInm;
    cout << "Status: ";
    char* status = new char[10];
    cin >> status;

    Aplicatie current = Aplicatie(nume, nrInm, status);

    delete[] nume;
    delete[] nrInm;
    delete[] status;

    cout << "Noile informatii: " << endl;
    cout << "Noul nume: ";
    char* newName = new char[10];
    cin >> newName;

    cout << "Noul nr de inmatriculare: ";
    char* newNumber = new char[10];
    cin >> newNumber;

    cout << "Noul status: ";
    char* newStatus = new char[10];
    cin >> newStatus;
    service.updateElem(current, newName, newNumber, newStatus);
    cout << "The project has been updated!" << endl;
    delete[] newName;
    delete[] newNumber;
    delete[] newStatus;
}


//returneaza toate elementele din vector
void UserInterface::getAllProjects() {
    for (int i = 0; i < service.dim(); i++) {
        cout << service.getItemFromPos(i).getNume() << " ";
        cout << service.getItemFromPos(i).getNrInmatriculare() << " ";
        cout << service.getItemFromPos(i).getStatus() << endl;
    }
}

//destructor
UserInterface::~UserInterface() {
}

void UserInterface::console() {
    bool ok = 1;
    int option;
    menu();

    while (ok) {
        cout << endl << "Optiunea dumneavoastra: ";
        cin >> option;
        cout << endl;
        switch (option) {
        case 1: {
            adaugare();
            break;
        }
        case 2: {
            cout << "Introduceti informatii despre proiectul pe care vreti sa il stergeti: " << endl;
            stergere();
            break;
        }
        case 3: {
            update();
            break;
        }
        case 4: {
            getAllProjects();
            break;
        }

        case 5: {
            cout << "Thank you!" << endl;
            ok = 0;
            break;
        }
        default: {
            cout << "This is not an option from our menu!" << endl;
            break;
        }
        }
    }
}