#include"Tests.h"
#include"RepoTemplate.h"
#include"Service.h"
#include"UI.h"
#include"TestFile.h"
int main() {
	cout << "Se verifica testele..." << endl;
	/*Tests test;
	test.testDomain();
	test.testRepoTemplate();
	test.testService();

	/*TestRepositoryFile testFileRepo;
	testFileRepo.testLoadFromFile();
	testFileRepo.testAddElem();
	testFileRepo.testFindElem();
	testFileRepo.testDelElem();
	testFileRepo.testGetAll();
	testFileRepo.testUpdateElem();
	testFileRepo.testElemAtPos();
	testFileRepo.testSize();*/
	cout << "Testele au fost verificate cu succes. :)" << endl;

	RepositoryFile<Masina> repo("Elem.txt");
	Service serv(repo);
	UI ui(serv);
	ui.showUI();

	return 0;
}