// Lokaverkefni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sjoppa.h"
#include "Malari.h"
#include "Rafverktaki.h"
#include "Starfsmadur.h"
#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


using namespace std;


int main()
{
	Malari mal;
	Rafverktaki raf;
	Starfsmadur starf;
	LinkedList b = LinkedList();
	Sjoppa shop[10];

	int adgangur;
	int kaupa;
	int admin;
	string notendaInfo = "";
	string notendaKT;
	string notendaNafn;
	int notendaAfslattur = 0;
	string kennitala;
	int total = 0;
	int totaltemp = 0;	
	stringstream ss;

	b.createNode(&Malari("2308992829", "Hilmar", 10));
	b.createNode(&Malari("1811992029", "Janus", 10));
	b.createNode(&Malari("1826342309", "Dmitri", 10));
	b.createNode(&Rafverktaki("0405994799", "Elas", 15));
	b.createNode(&Rafverktaki("3333333333", "Eggert", 15));
	b.createNode(&Starfsmadur("2222222222", "Geir", 20));
	b.createNode(&Starfsmadur("2711912029", "Solvi", 20));

	
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
	do
	{		
		if (adgangur == 1)
		{
			total = 0;
			b.display();
			cout << "Kennitala:";
			cin >> kennitala;
			if (b.ktExists(kennitala,3))
			{
				adgangur = 3;
			}
			else if (b.ktExists(kennitala,1) || b.ktExists(kennitala,2))
			{
				adgangur = 2;
			}
			else
			{
				cout << "Það er enginn notandi með þessa kennitölu";
			}
		}
		switch (adgangur){
		case 2:
			cout << "--------------------------------------------" << endl;
			for (int i = 0; i < 10; i++)
			{
				shop[i].print();
				cout << "--------------------------------------------" << endl;
			}		
			cout << "0. Checkout" << endl;
			cin >> kaupa;

			while (kaupa != 0){
				switch (kaupa) {
				case 1:
					totaltemp = 999;
					if (b.ktExists(kennitala, 1))
					{
						total += totaltemp * 0.9;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid pensli, Total: " << total << " kr." << endl;
					break;
				case 2:
					totaltemp = 1500;
					if (b.ktExists(kennitala, 1))
					{
						total += totaltemp * 0.9;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid 1L malningu, Total: " << total << " kr." << endl;
					break;
				case 3:
					totaltemp = 6500;
					if (b.ktExists(kennitala, 1))
					{
						total += totaltemp * 0.9;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid 5L malningu, Total: " << total << " kr." << endl;
					break;
				case 4:
					totaltemp = 11490;
					if (b.ktExists(kennitala, 1))
					{
						total += totaltemp * 0.9;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid 10L malningu, Total: " << total << " kr." << endl;
					break;
				case 5:
					int metra;
					cout << "Hversu marga metra? ";
					cin >> metra;
					totaltemp = 300 * metra;
					if (b.ktExists(kennitala, 2))
					{
						total += totaltemp * 0.85;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid " << metra << " metra af vir, Total: " << total << " kr." << endl;
					break;
				case 6:
					totaltemp = 1500;
					if (b.ktExists(kennitala, 2))
					{
						total += totaltemp * 0.85;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid 5M Netsnuru, Total: " << total << " kr." << endl;
					break;
				case 7:
					totaltemp = 2000;
					if (b.ktExists(kennitala, 2))
					{
						total += totaltemp * 0.85;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid 10M HDMI snuru, Total: " << total << " kr." << endl;
					break;
				case 8:
					totaltemp = 500;
					if (b.ktExists(kennitala, 2))
					{
						total += totaltemp * 0.85;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid klo, Total: " << total << " kr." << endl;
					break;
				case 9:
					totaltemp = 30000;
					if (b.ktExists(kennitala, 2))
					{
						total += totaltemp * 0.85;
					}
					else if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid tenglarennu, Total: " << total << " kr." << endl;
					break;
				case 10:
					totaltemp = 999;
					if (b.ktExists(kennitala, 3))
					{
						total += totaltemp * 0.8;
					}
					else
					{
						total += totaltemp;
					}
					cout << "Thu baettir vid Twix, Total: " << total << " kr." << endl;
					break;
				default:
					cout << "Thu slost inn vitlaust";
					break;
				}
				cin >> kaupa;
				cout << total << endl;
				cout << "----------------" << endl;
				adgangur = 1;
			}
			break;
		case 3:
			cout << "1. Bua til notenda" << endl;
			cout << "2. Eyda Notenda" << endl;
			cout << "3. Versla" << endl;
			cin >> admin;
			switch (admin)
			{
			case 1:
				ss.clear();
				cout << "Sladu inn kennitolu, nafn og afslatt notenda: ";
				cin >> std::ws;
				cout << endl;
				getline(cin, notendaInfo);
				ss << notendaInfo;
				ss >> notendaKT >> notendaNafn >> notendaAfslattur;
				if (notendaAfslattur == 10)
				{
					b.createNode(&Malari(notendaKT, notendaNafn, notendaAfslattur));
				}
				else if (notendaAfslattur == 15)
				{
					b.createNode(&Rafverktaki(notendaKT, notendaNafn, notendaAfslattur));
				}
				else if (notendaAfslattur == 20)
				{
					b.createNode(&Rafverktaki(notendaKT, notendaNafn, notendaAfslattur));
				}
				else
				{
					cout << "Ekki hægt að búa til notenda með þennan afslátt";
				}
				b.display();
				break;
			case 2:
				cout << "Sladu inn kennitolu notenda til ad eyda: ";
				cin >> std::ws;
				cout << endl;
				getline(cin, notendaKT);
				b.deleteNode(notendaKT);
				b.display();
				break;
			case 3:
				adgangur = 2;
			default:
				break;
			}
			break;
		};
	} while (adgangur != 0);	


	return 0;
}
