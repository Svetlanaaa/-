#pragma once

#include <stdio.h>
#include <iostream>
#include "guest.h"
using namespace std;

class Room {
private:
	int n;
	int price; //����
	int num_of_guests; //���������� ���� � ������
	Guest* guest_room; //��������� �� �����, ������� ����� � ���� ������
	bool breakfast; //������� ��������
	bool telephone; //������� ��������
	bool air_conditioning; //������� ������������
	bool television; //������� ����������
	bool z;
public:
	void setN(int num) { n = num; }
	int getN() { return n; }

	void setGuestRoom(Guest* g) { if (g != nullptr) { guest_room = g; } else { guest_room = new Guest(g->getName(), g->getLastname(), g->getNumber()); } }
	Guest* getGuestRoom() {return guest_room;}

	void setZ(bool nZ) {z = nZ;}
	bool getZ() {return z;}

	void settle(Guest* g) 
	{ //��������
		guest_room = g;	
		z = 1;
	}
	
	void moveOut() 
	{ //��������
		guest_room = NULL; 
		z = 0;
	}

	Room(bool nZ, int n1, int pr, int num_of_g, bool br, bool t, bool tv, bool air)
	{
		z = nZ;
		n = n1;
		price = pr;
		num_of_guests = num_of_g;
		guest_room = NULL;
		breakfast = br;
		telephone = t;
		air_conditioning = air;
		television = tv;
    }

	~Room() {}

	virtual void showRoom()
	{
		cout << "������� �" << n << endl;
		cout << "��������������:";
		cout << "	����: " << price << "���." << endl;
		cout << "	���������� ����: " << num_of_guests << endl;
		cout << "	�������: "; if (breakfast) { cout << "+" << endl; } else { cout << "-" << endl; };
		cout << "	�������:" ; if (telephone) { cout << "+" << endl; } else { cout << "-" << endl; };
		cout << "	�����������:"; if (air_conditioning) { cout << "+" << endl; } else { cout << "-" << endl; };
		cout << "	���������:" ; if (television) { cout << "+" << endl; } else { cout << "-" << endl; };
	}
};
