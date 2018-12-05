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
	Sjoppa();
	Sjoppa(string item, int verd, string deild);
	void print();
};

