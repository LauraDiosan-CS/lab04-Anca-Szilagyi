#include "Tests.h"
#include "Project.h"
#include "Operations.h"
#include "assert.h"
#include "RepositoryArray.h"
#include <iostream>
using namespace std;

/*void minimumNumberTest() {

	Project s1("Lab04.AnaMaria", 5, 3);
	Project s2("Lab04.Marina", 6, 9);
	Project s3("Lab05.VictorPopescu", 3, 1);
	Project s4("Lab06.MarianVoicu", 0, 3);
	Project projects[4] = { s1, s2,s3, s4 };
	Project results[4];
	int m = 0;
	//serv.minimumNumbers(projects, 4, 4, 3, results, m);

	assert((m == 2) && (results[0] == s1) && (results[1] == s2));
}

void minimumNumberTestWithRepoArray() {
	Project s1("Lab04.AnaMaria", 5, 3);
	Project s2("Lab04.Marina", 6, 9);
	Project s3("Lab05.VictorPopescu", 3, 1);
	Project s4("Lab06.MarianVoicu", 0, 3);
	RepositoryArray rep;
	rep.addElem(s1);
	rep.addElem(s2);
	rep.addElem(s3);
	rep.addElem(s4);
	Project results[10];
	int m = 0;
	minimumNumbersWithRepoArray(rep, 5, 3, results, m);
	assert((m == 2) && (results[0] == s1) && (results[1] == s2));
}*/

void repositoryArrayTests() {
	Project p1("Laborator05 - student 007", 7, 3);
	Project p2("Laborator05 - student 014", 5, 3);
	Project p3("Laborator05 - student 015", 6, 0);
	Project p4("Laborator05 - student 017", 7, 4);
	Project p5("Laborator05 - student 009", 12, 5);
	RepositoryArray repo;
	repo.addElem(p1);
	repo.addElem(p2);
	assert(repo.dim() == 2);

	repo.addElem(p3);
	repo.addElem(p4);
	assert(repo.findElem(p3) == 2);
	repo.delElem(p1);
	assert(repo.dim() == 3);

	assert(repo.getAll()[0] == p4);
}


void testeService() {
	Project p1("Laborator05 - student 007", 0, 3);
	Project p2("Laborator05 - student 014", 5, 0);
	Project p3("Laborator05 - student 015", 6, 0);
	Project p4("Laborator05 - student 017", 7, 4);
	Project p5("Laborator05 - student 009", 12, 5);
	Service serv;
	serv.addProject(p1);
	serv.addProject(p2);
	serv.addProject(p3);
	serv.addProject(p4);
	serv.addProject(p5);
	
	assert(serv.getAllProjects()[0] == p1);
	assert(serv.getItemFromPosition(1) == p2);
	assert(serv.findProject(p3) == 2);
	assert(serv.sizeee() == 5);

	serv.delProject(p5);
	assert(serv.sizeee() == 4);
	serv.addProject(p5);

	serv.eliminareProiecteCuRepoArray();
	assert(serv.findProject(p1)==-1);
	assert(serv.getItemFromPosition(1) == p4);
}


/*void eliminareCuRepoArrayTests() {
	Project p1("Laborator05 - student 007", 0, 3);
	Project p2("Laborator05 - student 014", 5, 0);
	Project p3("Laborator05 - student 015", 6, 0);
	Project p4("Laborator05 - student 017", 7, 4);
	Project p5("Laborator05 - student 009", 12, 5);
	RepositoryArray repos;
	repos.addElem(p1);
	repos.addElem(p2);
	repos.addElem(p3);
	repos.addElem(p4);
	repos.addElem(p5);
	eliminareProiecteCuRepoArray(repos);
	assert(repos.getAll()[0] == p5);
	assert(repos.getAll()[1] == p4);
}*/

