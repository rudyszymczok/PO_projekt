#pragma once
#include "Zbiorniki_wodne.h"
#include <iostream>
using namespace std;
class Slodkie :
	public Zbiorniki_wodne
{
private:
	float zasolenie;
protected:
	bool czystosc;
public:
	Slodkie(string,string, int, float, bool);
	float getZasolenie();
	void setZasolenie(float);
};

