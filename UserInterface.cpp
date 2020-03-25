/*#include "Operations.h"

UserInterface::UserInterface() { Service service; }

void UserInterface::menu(int &option) {
    cout << "Welcome!" << endl;
    cout << "1. Add a project" << endl;
    cout << "2. Delete a project" << endl;
    cout << "3. Update a project" << endl;
    cout << "4. Show all the projects" << endl;
    cout << "5. Show all the projects with a minimum no of branches and commits" << endl;
    cout << "6. Delete all the projects with branches*commits=0" << endl;
    cout << "7. Exit program" << endl;
    cout << "Your option: ";
    cin >> option;
}

void UserInterface::createProject(char*& gitPath, int& branches, int& commits) {
    cout << "Git PATH: ";
    cin >> gitPath;
    cout << "Number of branches: ";
    cin >> branches;
    cout << "Number of commits: ";
    cin >> commits;
    Project p;
    p = Project(gitPath, branches, commits);
}
void UserInterface::adaugare(Project p) {

    service.addProject(p);
    cout << "The project has been added!" << endl;
}

void UserInterface::stergere(Project s) {
    service.delProject(s);
    cout << "The project has been deleted!" << endl;
}

void UserInterface::update(Project s, char* n, int v, int u) {
    service.updateProject(s, n, v, u);
    cout << "The project has been updated!" << endl;
}

//returneaza toate elementele din vector
Project* UserInterface::getAllProjects() {
    for (int i = 0; i < service.sizeee(); i++) {
        cout << service.getItemFromPosition(i).getGitPath() << service.getItemFromPosition(i).getNoOfBranches();
        cout << service.getItemFromPosition(i).getNoOfCommits() << endl;
    }
}

//destructor
UserInterface::~UserInterface() {
}

void UserInterface::minimumNumbers(int& k, int& l, Project finalList[], int& m) {
    cout << "Introduceti numarul minim de branches: ";
    cin >> k;
    cout << "Introduceti numarul minim de commits: ";
    cin >> l;

    service.minimumNumbers(k, l, finalList, m);
    for (int i = 0; i < m; i++) {
        cout << finalList[i].getGitPath() << finalList[i].getNoOfBranches();
        cout << finalList[i].getNoOfCommits() << endl;
    }
}

void UserInterface::eliminareProiecteCuRepoArray() {
    service.eliminareProiecteCuRepoArray();
}*/