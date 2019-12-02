#pragma once
#include "Morza.h"
#include <iostream>
#include <vector>
using namespace std;
class Zamkniete :
	public Morza
{
private:
	int linia_brzegowa;
protected:
	bool czy_port;
public:
	Zamkniete(string,string, int, float, bool, int, int, int, bool);
	int getLinia();
	void setLinia(int);
	void dodaj(vector <Zamkniete>& wektor, Zamkniete objekt);
	void usun(vector <Zamkniete>& wektor, int position);
	void show();
	void modyfikuj(string, string, int, float, bool, int, int, int, bool);
	void zapisz(string);
};

