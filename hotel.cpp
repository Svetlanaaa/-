#include "hotel.h";
#include "guest.h"
#include "list.h"


using namespace std;

Hotel::Hotel() {
	
};

Hotel::~Hotel()// ����������
{ //������� ������� ������ �� ������
//	delete &rooms;
};

List Hotel::freeRooms() //������� ��������� �������
{
	Node *temp = &rooms.getHead(); //���������, ������� ���������� ����� ������ ������ ������
	List freeR; //������ ��������� ������
	while (temp != NULL) //���� �� �������� ������ �������
	{
			if (temp->r->getGuestRoom() == NULL) //���� ������� ������ �� ����� ������
			{
				freeR.add(temp->r); //�������� ��� ������� � ������ ��������� ������
			}
			temp = temp->next; //��������� ������������ �� ��������� �������
		};
	return freeR; 
};

void Hotel::showRooms() //�������� ��� �������
{
	rooms.show();
};

void Hotel::showRooms(List f_rooms) //�������� ��������� �������
{
	f_rooms.show();
};

int Hotel::settle(Guest* g) //�������� ������ �����. �� ������ - ����� �������, � ������� �� ��� �������.
{
	int n; //����� �������,������� ����� ����� �����
	List f_rooms; //��������� �������
	f_rooms = freeRooms(); //����� ��������� � ����� ������
	showRooms(f_rooms); //����� ��������� ������
	cout << "������� ����� �������, ������� �� ������ �����: ";
	cin >> n;
	bool f = 0; //����� �� �������
	Node *temp = &rooms.getHead(); //���������, ������� ���������� ����� ������ ������ ������
	while (!f) //���� ����� �� �������
	{
		if (temp->r->getN() == n) //���� ����������� �� ������� � ��������� ������ �������
		{
			temp->r->settle(g); //�������� ����� g � ������� � ������� n
			f = 1; //����� �������
		}
		else { temp = temp->next; }; //��������� ������������ �� ��������� �������
	};	
	//guestsOfDec.add(g, g->getArrivalDate());
	return n;
};

void Hotel::moveOut( int n) //�������� ����� �� ������� num
{
	bool f = 0; //����� �� �������
	Node *temp = &rooms.getHead(); //���������, ������� ���������� ����� ������ ������ ������
	while (!f) //���� ����� �� �������
	{
		if (temp->r->getN() == n) //���� ����������� �� ������� � ��������� ������ �������
		{
			temp->r->moveOut(); //�������� ����� g �� ������� � ������� n
			f = 1; //����� �������
		}
		else { temp = temp->next; }; //��������� ������������ �� ��������� �������
	};

};