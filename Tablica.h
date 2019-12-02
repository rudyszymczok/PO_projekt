#pragma once
#include <iostream>
using namespace std;

template <class typ>
class Tablica
{
private:
	int ilosc;
	typ* tab = (typ*)malloc(ilosc);
public:

	void set_size()
	{
		cout << "Podaj rozmiar tablicy" << endl;
		cin >> ilosc;
		cout << endl;
	}
	void show()
	{
		for (int i = 0; i < ilosc; i++)
		{
			cout << tab[i] << " ";
		}
		cout << endl;
	}
	void dodaj(int id, typ a)
	{
		tab[id] = a;
	}
	typ getIlosc()
	{
		return ilosc;
	}
};

