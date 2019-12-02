#include "Bezodplywowe.h"
#include "Jeziora.h"
#include <iostream>
#include <fstream>
using namespace std;

Bezodplywowe::Bezodplywowe(string n = "nazwa",string a = "jezioro_bezodplywowe", int b = 10,
	float c = 0.05, bool d = false, int e = 5, int f = 5, int g = 0, string h = "nazwa")
	:Jeziora(n,a, b, c, d, e, f)
{
	ilosc_odplywow = g;
	nazwa_zarzadcy = h;
}
int Bezodplywowe::getOdplywy()
{
	return ilosc_odplywow;
}
void Bezodplywowe::setOdplywy(int a)
{
	ilosc_odplywow = a;
}
void Bezodplywowe::dodaj(vector <Bezodplywowe>& wektor, Bezodplywowe objekt)
{
	/*auto pos = wektor.end();
	pos = wektor.insert(pos, *this);*/
	wektor.push_back(objekt);
}
void Bezodplywowe::usun(vector <Bezodplywowe>& wektor, int position)
{
	wektor.erase(wektor.begin() + position);
}
void Bezodplywowe::show()
{
	cout << endl << "Nazwa: " << name;
	cout << endl << "Typ zbiornika: " << getTyp();
	cout << endl << "Ilosc wody: " << ilosc_wody << "m3";
	cout << endl << "Zasolenie: " << getZasolenie() << "%";
	czystosc ? cout << endl << "Zbiornik czysty: TAK " : cout << endl << "Zbiornik czysty: NIE ";
	cout << endl << "Ilosc odplywow: " << ilosc_odplywow;
	cout << endl << "Zarz¹dca: " << nazwa_zarzadcy;
	cout << endl << "Glebokosc: " << glebokosc << "m";
	cout << endl << "Powierzchnia: " << getPowierzchnia() << "m2";

}
void Bezodplywowe::modyfikuj(string n, string a, int b, float c, bool d, int e, int f, int g, string h)
{
	name = n;
	setTyp(a);
	ilosc_wody = b;
	setZasolenie(c);
	czystosc = d;
	setPowierzchnia(e);
	glebokosc = f;
	setOdplywy(g);
	nazwa_zarzadcy = h;
}
void Bezodplywowe::zapisz(string plik)
{
	fstream plik_out;
	plik_out.open(plik, ios::out | ios::app);
	if (plik_out.good() == true)
	{
		plik_out << "Bezodplywowe" << endl;
		plik_out << name << " ";
		plik_out << getTyp() << " ";
		plik_out << ilosc_wody << " ";
		plik_out << getZasolenie() << " ";
		plik_out << czystosc << " ";
		plik_out << getPowierzchnia() << " ";
		plik_out << glebokosc << " ";
		plik_out << getOdplywy() << " ";
		plik_out << nazwa_zarzadcy << " ";
		plik_out << endl;
	}
	plik_out.close();
}
