#pragma once
#include <iostream>
using namespace std;

class Zbiorniki_wodne
{
private:
	string typ_zbiornika;
protected:
	int ilosc_wody;
public:
	string name;
	Zbiorniki_wodne(string, string, int);
	string getTyp();
	void setTyp(string);

};

