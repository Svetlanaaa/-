#pragma once
#include <string>
#include "hotel.h"
using namespace std;

class Guest {
private:
	string name;
	string last_name;
	int number;
	int passport;

public:
	void setName(string g_name) {name = g_name;}
	string getName() {return name;}

	void setLastname(string g_lastname) {last_name = g_lastname;}
	string getLastname() {return last_name;}

	void setNumber(int num) {number = num;}
	int getNumber() {return number;}

	void setPasport(int pass) {passport = pass;}
	int getPassport() {return passport;}

	void takeRoom(Hotel*); //снять номер
    
	void checkOut(Hotel*); //Выехать из номера.

	Guest(string n, string last_n, int pass) { //Конструктор
		name = n;
		last_name = last_n;
		passport = pass;
	}
 
	~Guest() {}
	
};
