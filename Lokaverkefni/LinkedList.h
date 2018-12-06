#pragma once
#include "Malari.h"
#include "Rafverktaki.h"
#include "Starfsmadur.h"
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
	LinkedList();
	void createNode(Malari *Mal);
	void createNode(Rafverktaki *Raf);
	void createNode(Starfsmadur *Starf);
	void deleteNode(string kt);
	void display();
	string getKT(string kt);
	bool ktExists(string kt, int type = 0);
};

