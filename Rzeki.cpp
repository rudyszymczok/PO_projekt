#include "Rzeki.h"
#include <iostream>
#include <fstream>
using namespace std;

Rzeki::Rzeki(string n = "nazwa",string a = "rzeka", int b = 10,
	float c = 0.05, bool d = false, int e=5, int f=5, int g=5)
	:Slodkie(n,a, b,c,d )
{
	dlugosc=e;
	szerokosc=f;
	glebokosc=g;
}
int Rzeki::getDlugosc()
{
	return dlugosc;
}
int Rzeki::getSzerokosc()
{
	return szerokosc;
}
void Rzeki::setDlugosc(int a)
{
	dlugosc = a;
}
void Rzeki::setSzerokosc(int a)
{
	szerokosc = a;
}
void Rzeki::dodaj(vector <Rzeki>& wektor, Rzeki objekt)
{
	/*auto pos = wektor.end();
	pos = wektor.insert(pos, *this);*/
	wektor.push_back(objekt);
}
void Rzeki::usun(vector <Rzeki>& wektor, int position)
{
	wektor.erase(wektor.begin() + position);
}
void Rzeki::show() 
{
	cout << endl << "Nazwa: " << name;
	cout << endl << "Typ zbiornika: " << getTyp();
	cout << endl << "Ilosc wody: " << ilosc_wody<<"m3";
	cout << endl << "Zasolenie: " << getZasolenie()<<"%";
	czystosc ? cout << endl << "Zbiornik czysty: TAK " : cout << endl << "Zbiornik czysty: NIE ";
	cout << endl << "Dlugosc: " << dlugosc<<"m";
	cout << endl << "Szerokosc: " << szerokosc <<"m";
	cout << endl << "Glebokosc: " << glebokosc<< "m";
}
void Rzeki::modyfikuj(string n, string a, int b, float c, bool d, int e, int f, int g)
{
	name = n;
	setTyp(a);
	ilosc_wody = b;
	setZasolenie(c);
	czystosc = d;
	setDlugosc(e);
	setSzerokosc(f);
	glebokosc = g;
}
void Rzeki::zapisz(string plik)
{
	fstream plik_out;
	plik_out.open(plik, ios::out | ios::app);
	if (plik_out.good() == true)
	{
		plik_out << "Rzeki" << endl;
		plik_out << name<<" ";
		plik_out << getTyp()<<" ";
		plik_out << ilosc_wody<<" ";
		plik_out << getZasolenie()<<" ";
		plik_out << czystosc<<" ";
		plik_out << dlugosc<<" ";
		plik_out << szerokosc<<" ";
		plik_out << glebokosc<<" ";
		plik_out << endl;
	}
	plik_out.close();
}
