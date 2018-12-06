#include "stdafx.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{	
}

void LinkedList::createNode(Malari *Mal)
{
	Malari newMal(*Mal);
	nodePtr n = new node;
	n->next = nullptr;
	n->dataMal = newMal;
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
	}
}

void LinkedList::createNode(Rafverktaki *Raf)
{
	Rafverktaki newRaf(*Raf);
	nodePtr n = new node;
	n->next = nullptr;
	n->dataRaf = newRaf;
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
	}
}

void LinkedList::createNode(Starfsmadur *Starf)
{
	Starfsmadur newStarf(*Starf);
	nodePtr n = new node;
	n->next = nullptr;
	n->dataStarf = newStarf;
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
	}
}

void LinkedList::display()
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
		else {
			syna->dataStarf.print();
			syna = syna->next;
		}
	}
}

string LinkedList::getKT(string kt)
{
	node *syna = new node();
	syna = head;
	while (syna != nullptr)
	{
		if (syna->dataMal.getKT() == "" && syna->dataRaf.getKT() != "" && syna->dataStarf.getKT() == "")
		{
			if (head->dataRaf.getKT() != kt)
			{
				syna->next = head;
				head = syna;
			}
			else
			{
				return syna->dataRaf.getKT();
			}

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

bool LinkedList::ktExists(string kt, int type)
{
	node *temp = new node;
	temp = head;
	while (temp != nullptr)
	{
		if (type == 1)
		{
			if (kt == "")
			{
				return false;
				break;
			}
			if (temp->dataMal.getKT() != kt)
			{
				if (temp->next != nullptr)
				{
					temp = temp->next;
				}
				else
				{
					return false;
					break;
				}
			}
			else if (temp->dataMal.getKT() == kt)
			{
				return true;
				break;
			}
		}
		else if (type == 2)
		{
			if (kt == "")
			{
				return false;
				break;
			}
			if (temp->dataRaf.getKT() != kt)
			{
				if (temp->next != nullptr)
				{
					temp = temp->next;
				}
				else
				{
					return false;
					break;
				}
			}
			else if (temp->dataRaf.getKT() == kt)
			{
				return true;
				break;
			}
		}
		else if (type == 3)
		{
			if (kt == "")
			{
				return false;
				break;
			}
			if (temp->dataStarf.getKT() != kt)
			{
				if (temp->next != nullptr)
				{
					temp = temp->next;
				}
				else
				{
					return false;
					break;
				}

			}
			else if (temp->dataStarf.getKT() == kt)
			{
				return true;
				break;
			}
		}
	}
}

void LinkedList::deleteNode(string kt)
{
	node *current = new node();
	node *prev = new node();
	current = head;
	while (current != nullptr)
	{
		if (current->dataMal.getKT() == kt)
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
		else if (current->dataRaf.getKT() == kt)
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
		else if (current->dataStarf.getKT() == kt)
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
		else
		{
			prev = current;
			current = current->next;
		}
	}
}