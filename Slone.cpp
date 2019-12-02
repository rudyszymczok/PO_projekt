#include "Slone.h"
#include <iostream>
using namespace std;

Slone::Slone(string n = "nazwa",string a = "zbiornik_slony", int b = 50, float c = 2, bool d = true)
	:Zbiorniki_wodne(n,a, b)
{
	zasolenie = c;
	czystosc = d;
}
float Slone::getZasolenie()
{
	return zasolenie;
}
void Slone::setZasolenie(float a)
{
	zasolenie = a;
}
