#include "hotel.h";
#include "guest.h"
#include "list.h"
#include <fstream>

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
			if (temp->r->getZ() == 0) //���� ������� ������ �� ����� ������
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
	int n,k; //����� �������,������� ����� ����� �����
	List f_rooms; //��������� �������
	f_rooms = freeRooms(); //����� ��������� � ����� ������
	showRooms(f_rooms); //����� ��������� ������
	cout << "������� ����� �������, ������� �� ������ �����: ";
	cin >> n;
	cout << "������� ���� ������: "; cin >> k;
	g->setArrivalDate(k);
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
	guestsOfDec.add(g, g->getArrivalDate());
	cout << "\n\n���� �����";
	while (guestsOfDec.getSize() != 0) {

		cout << "\n" << guestsOfDec.extract_min()->getPassport();
	}
	int i = 0;
	ifstream ifs("test.txt");
	string res = "", finded, replaced = "1"; finded = to_string(n);
	while (!ifs.eof())
	{
		string tmp;
		i++;
		ifs >> tmp;
		if (tmp == finded && (i == 1 || i % 8 == 1))
		{
			i++;
			ifs >> tmp;
			tmp = replaced;
			res = res + finded + " " + tmp;
		}
		else  res = res + tmp;
		if (i % 8 == 0) res = res + "\n"; else res = res + " ";

	}
	ofstream ofs("test.txt");
	ofs << res;
	ofs.close();
	ifs.close();
	cout << "����� ������� ������������!";
	std::ofstream f1("gs.txt", std::ios::app);
	f1 << "\n" << g->getPassport() << " " << g->getName() << " " << g->getLastname() << " " << to_string(n) << " " << g->getArrivalDate();//���������� ���������� � ����
	f1.close();//��������� ����*/
	return n;
};

void Hotel::moveOut(Guest* g) //�������� ����� �� ������� n
{
	int i = 0, f1 = 0;
	ifstream ifs1("gs.txt");
	string res1 = "", finded1; finded1 = to_string(g->getPassport());
	while (!ifs1.eof())
	{
		string tmp;
		i++;
		ifs1 >> tmp;
		if (tmp == finded1)
		{
			f1 = 1;
			for (int j = 1; j < 5; j++)
			{
				i++;
				ifs1 >> tmp;
				if (j == 3) g->setNumber(stoi(tmp));
			};
			if (res1.length())
			{
				res1.erase(res1.length() - 1, 1);
				if (!ifs1.eof()) res1 += "\n";
			}
		}
		else  res1 = res1 + tmp;
		if ((f1 == 0 || f1 == 2) && !ifs1.eof()) if (i % 5 == 0) res1 = res1 + "\n"; else res1 = res1 + " ";
		else f1 = 2;
	}
	ofstream ofs1("gs.txt");
	ofs1 << res1;
	ofs1.close();
	ifs1.close();
	if (f1 == 0) {
		cout << "��������������� ������� ���";
		return;
	}
	bool f = 0; //����� �� �������
	Node *temp = &rooms.getHead(); //���������, ������� ���������� ����� ������ ������ ������
	while (!f) //���� ����� �� �������
	{
		if (temp->r->getN() == g->getNumber()) //���� ����������� �� ������� � ��������� ������ �������
		{
			temp->r->moveOut(); //�������� ����� g �� ������� � ������� n
			f = 1; //����� �������
		}
		else { temp = temp->next; }; //��������� ������������ �� ��������� �������
	};
	
	i = 0;
	ifstream ifs("test.txt");
	string res = "", finded, replaced = "0"; finded = to_string(g->getNumber());
	while (!ifs.eof())
	{
		string tmp;
		i++;
		ifs >> tmp;
		if (tmp == finded && (i == 1 || i % 8 == 1))
		{
			i++;
			ifs >> tmp;
			tmp = replaced;
			res = res + finded + " " + tmp;
		}
		else  res = res + tmp;
		if (i % 8 == 0) res = res + "\n"; else res = res + " ";

	}
	ofstream ofs("test.txt");
	ofs << res;
	ofs.close();
	ifs.close();
	cout << "\n����� ��������";
};