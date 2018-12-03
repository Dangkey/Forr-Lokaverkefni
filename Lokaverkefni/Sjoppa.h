#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Sjoppa
{
private:
	string item;
	int verd;
	string deild;
public:
	Sjoppa() : item(""), verd(0), deild(""){};
	Sjoppa(string item, int verd, string deild) : item(item), verd(verd), deild(deild){};
	
};

