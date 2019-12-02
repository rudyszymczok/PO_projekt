#pragma once
#include "Zbiorniki_wodne.h"
#include <iostream>
using namespace std;
class Slone :
	public Zbiorniki_wodne
{
private:
	float zasolenie;
protected:
	bool czystosc;
public:
	Slone(string,string, int, float, bool);
	float getZasolenie();
	void setZasolenie(float);
};

