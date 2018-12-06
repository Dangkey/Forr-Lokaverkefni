#pragma once
#include <iostream>
#include <string>
using namespace std;
class Malari
{
private:
	string kt;
	string nafn;
	int afslattur;
public:
	Malari();
	Malari(string kt, string nafn, int afslattur);
	string getKT();
	void print();
};

