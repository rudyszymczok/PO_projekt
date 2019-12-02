#pragma once
#include "Slodkie.h"
#include <iostream>
#include <vector>
using namespace std;
class Rzeki :
	public Slodkie
{
private:
	int dlugosc;
	int szerokosc;
protected:
	int glebokosc;
public:
	Rzeki(string, string, int, float, bool, int, int, int);

	int getDlugosc();
	int getSzerokosc();

	void setDlugosc(int);
	void setSzerokosc(int);

	void dodaj(vector <Rzeki>& wektor, Rzeki objekt);
	void usun(vector <Rzeki>& wektor, int position);
	void show();
	void modyfikuj(string, string, int, float, bool, int, int, int);
	void zapisz(string);

	Rzeki operator+(Rzeki a)
	{
		Rzeki tmp("", "", 0, 0, false, 0, 0, 0);
		if (a.getTyp() == this->getTyp())
		{
			tmp.setTyp(a.getTyp());
		}
		else
		{
			tmp.setTyp("Brak_zgodnosci");
		}
		tmp.name.append(this->name);
		tmp.name.append("+");
		tmp.name.append(a.name);
		
		tmp.ilosc_wody = this->ilosc_wody + a.ilosc_wody;
		tmp.setZasolenie(this->getZasolenie() + a.getZasolenie());
		if ((this->czystosc == true) || (a.czystosc == true))
		{
			tmp.czystosc = true;
		}
		tmp.setDlugosc(this->getDlugosc() + a.getDlugosc());
		tmp.setSzerokosc(this->getSzerokosc() + a.getSzerokosc());
		tmp.glebokosc = this->glebokosc + a.glebokosc;

		return tmp;
		
	}


};

