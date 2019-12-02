#include "Oceany.h"
#include <iostream>
#include <fstream>
using namespace std;

Oceany::Oceany(string n = "nazwa",string a = "ocean", int b = 10,
	float c = 2, bool d = true, int e = 5, int f = 5)
	:Slone(n,a, b, c, d)
{
	powierzchnia = e;
	glebokosc = f;
}
int Oceany::getPowierzchnia()
{
	return powierzchnia;
}
void Oceany::setPowierzchnia(int a)
{
	powierzchnia = a;
}
void Oceany::dodaj(vector <Oceany>& wektor, Oceany objekt)
{
	/*auto pos = wektor.end();
	pos = wektor.insert(pos, *this);*/
	wektor.push_back(objekt);
}
void Oceany::usun(vector <Oceany>& wektor, int position)
{
	wektor.erase(wektor.begin() + position);
}
void Oceany::show()
{
	cout << endl << "Nazwa: " << name;
	cout << endl << "Typ zbiornika: " << getTyp();
	cout << endl << "Ilosc wody: " << ilosc_wody << "m3";
	cout << endl << "Zasolenie: " << getZasolenie() << "%";
	czystosc ? cout << endl << "Zbiornik czysty: TAK " : cout << endl << "Zbiornik czysty: NIE ";
	cout << endl << "Powierzchnia: " << getPowierzchnia() << "m2";
	cout << endl << "Glebokosc: " << glebokosc << "m";
}
void Oceany::modyfikuj(string n, string a, int b, float c, bool d, int e, int f)
{
	name = n;
	setTyp(a);
	ilosc_wody = b;
	setZasolenie(c);
	czystosc = d;
	setPowierzchnia(e);
	glebokosc = f;
}
void Oceany::zapisz(string plik)
{
	fstream plik_out;
	plik_out.open(plik, ios::out | ios::app);
	if (plik_out.good() == true)
	{
		plik_out << "Oceany" << endl;
		plik_out << name << " ";
		plik_out << getTyp() << " ";
		plik_out << ilosc_wody << " ";
		plik_out << getZasolenie() << " ";
		plik_out << czystosc << " ";
		plik_out << getPowierzchnia() << " ";
		plik_out << glebokosc << " ";
		plik_out << endl;
	}
	plik_out.close();
}

