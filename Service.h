#pragma once
#include "Repo.h"
#include "RepoFile.h"
#include "ValidareGadget.h"
#include<iostream>
#include "Service.h"
#include<string>
#include "MyException.h"
#include "Serializable.h"
using namespace std;
template <class T>
class Service {
private:
	Repo<Gadget&>& r;
	ValidareGadget& v1;
	ValidareGadget& v2;
public:
	Service(Repo<Gadget&>& repo, ValidareGadget& valid1, ValidareGadget& valid2) :r(repo), v1(valid1), v2(valid2) { r = repo; v1 = valid1; v2 = valid2; };
	~Service();
	void addElem(T t);
	int delElem(int);
	int updateElem(int, T);
	int getSize();
	Gadget& find(int i);
	map<int, Gadget&> showElem();
	map<int, Gadget&> show(string);
	string getType(T);
};
template<class T> Service<T>::~Service() {

}
template<class T> void Service<T>::addElem(T t) {

	if (getType(t).compare(typeid(Drona).name()) == 0) {

		v1.validareGadget(t);
	}
	else {
		v2.validareGadget(t);
	}

	r.addElem(t);


}
template<class T> int Service<T>::delElem(int i)
{
	if (r.delElem(i) == -1)
		throw MyException("Acest element nu exista.");
	return 0;

}
template<class T> int Service<T>::updateElem(int i, T t) {

	if (r.updateElem(i, t) == -1)
		throw MyException("Acest element nu exista.");
	return 0;
}
template<class T> int Service<T>::getSize() {

	return r.getSize();
}
template<class T> map<int, Gadget&> Service<T>::showElem() {

	return r.getAll();
}
template<class T> Gadget& Service<T>::find(int i) {

	return r.find(i);
}
template<class T> map<int, Gadget&> Service<T>::show(string username) {

	int key = 0;
	map<int, Gadget&> elem;
	elem = r.getAll();
	map<int, Gadget&> rez;
	for (auto i = elem.begin(); i != elem.end(); i++) {
		string ch_username = i->second.getProducator();
		if (username.compare(ch_username) == 0) {
			rez.insert(pair<int, Gadget&>(key++, i->second));

		}
	}
	return rez;
}
template<class T> string Service<T>::getType(T t) {

	return typeid(t).name();
}