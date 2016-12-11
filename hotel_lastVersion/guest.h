#pragma once
#include <string>
using namespace std;
class Hotel;
class Guest {
private:
	string name;
	string last_name;
	int number;
	int passport;
	int arrivalDate;

public:
	void setName(string g_name) {name = g_name;}
	string getName() {return name;}

	void setLastname(string g_lastname) {last_name = g_lastname;}
	string getLastname() {return last_name;}

	void setNumber(int num) {number = num;}
	int getNumber() {return number;}

	void setPasport(int pass) {passport = pass;}
	int getPassport() {return passport;}

	void setArrivalDate(int date) { arrivalDate = date; }
	int getArrivalDate() { return arrivalDate; }

	void takeRoom(Hotel*); //����� �����
    
	void checkOut(Hotel*); //������� �� ������.

	Guest(string n, string last_n, int pass) { //�����������
		name = n;
		last_name = last_n;
		passport = pass;
		arrivalDate = 0;
		number = 0;
	}
	~Guest() {}
	
};
