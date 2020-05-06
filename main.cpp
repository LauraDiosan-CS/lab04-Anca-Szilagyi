#include "Pet.h"
#include <assert.h>
#include <vector>
#include "RepoTemplate.h"
#include <iostream>
using namespace std;


template <typename R>
void addPets(R& v, int cate) {
	for (int i = 0; i<cate; i++) {
		Pet p{ std::to_string(i) + "_type",std::to_string(i) + "_spec",i + 10.0 };
		v.add(p);
	}
}

/*
Testare constructori / assignment
E template pentru a refolosi la diferite variante de Repo din proiect
*/
template <typename R>
void testCreateCopyAssign() {
	R v;//default constructor
	addPets(v, 100);
	assert(v.size() == 100);
	assert(v.get(50).getType() == "50_type");
	

	R v2{ v };//constructor de copiere
	assert(v2.size() == 100);
	assert(v2.get(50).getType() == "50_type");
	addPets(v2, 1);
	assert(v.size() == 100); //cand adaugam la copie, originalul ramane la fel
	assert(v2.size() == 101);


	R v3;//default constructor
	v3 = v;//operator=   assignment
	assert(v3.size() == 100);
	assert(v3.get(50).getType() == "50_type");
	addPets(v3, 1);
	assert(v.size() == 100); //cand adaugam la copie, originalul ramane la fel
	assert(v3.size() == 101);
}

/*
Testare constructori / assignment
E template pentru a refolosi la diferite variante de Repo din proiect
*/
template <typename R>
void testCRUD() {
	R v;//default constructor
	Pet p1{ "type1", "spec1", 1.0};
	Pet p2{ "type2", "spec2", 2.0}; 
	v.add(p1); v.add(p2); // create via add
	assert(v.size() == 2);
	assert(v.get(0).getType() == "type1"); // read by index
	assert(v.get(1).getType() == "type2"); // read by index

	v.update(p1, p2); // Update, Un repo trebuie sa accepte duplicate.
	assert(v.get(0) == p2); 
	assert(v.get(1) == p2); 
	assert(v.size() == 2);

	v.remove(p2); // delete, doar primul element trebuie sters. 
	assert(v.size() == 1);
	assert(v.get(0).getType() == "type2");
}

template <typename R>
void testAll() {
	testCreateCopyAssign<R>();
	testCRUD<R>();
}

int main() {

	//Pentru a testa
	// 1. copiati fisierle relevante pentru Repo-uri din proiectul de laborator, in acest proiect
	// 2. adaugati import-urile necesare
	// 3. aici in main, adaugati apel pentru toate RepoSTL, RepoFile (si/sau RepoCSV, RepoHTML):
	//        testAll<RepoSTL<Pet>>();
	//        testAll<RepoFile<Pet>>();   ///etc...
	// La Repo cu fisiere, faceti constructorul default sa foloseasca un nume de fisier predefinit.
	// ATENTIE: 
	//    Ca sa treaca, modificati codul vostru, nu testele de aici!
	//    Nu copiati modulele voastre din model (Gym, Proiect, Masina, etc.), clasele Repo nu au voie sa depinda de ele ci sa foloseasca template pentru a stoca Pet
	cout << "Se verifica..."<<endl;
	testAll<RepoTemplate<Pet>>();
	cout << "Testele sunt ok!";
	return 0;

}