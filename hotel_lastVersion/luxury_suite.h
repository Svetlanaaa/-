#pragma once
#include "room.h"

class Luxury_suite : public Room {
	bool morning_gown; //�����
	bool  slippers; //�������
	bool  kitchen; //�����

public:
	Luxury_suite(bool z, int n, int pr, int num_of_g, bool br, bool t, bool tv, bool air) :Room(z, n, pr, num_of_g, br, t, tv, air) {
		morning_gown = 1;
		slippers = 1; //�������
		kitchen = 1;
	}
	void showRoom()
	{
		Room::showRoom();
		cout << "�������������� ������:\n    �����\n    �������\n    ����� � ������\n";
	}
};
