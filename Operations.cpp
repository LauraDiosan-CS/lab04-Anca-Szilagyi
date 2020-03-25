#include "Operations.h"

Service::Service() { }

void Service::addProject(Project s) {
    repo.addElem(s);
}

int Service::findProject(Project s) {
    return repo.findElem(s);
}

void Service::delProject(Project s) {
    repo.delElem(s);
}

void Service::updateProject(Project s, char* n, int v, int u) {
    repo.updateElem(s, n, v, u);
}

//returneaza toate elementele din vector
Project* Service::getAllProjects() {
    return repo.getAll();
}

int Service::sizeee() {
    return repo.dim();
}

//destructor
Service::~Service() {
}

//returneaza elementul de pe pozitia i.
Project Service::getItemFromPosition(int i) {
    return repo.getItemFromPos(i);
}

void Service::minimumNumbers(int k, int l, Project finalList[], int& m) {
    for (int i = 0; i < repo.dim(); i++) {
        Project crtProject = repo.getItemFromPos(i);

        if ((crtProject.getNoOfBranches() >= k) && (crtProject.getNoOfCommits() >= l)) {
            finalList[m++] = crtProject;
        }
    }
}

void Service::eliminareProiecteCuRepoArray() {
    int size = repo.dim();
    //Project* proiecte[10] = new int[size];
    //proiecte = repository.getAll();

    for (int i = 0; i < size; i++)
        if (repo.getAll()[i].getNoOfBranches() * repo.getAll()[i].getNoOfCommits() == 0) {
            //Project p = proiecte[i];
            repo.delElem(repo.getAll()[i]);
        }
}

/*

//list of projects that have at least k branches and at least l commits
//a list of projects, len=the lenght of the list (int), k=minimum number of branches(int), l=minimum nr of commits(int)
//the list with the info we are looking for;
void minimumNumbers(Project projects[], int len, int k, int l, Project finalList[], int&m) {
    m = 0;
    for (int i=0; i<len; i++)
        if ((projects[i].getNoOfBranches() >= k) && (projects[i].getNoOfCommits() >= l)) {
            finalList[m] = projects[i];
            m++;
        }
}

//list of projects that have at least k branches and at least l commits
//a list of projects, len=the lenght of the list (int), k=minimum number of branches(int), l=minimum nr of commits(int)
//the list with the info we are looking for
void minimumNumbersWithRepoArray(RepositoryArray& repo, int k, int l, Project finalList[], int& m) {
    for (int i = 0; i < repo.dim(); i++) {
        Project crtProject = repo.getItemFromPos(i);

        if ((crtProject.getNoOfBranches()>=k) && (crtProject.getNoOfCommits() >= l)) {
            finalList[m++] = crtProject;
        }
    }
}


//list of projects that have at least k branches and at least l commits
//a list of projects, len=the lenght of the list (int), k=minimum number of branches(int), l=minimum nr of commits(int)
//the list with the info we are looking for
void minimumNumbersWithRepoSTL(RepositorySTL& rep, int k, int l, vector<Project>& finalList){
    for (int i = 0; i < rep.dim(); i++) {
        Project crtProject = rep.getItemFromPos(i);

        if ((crtProject.getNoOfBranches() >= k) && (crtProject.getNoOfCommits() >= l)) {
            finalList.push_back(rep.getItemFromPos(i));
        }
    }
    
}

//eliminarea proiectelor care au noOfBranches*noOfCommits=0
//lista de poiecte, lungimea listei (int)
void eliminareProiecte(Project projects[], int len) {
    for (int i = 0; i < len; i++)
        if (projects[i].getNoOfBranches() * projects[i].getNoOfCommits() == 0) {
            projects[i] = projects[len - 1];
            len--;
        }
}

void eliminareProiecteCuRepoArray(RepositoryArray& repository) {
    int size = repository.dim();
    //Project* proiecte[10] = new int[size];
    //proiecte = repository.getAll();

    for (int i = 0; i < size; i++) 
        if (repository.getAll()[i].getNoOfBranches() * repository.getAll()[i].getNoOfCommits() == 0) {
            //Project p = proiecte[i];
            repository.delElem(repository.getAll()[i]);
        }
}
*/

