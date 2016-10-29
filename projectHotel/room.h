#pragma once

#include <stdio.h>
#include <iostream>
using namespace std;
class Guest;
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

public:
	void setN(int num) { n = num; }
	int getN() { return n; }

	void setPrice(int pr) { price = pr;}
	int getPrice()	{ return price; }

	void setGuests(int g) { num_of_guests = g;}
	int getGuests() {return num_of_guests;}

	void setGuestRoom(Guest* g) { guest_room = g;}
	Guest* getGuestRoom() {return guest_room;}

	void setBreakfast(bool b) { breakfast = b;}
	bool getBreakfast() {return breakfast;}

	void setTelephone(bool t) {telephone = t;}
	bool getTelephone() {return telephone;}

	void setTelevision(bool tv) {television = tv;}
	bool getTelevision() {return television;}

	void setAirConditioning(bool a) {air_conditioning = a;}
	bool getAirConditioning() {return air_conditioning;}

	void settle(Guest* g) 
	{ //заселить
		guest_room = g; //Ссылка на жильца номера
	}
	
	void moveOut() 
	{ //выселить
		guest_room = NULL; 
	}

	Room(int pr, int num_of_g, bool br, bool t, bool tv, bool air)
	{
		price = pr;
		num_of_guests = num_of_g;
		guest_room = NULL;
		breakfast = br;
		telephone = t;
		air_conditioning = air;
		television = tv;
    }

	~Room() {}

	void showRoom()
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
