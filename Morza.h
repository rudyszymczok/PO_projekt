#pragma once
#include "Slone.h"
#include <iostream>
using namespace std;
class Morza :
	public Slone
{
private:
	int powierzchnia;
protected:
	int glebokosc;
public:
	Morza(string,string, int, float, bool, int, int);
	int getPowierzchnia();
	void setPowierzchnia(int);
};

