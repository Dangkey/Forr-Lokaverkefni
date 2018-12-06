#include "stdafx.h"
#include "Sjoppa.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Sjoppa::Sjoppa()
{
	item = "";
	verd = 0;
	deild = "";
}
Sjoppa::Sjoppa(string item, int verd, string deild)
{
	this->item = item;
	this->verd = verd;
	this->deild = deild;
}
void Sjoppa::print(){	
	cout << item << " " << verd << "kr " << deild << endl;
}
