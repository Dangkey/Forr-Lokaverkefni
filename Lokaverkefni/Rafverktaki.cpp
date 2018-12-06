#include "stdafx.h"
#include "Rafverktaki.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Rafverktaki::Rafverktaki()
{
	kt = "";
	nafn = "";
	afslattur = 10;
}

Rafverktaki::Rafverktaki(string kt, string nafn, int afslattur)
{
	this->kt = kt;
	this->nafn = nafn;
	this->afslattur = afslattur;
}

string Rafverktaki::getKT()
{
	return kt;
}

void Rafverktaki::print(){
	cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;
}
