#pragma once
#include "Jeziora.h"
#include <iostream>
#include <vector>
using namespace std;
class Bezodplywowe :
	public Jeziora
{
private:
	int ilosc_odplywow;
protected:
	string nazwa_zarzadcy;
public:
	Bezodplywowe(string,string, int, float, bool, int, int, int, string);
	int getOdplywy();
	void setOdplywy(int);
	void dodaj(vector <Bezodplywowe>& wektor, Bezodplywowe objekt);
	void usun(vector <Bezodplywowe>& wektor, int position);
	void show();
	void modyfikuj(string, string, int, float, bool, int, int, int, string);
	void zapisz(string);
};
