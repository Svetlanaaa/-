#pragma once
#include "room.h"

class Luxury_suite : public Room {
	bool morning_gown; //�����
	bool  slippers; //�������
	bool  kitchen; //�����

public:
	Luxury_suite(bool m_g,bool s, bool k, int n, int pr, int num_of_g, bool br, bool t, bool tv, bool air) :Room(n, pr, num_of_g, br, t, tv, air) {
		morning_gown = m_g;
		slippers = s; //�������
		kitchen = k;
	}
	void showRoom()
	{
		Room::showRoom();
		cout << "�������������� ������:\n    �����\n    �������\n    ����� � ������\n";
	}
};
