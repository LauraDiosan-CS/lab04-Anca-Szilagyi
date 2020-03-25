#include <iostream>
#include "Tests.h"
//#include "UserInterface.h"
#include "Project.h"
using namespace std;
int option, commits,branches;
char* gitPath;
Project p;

int main() {
	cout << "Se verifica testele... " << endl;
	repositoryArrayTests();
	testeService();
	cout << "Testele au fost verificate cu succes!" << endl;



/*	UserInterface emoji();

	emoji.menu(option);

	cin >> option;

	do {
		if (option == 1) {
			cout << "Introduce info about project:" << endl;
			p = emoji.createProject(gitPath, branches, commits);
			emoji.addProject(p);
		}
		else if (option == 2) {
			cout << "Introduce info about project you want to remove from list: " << endl;
			Project p2 = emoji.createProject(gitPath, branches, commits);
			emoji.stergere(p);
		}
		else if (option == 3) {
			cout << "We do not have this option temporary!" << endl;
		}
		else if (option == 4) {
			emoji.getAllProjects();
		}
		else if (option == 5) {
			emoji.minimumNumbers();
		}
		else if (option == 6) {
			emoji.eliminareProiecteCuRepoArray();
		}
		else
			cout << "Thank you!" << endl;
		cin >> option;
	} while (option <= 6);
	*/
	return 0;
}