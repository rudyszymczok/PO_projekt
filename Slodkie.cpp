#include "Slodkie.h"
#include <iostream>
using namespace std;

Slodkie::Slodkie(string n = "nazwa",string a = "zbiornik_slodki", int b = 10, float c = 0.05, bool d = false)
	:Zbiorniki_wodne(n,a,b)
{
	zasolenie = c;
	czystosc = d;
}
float Slodkie::getZasolenie()
{
	return zasolenie;
}
void Slodkie::setZasolenie(float a)
{
	zasolenie = a;
}