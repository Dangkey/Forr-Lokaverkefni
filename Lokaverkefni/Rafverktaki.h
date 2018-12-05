#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Rafverktaki
{
private:
	string kt;
	string nafn;
	int afslattur;
public:
	Rafverktaki();
	Rafverktaki(string kt, string nafn, int afslattur);
	string getKT();
	void print();
};

