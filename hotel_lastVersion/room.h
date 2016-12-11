#pragma once

#include <stdio.h>
#include <iostream>
#include "guest.h"
using namespace std;

class Room {
private:
	int n;
	int price; //цена
	int num_of_guests; //количество мест в номере
	Guest* guest_room; //указатель на гостя, который живет в этом номере
	bool breakfast; //наличие завтрака
	bool telephone; //наличие телефона
	bool air_conditioning; //наличие кондиционера
	bool television; //наличие телевизора
	bool z;
public:
	void setN(int num) { n = num; }
	int getN() { return n; }

	void setGuestRoom(Guest* g) { if (g != nullptr) { guest_room = g; } else { guest_room = new Guest(g->getName(), g->getLastname(), g->getNumber()); } }
	Guest* getGuestRoom() {return guest_room;}

	void setZ(bool nZ) {z = nZ;}
	bool getZ() {return z;}

	void settle(Guest* g) 
	{ //заселить
		guest_room = g;	
		z = 1;
	}
	
	void moveOut() 
	{ //выселить
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
		cout << "Комната №" << n << endl;
		cout << "Характеристики:";
		cout << "	Цена: " << price << "руб." << endl;
		cout << "	Количество мест: " << num_of_guests << endl;
		cout << "	Завтрак: "; if (breakfast) { cout << "+" << endl; } else { cout << "-" << endl; };
		cout << "	Телефон:" ; if (telephone) { cout << "+" << endl; } else { cout << "-" << endl; };
		cout << "	Кондиционер:"; if (air_conditioning) { cout << "+" << endl; } else { cout << "-" << endl; };
		cout << "	Телевизор:" ; if (television) { cout << "+" << endl; } else { cout << "-" << endl; };
	}
};
