#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "Zbiorniki_wodne.h"
#include "Slodkie.h"
#include "Slone.h"
#include "Rzeki.h"
#include "Jeziora.h"
#include "Morza.h"
#include "Oceany.h"
#include "Odplywowe.h"
#include "Bezodplywowe.h"
#include "Otwarte.h"
#include "Zamkniete.h"
#include "Tablica.h"
using namespace std;

int stringtoint(string a)
{
	int liczba = 0;
	int len = a.size();
	for (int i = len - 1; i >= 0; i--)

	{
		char znak;
		znak = a[i];
		liczba += (int(znak) - 48) * pow(10, len - i - 1);
	}
	return liczba;
}

float stringtofloat(string a)
{
	int id = -1;
	double liczba = 0;
	int len = a.size();

	for (int i = 0; i < len; i++)
	{
		if (a[i] == '.')
		{
			id = i;
		}
	}
	if (id < 0)
	{
		liczba = stringtoint(a);
	}
	else
	{
		for (int i = len - 1; i >= 0; i--)
		{
			char znak;
			znak = a[i];
			if (znak != '.')
			{
				if (i > id)
				{
					liczba += (int(znak) - 48) * pow(10, id - i);
				}
				else
				{
					liczba += (int(znak) - 48) * pow(10, id - i - 1);
				}
			}

		}
	}
	return liczba;

}
int spacja(string a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ')
			return i;
	}
}
void tablicowanie(string tab[10], string att)
{
	int counter = 0;
	while (att != "")
	{
		int a = spacja(att);
		string tmp = att.substr(0, a);
		tab[counter] = tmp;
		string tmp2 = att.substr(a + 1, att.size() - a - 1);
		att = tmp2;
		counter++;
	}
}

