// Lokaverkefni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sjoppa.h"
#include "Malari.h"
#include "Rafverktaki.h"
#include "Starfsmadur.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;
/*
class Vidskiptavinir{
private:
Malari *mal;
Rafverktaki *raf;
Starfsmadur *starf;


public:
Vidskiptavinir(){
*mal = Malari();
*raf = Rafverktaki();
*starf = Starfsmadur();
};
Vidskiptavinir(string kt, string nafn, int afslattur){
mal = new Malari[10];
raf = new Rafverktaki[10];
starf = new Starfsmadur[10];


};
};
*/
class LinkedList
{
private:
	typedef struct node
	{
		node* next;
		Malari dataMal;
		Rafverktaki dataRaf;
		Starfsmadur dataStarf;

	}*nodePtr;
	nodePtr head;
	nodePtr tail;

public:
	LinkedList()
	{
	}
	void createNode(Malari *Mal)
	{
		Malari newMal(*Mal);
		nodePtr n = new node;
		n->next = nullptr;
		n->dataMal = newMal;
		/*if (ktExists(kt, afslattur))
		{
		cout << "Cannot perform this operation: Flight with that id already exists" << endl;
		return;
		}*/
		if (head != nullptr)
		{
			tail = head;
			while (tail->next != nullptr)
			{
				tail = tail->next;

			}
			tail->next = n;
		}
		else
		{
			head = n;
			head->next = nullptr;
			return;
			/*Node *temp = new Node(kt, nafn, afslattur, type);
			if (head->Data.getKT() != kt)
			{
			temp->next = head;
			head = temp;
			}
			else
			{
			Node *current = head;
			Node *prev = head;
			while (current && current->Data.getKT() != kt)
			{
			prev = current;
			current = current->next;
			}
			prev->next = temp;
			temp->next = current;
			}*/

		}
	}
	void createNode(Rafverktaki *Raf)
	{
		Rafverktaki newRaf(*Raf);
		nodePtr n = new node;
		n->next = nullptr;
		n->dataRaf = newRaf;
		/*if (ktExists(kt, afslattur))
		{
		cout << "Cannot perform this operation: Flight with that id already exists" << endl;
		return;
		}*/
		if (head != nullptr)
		{
			tail = head;
			while (tail->next != nullptr)
			{
				tail = tail->next;

			}
			tail->next = n;
		}
		else
		{
			head = n;
			head->next = nullptr;
			return;
			/*Node *temp = new Node(kt, nafn, afslattur, type);
			if (head->Data.getKT() != kt)
			{
			temp->next = head;
			head = temp;
			}
			else
			{
			Node *current = head;
			Node *prev = head;
			while (current && current->Data.getKT() != kt)
			{
			prev = current;
			current = current->next;
			}
			prev->next = temp;
			temp->next = current;
			}*/

		}
	}
	void createNode(Starfsmadur *Starf)
	{
		Starfsmadur newStarf(*Starf);
		nodePtr n = new node;
		n->next = nullptr;
		n->dataStarf = newStarf;
		/*if (ktExists(kt, afslattur))
		{
		cout << "Cannot perform this operation: Flight with that id already exists" << endl;
		return;
		}*/
		if (head != nullptr)
		{
			tail = head;
			while (tail->next != nullptr)
			{
				tail = tail->next;

			}
			tail->next = n;
		}
		else
		{
			head = n;
			head->next = nullptr;
			return;
			/*Node *temp = new Node(kt, nafn, afslattur, type);
			if (head->Data.getKT() != kt)
			{
			temp->next = head;
			head = temp;
			}
			else
			{
			Node *current = head;
			Node *prev = head;
			while (current && current->Data.getKT() != kt)
			{
			prev = current;
			current = current->next;
			}
			prev->next = temp;
			temp->next = current;
			}*/

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
		node *syna = new node();
		syna = head;
		while (syna != nullptr)
		{
			if (syna->dataMal.getKT() == "" && syna->dataRaf.getKT() != "" && syna->dataStarf.getKT() == "")
			{
				syna->dataRaf.print();
				syna = syna->next;
			}
			else if (syna->dataMal.getKT() != "" && syna->dataRaf.getKT() == "" && syna->dataStarf.getKT() == "")
			{
				syna->dataMal.print();
				syna = syna->next;
			}
			else{
				syna->dataStarf.print();
				syna = syna->next;
			}
		}
	}
	string getKT(string kt)
	{
		node *syna = new node();
		syna = head;
		while (syna != nullptr)
		{
			if (syna->dataMal.getKT() == "" && syna->dataRaf.getKT() != "" && syna->dataStarf.getKT() == "")
			{
				while (head->dataRaf.getKT() != kt)
				{
					syna->next = head;
					head = syna;
				}
				return syna->dataRaf.getKT();

			}
			else if (syna->dataMal.getKT() != "" && syna->dataRaf.getKT() == "" && syna->dataStarf.getKT() == "")
			{
				if (head->dataMal.getKT() != kt)
				{
					syna->next = head;
					head = syna;
				}
				else
				{
					return syna->dataMal.getKT();
				}
			}

			else if (syna->dataMal.getKT() == "" && syna->dataRaf.getKT() == "" && syna->dataStarf.getKT() != "")
			{
				if (head->dataStarf.getKT() != kt)
				{
					syna->next = head;
					head = syna;
				}
				else
				{
					return syna->dataStarf.getKT();
				}
			}

		}

	}
	/*bool ktExists(string kt, int afslattur)
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
	}*/
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
	Malari mal;
	Rafverktaki raf;
	Starfsmadur starf;

	int adgangur;
	string kennitala;
	int kaupa;
	double total = 0.0;
	double totaltemp = 0.0;
	LinkedList b = LinkedList();
	b.createNode(&Malari("2308992829", "Hilmar", 10));
	b.createNode(&Malari("0000000000", "Peter", 10));
	b.createNode(&Malari("1811992029", "Janus", 10));
	b.createNode(&Malari("1826342309", "Dmitri", 10));
	b.createNode(&Rafverktaki("0405994799", "Elas", 15));
	b.createNode(&Rafverktaki("3333333333", "Eggert", 15));
	b.createNode(&Starfsmadur("2222222222", "Geir", 20));
	b.createNode(&Starfsmadur("2711912029", "Solvi", 20));

	Sjoppa shop[10];
	shop[0] = Sjoppa("1. Pensill            ", 999, "  Malningadeild");
	shop[1] = Sjoppa("2. Blondud malning 1L ", 1500, " Malningadeild");
	shop[2] = Sjoppa("3. Blondud malning 5L ", 6500, " Malningadeild");
	shop[3] = Sjoppa("4. Blondud malning 10L", 11490, "Malningadeild");
	shop[4] = Sjoppa("5. Vir 1M             ", 300, "   Rafindadeild");
	shop[5] = Sjoppa("6. Netsnura 5M        ", 1500, "  Rafindadeild");
	shop[6] = Sjoppa("7. HDMI Snura 10M     ", 2000, "  Rafindadeild");
	shop[7] = Sjoppa("8. Klo                ", 500, "   Rafindadeild");
	shop[8] = Sjoppa("9. Tenglarenna        ", 300000, "Rafindadeild");
	shop[9] = Sjoppa("10.Twix               ", 999, "        Almennt");



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
				total += 999;
				while (b.getKT(kennitala) == kennitala)
				{

					totaltemp = total * 0.9;
					break;
				}
				total = totaltemp;
				cout << "Thu baettir vid pensli, Total: " << total << " kr." << endl;

				break;
			case 2:
				total += 1500;
				while (b.getKT(kennitala) == kennitala)
				{

					totaltemp = total * 0.9;
					total = totaltemp;

					break;

				}
				cout << "Thu baettir vid 1L malningu, Total: " << total << " kr." << endl;
				break;
			case 3:
				total += 4999;
				while (b.getKT(kennitala) == kennitala)
				{

					totaltemp += total * 0.9;
					total = totaltemp;

					break;

				}
				cout << "Thu baettir vid 5L malningu, Total: " << total << " kr." << endl;
				break;
			case 4:
				total += 11490;
				while (b.getKT(kennitala) == kennitala)
				{

					totaltemp += total * 0.9;
					total = totaltemp;

					break;

				}
				cout << "Thu baettir vid 10L malningu, Total: " << total << " kr." << endl;
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
				if (b.getKT(kennitala) == kennitala)
				{

					totaltemp += total * 0.85;
					cout << "Thu baettir vid 5M Netsnuru, Total: " << totaltemp << " kr." << endl;
				}
				else{
					cout << "Thu baettir vid 5M Netsnuru, Total: " << total << " kr." << endl;
				}
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



