#pragma once
#include "Slodkie.h"
#include <iostream>
using namespace std;
class Jeziora :
	public Slodkie
{
private:
	int powierzchnia;
protected:
	int glebokosc;
public:
	Jeziora(string,string, int, float, bool,int,int);
	int getPowierzchnia();
	void setPowierzchnia(int);
};
