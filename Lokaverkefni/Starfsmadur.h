#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Starfsmadur
{
private:
	string kt;
	string nafn;
	int afslattur;
public:
	Starfsmadur();
	Starfsmadur(string kt, string nafn, int afslattur);
	string getKT();
	void print();
};

