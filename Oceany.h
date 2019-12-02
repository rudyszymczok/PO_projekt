#pragma once
#include "Slone.h"
#include <iostream>
#include <vector>
using namespace std;
class Oceany :
	public Slone
{
private:
	int powierzchnia;
protected:
	int glebokosc;
public:
	Oceany(string,string, int, float, bool, int, int);
	int getPowierzchnia();
	void setPowierzchnia(int);
	void dodaj(vector <Oceany>& wektor, Oceany objekt);
	void usun(vector <Oceany>& wektor, int position);
	void show();
	void modyfikuj(string, string, int, float, bool, int, int);
	void zapisz(string);

};

