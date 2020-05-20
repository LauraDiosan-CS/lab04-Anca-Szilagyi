#pragma once
#include<string>
#include<iostream>
using namespace std;
class Avion {
private:
	int xVarf;
	int yVarf;
	string orientare;
	//u=up, d=down, l=left, r=right
public:
	Avion();
	Avion(int x, int y, string orientare);
	Avion(const Avion& a);
	~Avion();
	int getX();
	int getY();
	string getOrientareCoada();
	void setX(int x);
	void setY(int y);
	void setOrientareCoada(string orientare);
	Avion& operator=(const Avion& a);
	bool operator==(const Avion&);
	friend ostream& operator<<(ostream& os, const Avion& c);
};