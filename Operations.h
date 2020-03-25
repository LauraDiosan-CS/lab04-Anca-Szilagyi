#include "Project.h"
#include "RepositoryArray.h"

class Service {
private:
	RepositoryArray repo;
public:
	Service();
	void addProject(Project);
	int findProject(Project);
	Project getItemFromPosition(int);
	void delProject(Project);
	void updateProject(Project, char*, int, int);
	Project* getAllProjects();
	int sizeee();
	void minimumNumbers(int k, int l, Project finalList[], int& m);
	void eliminareProiecteCuRepoArray();

	~Service();
};