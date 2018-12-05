#include "stdafx.h"
#include "Starfsmadur.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Starfsmadur::Starfsmadur()
{
	kt = "";
	nafn = "";
	afslattur = 10;
}

Starfsmadur::Starfsmadur(string kt, string nafn, int afslattur)
{
	this->kt = kt;
	this->nafn = nafn;
	this->afslattur = afslattur;
}

string Starfsmadur::getKT()
{
	return kt;
}

void Starfsmadur::print(){
	cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;
}
