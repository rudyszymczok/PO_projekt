#include "Zamkniete.h"
#include "Morza.h"
#include <iostream>
#include <fstream>
using namespace std;

Zamkniete::Zamkniete(string n="nazwa",string a = "morze_zamkniete", int b = 10,
	float c = 0.05, bool d = false, int e = 5, int f = 5, int g = 100, bool h = false)
	:Morza(n,a, b, c, d, e, f)
{
	linia_brzegowa = g;
	czy_port = h;
}
int Zamkniete::getLinia()
{
	return linia_brzegowa;
}
void Zamkniete::setLinia(int a)
{
	linia_brzegowa = a;
}
void Zamkniete::dodaj(vector <Zamkniete>& wektor, Zamkniete objekt)
{
	/*auto pos = wektor.end();
	pos = wektor.insert(pos, *this);*/
	wektor.push_back(objekt);
}
void Zamkniete::usun(vector <Zamkniete>& wektor, int position)
{
	wektor.erase(wektor.begin() + position);
}
void Zamkniete::show()
{
	cout << endl << "Nazwa: " << name;
	cout << endl << "Typ zbiornika: " << getTyp();
	cout << endl << "Ilosc wody: " << ilosc_wody << "m3";
	cout << endl << "Zasolenie: " << getZasolenie() << "%";
	czystosc ? cout << endl << "Zbiornik czysty: TAK " : cout << endl << "Zbiornik czysty: NIE ";
	cout << endl << "Dlugosc linii brzegowej: " << linia_brzegowa << "m";
	czy_port ? cout << endl << "Czy posiada port: TAK " : cout << endl << "Czy posiada port: NIE ";
	cout << endl << "Glebokosc: " << glebokosc << "m";
	cout << endl << "Powierzchnia: " << getPowierzchnia() << "m2";
}
void Zamkniete::modyfikuj(string n, string a, int b, float c, bool d, int e, int f, int g, bool h)
{
	name = n;
	setTyp(a);
	ilosc_wody = b;
	setZasolenie(c);
	czystosc = d;
	setPowierzchnia(e);
	glebokosc = f;
	setLinia(g);
	czy_port = h;
}
void Zamkniete::zapisz(string plik)
{
	fstream plik_out;
	plik_out.open(plik, ios::out | ios::app);
	if (plik_out.good() == true)
	{
		plik_out << "Zamkniete" << endl;
		plik_out << name << " ";
		plik_out << getTyp() << " ";
		plik_out << ilosc_wody << " ";
		plik_out << getZasolenie() << " ";
		plik_out << czystosc << " ";
		plik_out << getPowierzchnia() << " ";
		plik_out << glebokosc << " ";
		plik_out << getLinia() << " ";
		plik_out << czy_port << " ";
		plik_out << endl;
	}
	plik_out.close();
}


