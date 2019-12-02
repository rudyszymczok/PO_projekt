#include "Morza.h"
#include "Slone.h"
#include <iostream>
using namespace std;

Morza::Morza(string n = "nazwa",string a = "morze", int b = 10,
	float c = 0.05, bool d = false, int e = 5, int f = 5)
	:Slone(n,a, b, c, d)
{
	powierzchnia = e;
	glebokosc = f;
}
int Morza::getPowierzchnia()
{
	return powierzchnia;
}
void Morza::setPowierzchnia(int a)
{
	powierzchnia = a;
}
