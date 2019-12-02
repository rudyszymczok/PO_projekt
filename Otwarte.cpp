#include "Otwarte.h"
#include "Morza.h"
#include <iostream>
#include <fstream>
using namespace std;

Otwarte::Otwarte(string n = "nazwa",string a = "morze_otwarte", int b = 10,
	float c = 0.05, bool d = false, int e = 5, int f = 5, int g = 2, string h = "odplyw")
	:Morza(n,a, b, c, d, e, f)
{
	ilosc_odplywow = g;
	najdluzszy_odplyw = h;
}
int Otwarte::getOdplywy()
{
	return ilosc_odplywow;
}
void Otwarte::setOdplywy(int a)
{
	ilosc_odplywow = a;
}
void Otwarte::dodaj(vector <Otwarte>& wektor, Otwarte objekt)
{
	/*auto pos = wektor.end();
	pos = wektor.insert(pos, *this);*/
	wektor.push_back(objekt);
}
void Otwarte::usun(vector <Otwarte>& wektor, int position)
{
	wektor.erase(wektor.begin() + position);
}
void Otwarte::show()
{
	cout << endl << "Nazwa: " << name;
	cout << endl << "Typ zbiornika: " << getTyp();
	cout << endl << "Ilosc wody: " << ilosc_wody << "m3";
	cout << endl << "Zasolenie: " << getZasolenie() << "%";
	czystosc ? cout << endl << "Zbiornik czysty: TAK " : cout << endl << "Zbiornik czysty: NIE ";
	cout << endl << "Ilosc odplywow: " << ilosc_odplywow;
	cout << endl << "Najdluzszy odplyw: " << najdluzszy_odplyw;
	cout << endl << "Glebokosc: " << glebokosc << "m";
	cout << endl << "Powierzchnia: " << getPowierzchnia() << "m2";
}
void Otwarte::modyfikuj(string n, string a, int b, float c, bool d, int e, int f, int g, string h)
{
	name = n;
	setTyp(a);
	ilosc_wody = b;
	setZasolenie(c);
	czystosc = d;
	setPowierzchnia(e);
	glebokosc = f;
	setOdplywy(g);
	najdluzszy_odplyw = h;
}
void Otwarte::zapisz(string plik)
{
	fstream plik_out;
	plik_out.open(plik, ios::out | ios::app);
	if (plik_out.good() == true)
	{
		plik_out << "Otwarte" << endl;
		plik_out << name << " ";
		plik_out << getTyp() << " ";
		plik_out << ilosc_wody << " ";
		plik_out << getZasolenie() << " ";
		plik_out << czystosc << " ";
		plik_out << getPowierzchnia() << " ";
		plik_out << glebokosc << " ";
		plik_out << getOdplywy() << " ";
		plik_out << najdluzszy_odplyw << " ";
		plik_out << endl;
	}
	plik_out.close();
}