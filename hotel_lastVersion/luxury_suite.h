#pragma once
#include "room.h"

class Luxury_suite : public Room {
	bool morning_gown; //халат
	bool  slippers; //тапочки
	bool  kitchen; //кухня

public:
	Luxury_suite(bool z, int n, int pr, int num_of_g, bool br, bool t, bool tv, bool air) :Room(z, n, pr, num_of_g, br, t, tv, air) {
		morning_gown = 1;
		slippers = 1; //тапочки
		kitchen = 1;
	}
	void showRoom()
	{
		Room::showRoom();
		cout << "Дополнительные услуги:\n    Халат\n    Тапочки\n    Кухня в номере\n";
	}
};
