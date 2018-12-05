// Lokaverkefni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Malarar{
private:
	string kt;
	string nafn;
	int afslattur;
public:
	Malarar() : kt(""), nafn(""), afslattur(10){};
	Malarar(string kt, string nafn, int afslattur) : kt(kt), nafn(nafn), afslattur(afslattur){};
	string getKT() { return kt; };
	void print(){
		cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;
	};

};
class Rafverktakar{
private:
	string kt;
	string nafn;
	int afslattur;
public:
	Rafverktakar() : kt(""),nafn(""), afslattur(15){};
	Rafverktakar(string kt, string nafn, int afslattur) : kt(kt), nafn(nafn), afslattur(afslattur){};
	string getKT() { return kt; };
	void print(){
		cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;
	};
};
class Starfsmenn{
private:
	string kt;
	string nafn;
	int afslattur;
public:
	Starfsmenn() : kt(""), nafn(""), afslattur(20){};
	Starfsmenn(string kt, string nafn, int afslattur) : kt(kt), nafn(nafn), afslattur(afslattur){};
	string getKT() { return kt; };
	void print(){	
		cout << kt << " : " << nafn << " : " << afslattur << "%" << endl;	
	};
};/*
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
	Vidskiptavinir(string kt, string nafn, int afslattur){
		mal = new Malarar[10];
		raf = new Rafverktakar[10];
		starf = new Starfsmenn[10];


	};	
};
*/


