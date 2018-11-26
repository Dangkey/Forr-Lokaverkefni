// Lokaverkefni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class Node {
public:
	Malarar Mal;
	Rafverktakar Raf;
	Starfsmenn Starf;
	Node *next;
	Node(int kt, string nafn, int afslattur)
	{
		if (afslattur == 10)
		{
			Mal = Malarar(kt, nafn, afslattur);
			next = nullptr;
		}	
		else if (afslattur == 15)
		{
			Raf = Rafverktakar(kt, nafn, afslattur);
			next = nullptr;
		}
		else if(afslattur == 20)
		{
			Starf = Starfsmenn(kt, nafn, afslattur);
			next = nullptr;
		}
	}
	Node()
	{
	};
};
class LinkedList
{
private:
	Node *head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	void createNode(int kt, string nafn, int afslattur)
	{
		if (idExists(kt))
		{
			cout << "Cannot perform this operation: Flight with that id already exists" << endl;
			return;
		}
		if (head == nullptr)
		{
			head = new Node(kt, nafn, afslattur);
		}
		else
		{
			Node *temp = new Node(id, capacity, reserved);
			if (head->data.getId() > id)
			{
				temp->next = head;
				head = temp;
			}
			else
			{
				Node *current = head;
				Node *prev = head;
				while (current && current->data.getId() < id)
				{
					prev = current;
					current = current->next;
				}
				prev->next = temp;
				temp->next = current;
			}
		}
	}
	void deleteNode(int id)
	{
		Node *current = new Node;
		Node *prev = new Node;
		current = head;
		while (current != nullptr)
		{
			if (idExists(id))
			{
				if (current->data.getId() == id)
				{
					if (current == head)
					{
						head = head->next;
						delete current;
						break;
					}
					else
					{
						prev->next = current->next;
						break;
					}
				}
				{
					prev = current;
					current = current->next;
				}
			}
			else
			{
				cout << "Cannot perform this operation: Flight with that id does not exist" << endl;
				return;
			}

		}
	}

	void display()
	{
		Node *temp = new Node();
		temp = head;
		while (temp != nullptr)
		{
			temp->data.printStatus();
			temp = temp->next;
		}
	}	
	bool ktExists(int kt, int afslattur)
	{
		Node *temp = new Node;
		temp = head;
		while (temp != nullptr)
		{
			if (afslattur == 10)
			{
				if (temp->Mal.getId() == kt)
				{
					return true;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			
		}
		return false;
	}
};

class Malarar{
private:
	int kt;
	string nafn;
	int afslattur;
public:
	Malarar() : kt(0), nafn(""), afslattur(10){};
	Malarar(int kt, string nafn, int afslattur) : kt(kt), nafn(nafn){};
	void print(){
		cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;
	};
};
class Rafverktakar{
private:
	int kt;
	string nafn;
	int afslattur;
public:
	Rafverktakar() : kt(0),nafn(""), afslattur(15){};
	Rafverktakar(int kt ,string nafn, int afslattur) : kt(kt),nafn(nafn){};
	void print(){
		cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;
	};
};
class Starfsmenn{
private:
	int kt;
	string nafn;
	int afslattur;
public:
	Starfsmenn() : kt(0), nafn(""), afslattur(20){};
	Starfsmenn(int kt, string nafn,int afslattur) : kt(kt), nafn(nafn){};
	void print(){	
		cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;	
	};
};
class Vidskiptavinir{
private:
	Malarar *mal;
	Rafverktakar *raf;
	Starfsmenn *starf;	
	

public:
	Vidskiptavinir(){
		*mal = Malarar();
		*raf = Rafverktakar();
		*starf = Starfsmenn();		
	};
	Vidskiptavinir(int kt, string nafn, int afslattur){
		mal = new Malarar[10];
		raf = new Rafverktakar[10];
		starf = new Starfsmenn[10];

		if (afslattur == 10)
		{
			for (int i = 0; i < 10; i++)
			{
				mal[i]
			}
		}
	};	
};


class Shoppa{
private:
	string item;
	int verd;
	string deild;
public:
	Shoppa() : item(""), verd(0), deild(""){};
	Shoppa(string item, int verd, string deild) : item(item), verd(verd), deild(deild){};
	void print(){
		cout << item << " " << verd << "kr " << deild << endl;
	}
};

int main()
{
	Shoppa shop[10];
	shop[0] = Shoppa("Pensill            ", 999,"  Malningadeild");
	shop[1] = Shoppa("Blondud malning 1L ",  1500," Malningadeild");
	shop[2] = Shoppa("Blondud malning 5L ", 6500," Malningadeild");
	shop[3] = Shoppa("Blondud malning 10L", 11490,"Malningadeild");
	shop[4] = Shoppa("Vir 1M             ", 300,"   Rafindadeild");
	shop[5] = Shoppa("Netsnura 5M        ", 1500,"  Rafindadeild");
	shop[6] = Shoppa("HDMI Snura 10M     ", 2000,"  Rafindadeild");
	shop[7] = Shoppa("Klo                ", 500,"   Rafindadeild");
	shop[8] = Shoppa("Tenglarenna        ", 300000,"Rafindadeild");
	shop[9] = Shoppa("Twix               ", 999,"        Almennt");
	for (int i = 0; i < 10; i++)
	{
		shop[i].print();
	}
	return 0;
}

