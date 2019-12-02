#include "Jeziora.h"
#include "Slodkie.h"
#include <iostream>
using namespace std;

Jeziora::Jeziora(string n = "nazwa",string a = "jezioro", int b = 10,
	float c = 0.05, bool d = false, int e = 5, int f = 5)
	:Slodkie(n,a, b, c, d)
{
	powierzchnia = e;
	glebokosc = f;
}
int Jeziora::getPowierzchnia()
{
	return powierzchnia;
}
void Jeziora::setPowierzchnia(int a)
{
	powierzchnia = a;
}