class Node {
public:
	Malarar Mal;
	Rafverktakar Raf;
	Starfsmenn Starf;
	Node *next;
	Node(string kt, string nafn, int afslattur)
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
		else if (afslattur == 20)
		{
			Starf = Starfsmenn(kt, nafn, afslattur);
			next = nullptr;
		}
		else
		{
			cout << "fucked up";
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
	void createNode(string kt, string nafn, int afslattur)
	{
		if (ktExists(kt, afslattur))
		{
			cout << "Einhvad for vitlaust" << endl;
			return;
		}
		if (head == nullptr)
		{
			head = new Node(kt, nafn, afslattur);
		}
		else
		{
			Node *temp = new Node(kt, nafn, afslattur);
			if (afslattur == 10)
			{
				if (head->Mal.getKT() != kt)
				{
					temp->next = head;
					head = temp;
				}
				else
				{
					Node *current = head;
					Node *prev = head;
					while (current && current->Mal.getKT() != kt)
					{
						prev = current;
						current = current->next;
					}
					prev->next = temp;
					temp->next = current;
				}
			}
			else if (afslattur == 15)
			{
				if (head->Raf.getKT() != kt)
				{
					temp->next = head;
					head = temp;
				}
				else
				{
					Node *current = head;
					Node *prev = head;
					while (current && current->Raf.getKT() != kt)
					{
						prev = current;
						current = current->next;
					}
					prev->next = temp;
					temp->next = current;
				}
			}
			else if (afslattur == 20)
			{
				if (head->Starf.getKT() != kt)
				{
					temp->next = head;
					head = temp;
				}
				else
				{
					Node *current = head;
					Node *prev = head;
					while (current && current->Starf.getKT() != kt)
					{
						prev = current;
						current = current->next;
					}
					prev->next = temp;
					temp->next = current;
				}
				
			}
		}
	}
	
	/*void deleteNode(int id,int af)
	{
	Node *current = new Node;
	Node *prev = new Node;
	current = head;
	while (current != nullptr)
	{
	if (ktExists(id,afslattur))
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
	*/
	void display()
	{
		Node *temp = new Node();
		Node *temp1 = new Node();
		Node *temp2 = new Node();
		temp = head;
		temp1 = head;
		temp2 = head;
		while (temp != nullptr)
		{
			temp->Mal.print();
			temp = temp->next;
			
		}
		while (temp2 != nullptr)
		{
			temp2->Raf.print();
			temp2 = temp2->next;

		}
		
	}
	void print()
	{

	}
	bool ktExists(string kt, int afslattur)
	{
		Node *temp = new Node;
		temp = head;
		while (temp != nullptr)
		{
			if (afslattur == 10)
			{
				if (temp->Mal.getKT() == kt)
				{
					return true;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			else if (afslattur == 15)
			{
				if (temp->Raf.getKT() == kt)
				{
					return true;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			else if (afslattur == 20)
			{
				if (temp->Starf.getKT() == kt)
				{
					return true;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			else
			{
				cout << " beebooo" << endl;
			}

		}
		return false;
	}
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
	Malarar mal;
	
	int adgangur;
	string kennitala;
	int kaupa;
	int total = 0;
	LinkedList b = LinkedList();
	b.createNode("2308992829", "Hilmar", 10);
	b.createNode("2711912029", "Elas", 15);
	b.createNode("0000000000", "Hilmar", 10);
	b.createNode("1111111111", "Elas", 15);
	b.createNode("1811992029", "Hilmar", 10);
	b.createNode("3333333333", "Elas", 15);
	b.createNode("0405994799", "Hilmar", 10);
	b.createNode("2222222222", "Elas", 15);
	
	Shoppa shop[10];
	shop[0] = Shoppa("1. Pensill            ", 999, "  Malningadeild");
	shop[1] = Shoppa("2. Blondud malning 1L ", 1500, " Malningadeild");
	shop[2] = Shoppa("3. Blondud malning 5L ", 6500, " Malningadeild");
	shop[3] = Shoppa("4. Blondud malning 10L", 11490, "Malningadeild");
	shop[4] = Shoppa("5. Vir 1M             ", 300, "   Rafindadeild");
	shop[5] = Shoppa("6. Netsnura 5M        ", 1500, "  Rafindadeild");
	shop[6] = Shoppa("7. HDMI Snura 10M     ", 2000, "  Rafindadeild");
	shop[7] = Shoppa("8. Klo                ", 500, "   Rafindadeild");
	shop[8] = Shoppa("9. Tenglarenna        ", 300000, "Rafindadeild");
	shop[9] = Shoppa("10.Twix               ", 999, "        Almennt");



	cout << "1. Login" << endl;
	cout << "2. Versla" << endl;
	cin >> adgangur;

	if (adgangur == 1)
	{
		cout << "Kennitala:";
		cin >> kennitala;
		adgangur = 2;
	}
	switch (adgangur){
	case 2:
		for (int i = 0; i < 10; i++)
		{
			shop[i].print();
		}	
		cout << "0. Checkout" << endl;
		cin >> kaupa;

		while (kaupa != 0){
			switch (kaupa){

			case 1:
				cout << "Thu baettir vid pensil, Total: " << total << " kr." << endl;
				for (int i = 0; i < 100; i++)
				{
					if (kennitala == mal.getKT())
					{
						mal.print();
						total += (999 * 0.9);
						break;
					}
				}
				break;
			case 2:
				total += 1500;
				cout << "Thu baettir vid 1L af Malningu, Total: " << total << " kr." << endl;
				break;
			case 3:
				total += 6500;
				cout << "Thu baettir vid 5L af Malningu, Total: " << total << " kr." << endl;
				break;
			case 4:
				total += 11490;
				cout << "Thu baettir vid 10L af Malningu, Total: " << total << " kr." << endl;
				break;
			case 5:
				int metra;
				cout << "Hversu marga metra? ";
				cin >> metra;
				total += 300 * metra;
				cout << "Thu baettir vid " << metra << " metra af vir, Total: " << total << " kr." << endl;
				break;
			case 6:
				total += 1500;
				cout << "Thu baettir vid 5M Netsnuru, Total: " << total << " kr." << endl;
				break;
			case 7:
				total += 2000;
				cout << "Thu baettir vid 10M HDMI snuru, Total: " << total << " kr." << endl;
				break;
			case 8:
				total += 500;
				cout << "Thu baettir vid klo, Total: " << total << " kr." << endl;
				break;
			case 9:
				total += 30000;
				cout << "Thu baettir vid tenglarennu, Total: " << total << " kr." << endl;
				break;
			case 10:
				total += 999;
				cout << "Thu baettir vid Twix, Total: " << total << " kr." << endl;
				break;
			default:
				cout << "Thu slost inn vitlaust";
				break;
			}
			
			cin >> kaupa;
			
		}
		
	};







		cout << total << endl;
		cout << "----------------" << endl;
		

		return 0;
	}