int main()
{
	vector<Rzeki> w_rzeki;
	vector<Odplywowe> w_odplywowe;
	vector<Bezodplywowe> w_bezodplywowe;
	vector<Otwarte> w_otwarte;
	vector<Zamkniete> w_zamkniete;
	vector<Oceany> w_oceany;

	for (int i = 0; i < w_rzeki.size(); i++)
	{
		w_rzeki[i].show();
	}

	bool running = true;
	string current_wezel="Rzeki";
	int nr_operacji;
	string current_operation;
	string current_id="default";

	
	fstream plik_in;

	string klasa,atrybuty;
	string nam;
	string new_name;
	string typ;
	int woda;
	float sol;
	bool clean;
	int dlug;
	int szer;
	int gleb;
	int pow;
	int odplywy;
	string najdluzszy;
	string zarzad;
	int brzeg;
	bool port;
	string test;

	string tab[10];


	while (running)
	{
		cout << endl;
		cout << "Jestes w wezle: " << current_wezel << endl;
		cout << endl;
		cout << "Co chcesz zrobic?:" << endl;
		cout << "1) Zmiana wezla w strukturze: CD[nazwa wezla]" << endl;
		cout << "2) Utworzyc obiekt w wezle " << current_wezel <<" : MO[nazwa obiektu]"<< endl;
		cout << "3) Usunac obiekt w wezle " << current_wezel << " : DO[nazwa obiektu]" << endl;
		cout << "4) Zmodyfikowac obiekt w wezle " << current_wezel << " : MDO[nazwa obiektu]" << endl;
		cout << "5) Wyswietlic informacje o obiektach widocznych z poziomu " << current_wezel<<" : DIR" << endl;
		cout << "6) Wyswitlic szczegolowe informacje o danym obiekcie" << " : SHOW[nazwa obiektu]" << endl;
		cout << "7) Zapisac obecny zbior do pliku: SAVE"<< endl;
		cout << "8) Wczytac zbior z pliku: READ"<<endl;
		cout << "9) Wyswietlic strukture w formie wciec: TREE" << endl;
		cout << "10) Zakonczyc prace z programem: EXIT" << endl;

		cin >> current_operation;
		
		if (current_operation.compare(0, 2, "CD")==0)
		{
			nr_operacji = 1;
		}
		else if (current_operation.compare(0, 2, "MO")==0)
		{
			nr_operacji = 2;
		}
		else if (current_operation.compare(0, 2, "DO")==0)
		{
			nr_operacji = 3;
		}
		else if (current_operation.compare(0, 3, "MDO")==0)
		{
			nr_operacji = 4;
		}
		else if (current_operation == "DIR")
		{
			nr_operacji = 5;
		}
		else if (current_operation.compare(0, 4, "SHOW")==0)
		{
			nr_operacji = 6;
		}
		else if (current_operation == "SAVE")
		{
			nr_operacji = 7;
		}
		else if (current_operation == "READ")
		{
			nr_operacji = 8;
		}
		else if (current_operation == "TREE")
		{
			nr_operacji = 9;
		}
		else if (current_operation == "EXIT")
		{
			nr_operacji = 10;
		}
		else 
		{ 
			nr_operacji = 11; 
		}
		bool found = false;

		switch (nr_operacji)
		{
		case 1:
			current_wezel = current_operation.substr(3, current_operation.size()-4);
			break;
		case 2:
			nam = current_operation.substr(3, current_operation.size() - 4);
			if (current_wezel == "Rzeki")
			{
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if(test == "nie")
					clean = false;
				cout << "Podaj dlugosc rzeki" << endl;
				cin >> dlug;
				cout << "Podaj szerokosc rzeki" << endl;
				cin >> szer;
				cout << "Podaj glebokosc rzeki" << endl;
				cin >> gleb;

				Rzeki tmp(nam, typ, woda, sol, clean, dlug, szer, gleb);
				tmp.dodaj(w_rzeki, tmp);
			}
			else if (current_wezel == "Odplywowe")
			{
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout<<"Podaj powierzchnie jeziora"<<endl;
				cin >> pow;
				cout << "Podaj glebokosc jeziora" << endl;
				cin >> gleb;
				cout << "Podaj ilosc odplywow jeziora" << endl;
				cin >> odplywy;
				cout << "Podaj nazwe najdluzszego odplywu" << endl;
				cin >> najdluzszy;

				Odplywowe tmp(nam, typ, woda, sol, clean, pow, gleb, odplywy, najdluzszy);
				tmp.dodaj(w_odplywowe, tmp);
			}
			else if (current_wezel == "Bezodplywowe")
			{
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj powierzchnie jeziora" << endl;
				cin >> pow;
				cout << "Podaj glebokosc jeziora" << endl;
				cin >> gleb;
				cout << "Podaj ilosc odplywow jeziora" << endl;
				cin >> odplywy;
				cout << "Podaj nazwe zarzadcy jeziora" << endl;
				cin >> zarzad;

				Bezodplywowe tmp(nam, typ, woda, sol, clean, pow, gleb, odplywy, zarzad);
				tmp.dodaj(w_bezodplywowe, tmp);
			}
			else if (current_wezel == "Otwarte")
			{
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj powierzchnie morza" << endl;
				cin >> pow;
				cout << "Podaj glebokosc morza" << endl;
				cin >> gleb;
				cout << "Podaj ilosc odplywow morza" << endl;
				cin >> odplywy;
				cout << "Podaj nazwe najdluzszego odplywu" << endl;
				cin >> najdluzszy;

				Otwarte tmp(nam, typ, woda, sol, clean, pow, gleb, odplywy, najdluzszy);
				tmp.dodaj(w_otwarte, tmp);
			}
			else if (current_wezel == "Zamkniete")
			{
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj powierzchnie morza" << endl;
				cin >> pow;
				cout << "Podaj glebokosc morza" << endl;
				cin >> gleb;
				cout << "Podaj dlugosc linii brzegowej" << endl;
				cin >> brzeg;
				cout << "Podaj informacje o wystepowaniu portu: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					port = true;
				else if (test == "nie")
					port = false;

				Zamkniete tmp(nam, typ, woda, sol, clean, pow, gleb, brzeg, port);
				tmp.dodaj(w_zamkniete, tmp);
			}
			else if (current_wezel == "Oceany")
			{
			cout << "Podaj typ zbiornika" << endl;
			cin >> typ;
			cout << "Podaj ilosc wody w zbiorniku" << endl;
			cin >> woda;
			cout << "Podaj procentowe zasolenie wody" << endl;
			cin >> sol;
			cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
			cin >> test;
			if (test == "tak")
				clean = true;
			else if (test == "nie")
				clean = false;
			cout << "Podaj powierzchnie oceanu" << endl;
			cin >> pow;
			cout << "Podaj glebokosc oceanu" << endl;
			cin >> gleb;
			
			Oceany tmp(nam, typ, woda, sol, clean, pow, gleb);
			tmp.dodaj(w_oceany, tmp);
			}
			break;
		case 3:
		
			nam = current_operation.substr(3, current_operation.size() - 4);
			
			
			if (current_wezel == "Rzeki")
			{
				for (int i = 0; i < w_rzeki.size(); i++)
				{
					if (w_rzeki[i].name == nam)
					{
						found = true;
						w_rzeki[i].usun(w_rzeki, i);
						break;
					}
				}
				if (found == false)
				{
					cout << "Nie znaleziono obiektu o podanej nazwie!" << endl;
				}
				else { cout << "Pomyslnie usunieto obiekt " << nam << endl; }
				found = false;
			}
			else if (current_wezel == "Odplywowe")
			{
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					if (w_odplywowe[i].name == nam)
					{
						found = true;
						w_odplywowe[i].usun(w_odplywowe, i);
						break;
					}
				}
				if (found == false)
				{
					cout << "Nie znaleziono obiektu o podanej nazwie!" << endl;
				}
				else { cout << "Pomyslnie usunieto obiekt " << nam << endl; }
				found = false;
			}
			else if (current_wezel == "Bezodplywowe")
			{
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					if (w_bezodplywowe[i].name == nam)
					{
						found = true;
						w_bezodplywowe[i].usun(w_bezodplywowe, i);
						break;
					}
				}
				if (found == false)
				{
					cout << "Nie znaleziono obiektu o podanej nazwie!" << endl;
				}
				else { cout << "Pomyslnie usunieto obiekt " << nam << endl; }

				found = false;
				
			}
			else if (current_wezel == "Otwarte")
			{
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					if (w_otwarte[i].name == nam)
					{
						found = true;
						w_otwarte[i].usun(w_otwarte, i);
						break;
					}
				}
				if (found == false)
				{
					cout << "Nie znaleziono obiektu o podanej nazwie!" << endl;
				}
				else { cout << "Pomyslnie usunieto obiekt " << nam << endl; }
				found = false;
			}
			else if (current_wezel == "Zamkniete")
			{
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					if (w_zamkniete[i].name == nam)
					{
						found = true;
						w_zamkniete[i].usun(w_zamkniete, i);
						break;
					}
				}
				if (found == false)
				{
					cout << "Nie znaleziono obiektu o podanej nazwie!" << endl;
				}
				else { cout << "Pomyslnie usunieto obiekt " << nam << endl; }
				found = false;

			}
			else if (current_wezel == "Oceany")
			{
				for (int i = 0; i < w_oceany.size(); i++)
				{
					if (w_oceany[i].name == nam)
					{
						found = true;
						w_oceany[i].usun(w_oceany, i);
						break;
					}
				}
				if (found == false)
				{
					cout << "Nie znaleziono obiektu o podanej nazwie!" << endl;
				}
				else { cout << "Pomyslnie usunieto obiekt " << nam << endl; }
				found = false;
			}
			break;
		case 4:
			nam = current_operation.substr(4, current_operation.size() - 5);
			if (current_wezel == "Rzeki")
			{
				cout << "Podaj nowa nazwe zbiornika" << endl;
				cin >> new_name;
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj dlugosc rzeki" << endl;
				cin >> dlug;
				cout << "Podaj szerokosc rzeki" << endl;
				cin >> szer;
				cout << "Podaj glebokosc rzeki" << endl;
				cin >> gleb;

				for (int i = 0; i < w_rzeki.size(); i++)
				{
					if (w_rzeki[i].name == nam)
					{
						w_rzeki[i].modyfikuj(new_name, typ, woda, sol, clean, dlug, szer, gleb);
						break;
					}
				}

			}
			else if (current_wezel == "Odplywowe")
			{
				cout << "Podaj nowa nazwe zbiornika" << endl;
				cin >> new_name;
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj powierzchnie jeziora" << endl;
				cin >> pow;
				cout << "Podaj glebokosc jeziora" << endl;
				cin >> gleb;
				cout << "Podaj ilosc odplywow jeziora" << endl;
				cin >> odplywy;
				cout << "Podaj nazwe najdluzszego odplywu" << endl;
				cin >> najdluzszy;

				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					if (w_odplywowe[i].name == nam)
					{
						w_odplywowe[i].modyfikuj(new_name, typ, woda, sol, clean, pow ,gleb, odplywy, najdluzszy);
						break;
					}
				}
			}
			else if (current_wezel == "Bezodplywowe")
			{
				cout << "Podaj nowa nazwe zbiornika" << endl;
				cin >> new_name;
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj powierzchnie jeziora" << endl;
				cin >> pow;
				cout << "Podaj glebokosc jeziora" << endl;
				cin >> gleb;
				cout << "Podaj ilosc odplywow jeziora" << endl;
				cin >> odplywy;
				cout << "Podaj nazwe zarzadcy jeziora" << endl;
				cin >> zarzad;

				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					if (w_bezodplywowe[i].name == nam)
					{
						w_bezodplywowe[i].modyfikuj(new_name, typ, woda, sol, clean, pow, gleb, odplywy, zarzad);
						break;
					}
				}
			}
			else if (current_wezel == "Otwarte")
			{
				cout << "Podaj nowa nazwe zbiornika" << endl;
				cin >> new_name;
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj powierzchnie morza" << endl;
				cin >> pow;
				cout << "Podaj glebokosc morza" << endl;
				cin >> gleb;
				cout << "Podaj ilosc odplywow morza" << endl;
				cin >> odplywy;
				cout << "Podaj nazwe najdluzszego odplywu" << endl;
				cin >> najdluzszy;

				for (int i = 0; i < w_otwarte.size(); i++)
				{
					if (w_otwarte[i].name == nam)
					{
						w_otwarte[i].modyfikuj(new_name, typ, woda, sol, clean, pow, gleb, odplywy, najdluzszy);
						break;
					}
				}
			}
			else if (current_wezel == "Zamkniete")
			{
				cout << "Podaj nowa nazwe zbiornika" << endl;
				cin >> new_name;
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj powierzchnie morza" << endl;
				cin >> pow;
				cout << "Podaj glebokosc morza" << endl;
				cin >> gleb;
				cout << "Podaj dlugosc linii brzegowej" << endl;
				cin >> brzeg;
				cout << "Podaj informacje o wystepowaniu portu: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;

				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					if (w_zamkniete[i].name == nam)
					{
						w_zamkniete[i].modyfikuj(new_name, typ, woda, sol, clean, pow, gleb, brzeg, port);
						break;
					}
				}
			}
			else if (current_wezel == "Oceany")
			{
				cout << "Podaj nowa nazwe zbiornika" << endl;
				cin >> new_name;
				cout << "Podaj typ zbiornika" << endl;
				cin >> typ;
				cout << "Podaj ilosc wody w zbiorniku" << endl;
				cin >> woda;
				cout << "Podaj procentowe zasolenie wody" << endl;
				cin >> sol;
				cout << "Podaj informacje o czystosci wody: [tak/nie]" << endl;
				cin >> test;
				if (test == "tak")
					clean = true;
				else if (test == "nie")
					clean = false;
				cout << "Podaj powierzchnie oceanu" << endl;
				cin >> pow;
				cout << "Podaj glebokosc oceanu" << endl;
				cin >> gleb;

				for (int i = 0; i < w_oceany.size(); i++)
				{
					if (w_oceany[i].name == nam)
					{
						w_oceany[i].modyfikuj(new_name, typ, woda, sol, clean, pow, gleb);
						break;
					}
				}
			}
			break;
		case 5:
			if (current_wezel == "Zbiorniki_wodne")
			{
				cout << endl;
				for (int i = 0; i < w_oceany.size(); i++)
				{
					cout << w_oceany[i].name << " ";	
				}
				cout << endl;
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					cout << w_zamkniete[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					cout<<w_otwarte[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					cout << w_bezodplywowe[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					cout << w_odplywowe[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_rzeki.size(); i++)
				{
					cout << w_rzeki[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Slodkie")
			{
				cout << endl;
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					cout << w_zamkniete[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					cout << w_otwarte[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					cout << w_bezodplywowe[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					cout << w_odplywowe[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_rzeki.size(); i++)
				{
					cout << w_rzeki[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Slone")
			{
				cout << endl;
				for (int i = 0; i < w_oceany.size(); i++)
				{
					cout << w_oceany[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					cout << w_zamkniete[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					cout << w_otwarte[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Rzeki")
			{
				cout << endl;
				for (int i = 0; i < w_rzeki.size(); i++)
				{
					cout << w_rzeki[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Jeziora")
			{
				cout << endl;
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					cout << w_bezodplywowe[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					cout << w_odplywowe[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Morza")
			{
				cout << endl;
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					cout << w_zamkniete[i].name << " ";
				}
				cout << endl;
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					cout << w_otwarte[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Oceany")
			{
				cout << endl;
				for (int i = 0; i < w_oceany.size(); i++)
				{
					cout << w_oceany[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Odplywowe")
			{
				cout << endl;
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					cout << w_odplywowe[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Bezodplywowe")
			{
				cout << endl;
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					cout << w_bezodplywowe[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Otwarte")
			{
				cout << endl;
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					cout << w_otwarte[i].name << " ";
				}
				cout << endl;
			}
			else if (current_wezel == "Zamkniete")
			{
				cout << endl;
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					cout << w_zamkniete[i].name << " ";
				}
				cout << endl;
			}
			break;
		case 6:
			nam = current_operation.substr(5, current_operation.size() - 6);
			if (current_wezel == "Zbiorniki_wodne")
			{
				cout << endl;
				for (int i = 0; i < w_oceany.size(); i++)
				{
					if (w_oceany[i].name == nam)
					{
						w_oceany[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					if (w_zamkniete[i].name == nam)
					{
						w_zamkniete[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					if (w_otwarte[i].name == nam)
					{
						w_otwarte[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					if (w_bezodplywowe[i].name == nam)
					{
						w_bezodplywowe[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					if (w_odplywowe[i].name == nam)
					{
						w_odplywowe[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_rzeki.size(); i++)
				{
					if (w_rzeki[i].name == nam)
					{
						w_rzeki[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Slodkie")
			{
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					if (w_zamkniete[i].name == nam)
					{
						w_zamkniete[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					if (w_otwarte[i].name == nam)
					{
						w_otwarte[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					if (w_bezodplywowe[i].name == nam)
					{
						w_bezodplywowe[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					if (w_odplywowe[i].name == nam)
					{
						w_odplywowe[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_rzeki.size(); i++)
				{
					if (w_rzeki[i].name == nam)
					{
						w_rzeki[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Slone")
			{
				for (int i = 0; i < w_oceany.size(); i++)
				{
					if (w_oceany[i].name == nam)
					{
						w_oceany[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					if (w_zamkniete[i].name == nam)
					{
						w_zamkniete[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					if (w_otwarte[i].name == nam)
					{
						w_otwarte[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Rzeki")
			{
				for (int i = 0; i < w_rzeki.size(); i++)
				{
					if (w_rzeki[i].name == nam)
					{
						w_rzeki[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Jeziora")
			{
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					if (w_bezodplywowe[i].name == nam)
					{
						w_bezodplywowe[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					if (w_odplywowe[i].name == nam)
					{
						w_odplywowe[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Morza")
			{
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					if (w_zamkniete[i].name == nam)
					{
						w_zamkniete[i].show();
						cout << endl;
					}
				}
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					if (w_otwarte[i].name == nam)
					{
						w_otwarte[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Oceany")
			{
				for (int i = 0; i < w_oceany.size(); i++)
				{
					if (w_oceany[i].name == nam)
					{
						w_oceany[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Odplywowe")
			{
				for (int i = 0; i < w_odplywowe.size(); i++)
				{
					if (w_odplywowe[i].name == nam)
					{
						w_odplywowe[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Bezodplywowe")
			{
				for (int i = 0; i < w_bezodplywowe.size(); i++)
				{
					if (w_bezodplywowe[i].name == nam)
					{
						w_bezodplywowe[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Otwarte")
			{
				for (int i = 0; i < w_otwarte.size(); i++)
				{
					if (w_otwarte[i].name == nam)
					{
						w_otwarte[i].show();
						cout << endl;
					}
				}
			}
			else if (current_wezel == "Zamkniete")
			{
				for (int i = 0; i < w_zamkniete.size(); i++)
				{
					if (w_zamkniete[i].name == nam)
					{
						w_zamkniete[i].show();
						cout << endl;
					}
				}
				cout << endl;
			}

			break;
		case 7:
			
			for (int i = 0; i < w_rzeki.size(); i++)
			{
				w_rzeki[i].zapisz("zapis.txt");
			}
			for (int i = 0; i < w_otwarte.size(); i++)
			{
				w_otwarte[i].zapisz("zapis.txt");
			}
			
			for (int i = 0; i < w_zamkniete.size(); i++)
			{
				w_zamkniete[i].zapisz("zapis.txt");
			}
			for (int i = 0; i < w_odplywowe.size(); i++)
			{
				w_odplywowe[i].zapisz("zapis.txt");
			}
			for (int i = 0; i < w_oceany.size(); i++)
			{
				w_oceany[i].zapisz("zapis.txt");
			}
			for (int i = 0; i < w_bezodplywowe.size(); i++)
			{
				w_bezodplywowe[i].zapisz("zapis.txt");
			}
			break;
		case 8:
			plik_in.open("odczyt.txt", ios::in);
			if (plik_in.good() == false)
			{
				cout << "Blad pliku!" << endl;
				break;
			}
			while (getline(plik_in, klasa))
			{
				if (klasa == "Rzeki")
				{
					getline(plik_in, atrybuty);

					tablicowanie(tab, atrybuty);
					clean = false;
					nam = tab[0];
					typ = tab[1];
					woda = stringtoint(tab[2]);
					sol = stringtofloat(tab[3]);
					if (tab[4] == "1")
					{
						clean = true;
					}
					else if (tab[4] == "0")
					{
						clean = false;
					}
					dlug = stringtoint(tab[5]);
					szer = stringtoint(tab[6]);
					gleb = stringtoint(tab[7]);
					Rzeki tmp(nam, typ, woda, sol, clean, dlug, szer, gleb);
					tmp.dodaj(w_rzeki, tmp);
				}
				else if (klasa == "Odplywowe")
				{
					getline(plik_in, atrybuty);

					tablicowanie(tab, atrybuty);
					clean = false;
					nam = tab[0];
					typ = tab[1];
					woda = stringtoint(tab[2]);
					sol = stringtofloat(tab[3]);
					if (tab[4] == "1")
					{
						clean = true;
					}
					else if (tab[4] == "0")
					{
						clean = false;
					}
					pow = stringtoint(tab[5]);
					gleb = stringtoint(tab[6]);
					odplywy = stringtoint(tab[7]);
					najdluzszy = tab[8];
					Odplywowe tmp(nam, typ, woda, sol, clean, pow, gleb, odplywy, najdluzszy);
					tmp.dodaj(w_odplywowe, tmp);
				}
				else if (klasa == "Bezodplywowe")
				{
					getline(plik_in, atrybuty);

					tablicowanie(tab, atrybuty);
					clean = false;
					nam = tab[0];
					typ = tab[1];
					woda = stringtoint(tab[2]);
					sol = stringtofloat(tab[3]);
					if (tab[4] == "1")
					{
						clean = true;
					}
					else if (tab[4] == "0")
					{
						clean = false;
					}
					pow = stringtoint(tab[5]);
					gleb = stringtoint(tab[6]);
					odplywy = stringtoint(tab[7]);
					zarzad = tab[8];
					Bezodplywowe tmp(nam, typ, woda, sol, clean, pow, gleb, odplywy, zarzad);
					tmp.dodaj(w_bezodplywowe, tmp);
				}
				else if (klasa == "Otwarte")
				{
					getline(plik_in, atrybuty);

					tablicowanie(tab, atrybuty);
					clean = false;
					nam = tab[0];
					typ = tab[1];
					woda = stringtoint(tab[2]);
					sol = stringtofloat(tab[3]);
					if (tab[4] == "1")
					{
						clean = true;
					}
					else if (tab[4] == "0")
					{
						clean = false;
					}
					pow = stringtoint(tab[5]);
					gleb = stringtoint(tab[6]);
					odplywy = stringtoint(tab[7]);
					najdluzszy = tab[8];
					Otwarte tmp(nam, typ, woda, sol, clean, pow, gleb, odplywy, najdluzszy);
					tmp.dodaj(w_otwarte, tmp);
				}
				else if (klasa == "Zamkniete")
				{
					getline(plik_in, atrybuty);

					tablicowanie(tab, atrybuty);
					clean = false;
					port = false;
					nam = tab[0];
					typ = tab[1];
					woda = stringtoint(tab[2]);
					sol = stringtofloat(tab[3]);
					if (tab[4] == "1")
					{
						clean = true;
					}
					else if (tab[4] == "0")
					{
						clean = false;
					}
					pow = stringtoint(tab[5]);
					gleb = stringtoint(tab[6]);
					brzeg = stringtoint(tab[7]);
					if (tab[8] == "1")
					{
						port = true;
					}
					else if (tab[8] == "0")
					{
						port = false;
					}
					Zamkniete tmp(nam, typ, woda, sol, clean, pow, gleb, brzeg, port);
					tmp.dodaj(w_zamkniete, tmp);
				}
				else if (klasa == "Oceany")
				{
					getline(plik_in, atrybuty);

					tablicowanie(tab, atrybuty);
					clean = false;
					nam = tab[0];
					typ = tab[1];
					woda = stringtoint(tab[2]);
					sol = stringtofloat(tab[3]);
					if (tab[4] == "1")
					{
						clean = true;
					}
					else if (tab[4] == "0")
					{
						clean = false;
					}
					pow = stringtoint(tab[5]);
					gleb = stringtoint(tab[6]);
					Oceany tmp(nam, typ, woda, sol, clean, pow, gleb);
					tmp.dodaj(w_oceany, tmp);
				}

				
			}
			plik_in.close();
			break;
		case 9:
			cout << endl;
			cout << endl;
			cout << "STRUKTURA HIERARCHII KLAS" << endl;
			cout << endl;
			cout << "|-Zbiorniki_wodne" << endl;
			cout << "|    |-Slodkie" << endl;
			cout << "|    |    |-Rzeki" << endl;
			cout << "|    |    |-Jeziora" << endl;
			cout << "|    |    |    |-Odplywowe" << endl;
			cout << "|    |    |    |-Bezodplywowe" << endl;
			cout << "|    |    |-Morza" << endl;
			cout << "|    |         |-Otwarte" << endl;
			cout << "|    |         |-Zamkniete" << endl;
			cout << "|    |-Slone" << endl;
			cout << "|    |    |-Oceany" << endl;
			cout << "|    |    |-Morza" << endl;
			cout << "|    |    |    |-Otwarte" << endl;
			cout << "|    |    |    |-Zamkniete" << endl;
			cout << endl;

			break;
		case 10:
			running = false;
			break;
		default:
			cout << "Podaj poprawne polecenie!" << endl;
			break;

		}
		
     
			
	}
	Tablica <int> table;
	table.set_size();

	Rzeki a("leszcz", "rzeka", 1, 0.35, true, 1, 1, 1);
	Rzeki b("sum", "rzeka", 1, 0.35, true, 1, 1, 1);
	Rzeki c = a + b;
	a.show();
	b.show();
	c.show();

	
}
