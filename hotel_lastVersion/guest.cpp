#include "guest.h"
#include "hotel.h"

void Guest::takeRoom(Hotel *H) { //����� �����
	int n;
	n = H->settle(this);  //����� ������ ������ Hotel. n - ����� �������, ������� ���� �����. 
	number = n; //������ � ���� "����� �������" ������, � ������� ����� �����
};

void Guest::checkOut(Hotel *H) { //������� �� ������.
	H->moveOut(this);
};