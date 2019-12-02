#pragma once
#include "Jeziora.h"
#include <iostream>
#include <vector>
using namespace std;
class Odplywowe :
	public Jeziora
{
private:
	int ilosc_odplywow;
protected:
	string najdluzszy_odplyw;
public:
	Odplywowe(string, string, int, float, bool, int, int, int, string);
	int getOdplywy();
	void setOdplywy(int);
	void dodaj(vector <Odplywowe>& wektor, Odplywowe objekt);
	void usun(vector <Odplywowe>& wektor, int position);
	void show();
	void modyfikuj(string, string, int, float, bool, int, int, int, string);
	void zapisz(string);
};

