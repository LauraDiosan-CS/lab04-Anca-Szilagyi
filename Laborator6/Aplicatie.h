#pragma once
#include<iostream>
#include<string>
using namespace std;

class Aplicatie {
private:
    char* nume;
    char* numarInmatriculare;
    char* status;
public:
    Aplicatie();
    Aplicatie(const char*, const char*, const char*);
    Aplicatie(const Aplicatie&);
    Aplicatie& operator=(const Aplicatie& app);

    char* getNume();
    char* getNrInmatriculare();
    char* getStatus();
    void setNume(const char* n);
    void setNrInmatriculare(const char*);
    void setStatus(const char*);
    bool operator==(const Aplicatie& app);

    //friendsurile alea cred ca nu prea au ce cauta aici
    ~Aplicatie(); //destructor - elibereaza toate resursele alocate de constructor
};

//constructorul poate sa aloce dinamic ceva in memorie;
//constr poate sa deschida/inchida fisiere; etc.