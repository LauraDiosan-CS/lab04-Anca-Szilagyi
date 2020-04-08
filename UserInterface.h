#pragma once
#include "Aplicatie.h"
#include "RepositorySTL.h"
#include "Service.h"

class UserInterface {
private:
	Service service;

	void menu();
	void adaugare();
	void stergere();
	void update();
	void getAllProjects();

public:
	UserInterface();
	void console();

	~UserInterface();
};
