#include"Tests.h"
#include"RepositoryTemplate.h"

int main() {
	cout << "Se verifica testele..." << endl;
	Tests test;
	test.testDomain();
	test.testRepositoryTemplate();

	
	cout << "Testele au fost verificate cu succes. :)" << endl;

	return 0;
}