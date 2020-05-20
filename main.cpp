#include "Avion.h"
#include "Tabla.h"
#include "Joc.h"
using namespace std;
int tab[100][100];
int op;
int main() {
	cout << "All good in here!" << endl;
	//cout<<"1. incepe jocul"<<endl;
	//cout << "2. adaugare avion" << endl;
	//cin >> op;
	//if (op == 1) {
		Avion a1(3, 1, "l");
		Tabla t1(6, 6, tab);
		vector<Avion> planes;
		planes.push_back(a1);
		/*cout << "X varf: " << endl;
		int xVarf, yVarf;
		string poz;
		cin >> xVarf;
		cout << "yVarf: ";
		cin >> yVarf;
		cout << "directia(l, r, u, d) ";
		cin >> poz;
		Avion a2(xVarf, yVarf, poz);
		//planes.push_back(a2);*/
		Joc game(t1, planes);
		for (int i = 1; i <= game.getLin(); i++) {
			for (int j = 1; j <= game.getCol(); j++)
				cout << game.getItemFromPos(i, j) << " ";
			cout << endl;
		}
	//}
	/*else {
		cout << "X varf: " << endl;
		int xVarf, yVarf;
		string poz;
		cin >> xVarf;
		cout << "yVarf: ";
		cin >> yVarf;
		cout << "directia(l, r, u, d) ";
		cin >> poz;
		Avion a2(xVarf, yVarf, poz);

	}*/
	//for(int i=1; i<=game.t1.getLinii(); i++)
		//for
	//cout << game;
	return 0;
}