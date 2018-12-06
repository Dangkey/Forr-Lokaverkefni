#include "stdafx.h"
#include "Malari.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Malari::Malari()
{
	kt = "";
	nafn = "";
	afslattur = 10;
}

Malari::Malari(string kt, string nafn, int afslattur)
{
	this->kt = kt;
	this->nafn = nafn;
	this->afslattur = afslattur;
}

string Malari::getKT()
{
	return kt;
}

void Malari::print(){
	cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;
}