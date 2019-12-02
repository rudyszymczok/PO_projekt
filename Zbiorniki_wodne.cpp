#include "Zbiorniki_wodne.h"
#include <iostream>
using namespace std;

Zbiorniki_wodne::Zbiorniki_wodne(string n="nazwa",string a="zbiornik", int b=10)
{
	name = n;
	typ_zbiornika = a;
	ilosc_wody = b;
}
string Zbiorniki_wodne::getTyp()
{
	return typ_zbiornika;
}
void Zbiorniki_wodne::setTyp(string a)
{
	typ_zbiornika = a;
}


