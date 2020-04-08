#include <iostream>
#include "Teste.h"
#include "UserInterface.h"

int main()
{
    cout << "Se verifica testele..." << endl;
    appTests();
    repositorySTLTests();
    serviceTests();
    testeRepoFile();

    cout << "Testele sunt ok! :D" << endl<<endl;

    UserInterface ui;
    ui.console();
}

