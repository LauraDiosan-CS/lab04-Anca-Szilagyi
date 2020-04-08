#include "Aplicatie.h"
#include <iostream>
#include <string.h>

//Constructor
//in: -
//out: an empty object of type Aplicatie
Aplicatie::Aplicatie() {
	nume = NULL;
	numarInmatriculare = NULL;
	status = NULL;
}


//Constructor with parameters
//IN: a name(string), un nr de intatriculare (char) and a status (char);
//OUT: an object of type Aplciatie that contains the given info
Aplicatie::Aplicatie(const char* name, const char* nrInmatriculare, const char* stat) {
	this->nume = new char[strlen(name) + 1];
	strcpy_s(this->nume, strlen(name) + 1, name);
	this->numarInmatriculare = new char[strlen(nrInmatriculare) + 1];
	strcpy_s(this->numarInmatriculare, strlen(nrInmatriculare) + 1, nrInmatriculare);
	this->status = new char[strlen(stat) + 1];
	strcpy_s(this->status, strlen(stat) + 1, stat);
}

// Copy constructor
// In: an object s of type Project
// Out: another object of type Project that contains the same info as p
Aplicatie::Aplicatie(const Aplicatie& app) {
	this->nume = new char[strlen(app.nume) + 1];
	strcpy_s(this->nume, strlen(app.nume) + 1, app.nume);
	this->numarInmatriculare = new char[strlen(app.numarInmatriculare) + 1];
	strcpy_s(this->numarInmatriculare, strlen(app.numarInmatriculare) + 1, app.numarInmatriculare);
	this->status = new char[strlen(app.status) + 1];
	strcpy_s(this->status, strlen(app.status) + 1, app.status);
}


// getter
// In: an object of type Aplciatie
// Out: name of a project
char* Aplicatie::getNume() {
	return nume;
}

char* Aplicatie::getNrInmatriculare() {
	return numarInmatriculare;
}

char* Aplicatie::getStatus() {
	return status;
}
// comparator
// In: two objects of type Project (this and p)
// Out: true or false
bool Aplicatie::operator==(const Aplicatie& p) {
	return ((strcmp(this->nume, p.nume) == 0) && (strcmp(this->numarInmatriculare, p.numarInmatriculare)==0) && (strcmp(this->status, p.status)==0));
}

// setter
// In: an object of type Aplicatie and a new name (string)
// Out: the same object with a new name
void Aplicatie::setNume(const char* newName) {
	if (nume) {
		delete[] nume;
	}
	nume = new char[strlen(newName) + 1];
	strcpy_s(this->nume, strlen(newName) + 1, newName);
}

// setter
// In: an object of type Aplicatie and a new nrInmatriculare (string)
// Out: the same object with a new nrInmatriculare
void Aplicatie::setNrInmatriculare(const char* newNo) {
	if (numarInmatriculare) {
		delete[] numarInmatriculare;
	}
	numarInmatriculare = new char[strlen(newNo) + 1];
	strcpy_s(this->numarInmatriculare, strlen(newNo) + 1, newNo);
}

void Aplicatie::setStatus(const char* newStatus) {
	if (status) {
		delete[] status;
	}
	status = new char[strlen(newStatus) + 1];
	strcpy_s(this->status, strlen(newStatus) + 1, newStatus);
}


// Desonstructor
// In: an object of type Project
// Out: -
Aplicatie::~Aplicatie() {
	if (nume) {
		delete[] nume;
		nume = NULL;
		delete[] numarInmatriculare;
		numarInmatriculare = NULL;
		delete[] status;
		status = NULL;
	}
}







/*

// setter
// In: an object of type Project and a number of branches (integer)
// Out: the same object with a new number of branches
void Project::setNoOfBranches(int a) {
	noOfBranches = a;
}

// setter
// In: an object of type Project and a number of commits (integer)
// Out: the same object with a new number of commits
void Project::setNoOfCommits(int b) {
	totalNoOfCommits = b;
}

// assignment operator
// In: two objects of type Project (the current one, this, and p)
// Out: the new state of the current object (this)
Aplicatie& Aplicatie::operator=(const Aplicatie& p) {
	if (this == &p) return *this;
	if (nume) delete[] nume;
	gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(gitPath, strlen(p.gitPath) + 1, p.gitPath);
	noOfBranches = p.noOfBranches;
	totalNoOfCommits = p.totalNoOfCommits;
	//this->setGitPath(p.gitPath);
	//this->setNoOfBranches(p.noOfBranches);
	//this->setNoOfCommits(p.totalNoOfCommits);
	return *this;
}*/
