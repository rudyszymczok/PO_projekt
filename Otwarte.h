#pragma once
#include "Morza.h"
#include <iostream>
#include <vector>
using namespace std;
class Otwarte :
	public Morza
{
private:
	int ilosc_odplywow;
protected:
	string najdluzszy_odplyw;
public:
	Otwarte(string, string, int, float, bool, int, int, int, string);
	int getOdplywy();
	void setOdplywy(int);
	void dodaj(vector <Otwarte> &wektor, Otwarte objekt);
	void usun(vector <Otwarte> &wektor, int position);
	void show();
	void modyfikuj(string, string, int, float, bool, int, int, int, string);
	void zapisz(string);
};

