#pragma once
#include "room.h"

class Suite : public Room {
	bool morning_gown; //халат
	bool  slippers; //тапочки
	bool  pool; //бассейн
	bool allyoucaneat_buffet; //шведский стол

public:
	Suite(bool m_g, bool s, bool p, bool a_b, int n, int pr, int num_of_g, bool br, bool t, bool tv, bool air) :Room(n, pr, num_of_g, br, t, tv, air) {
		morning_gown = m_g;
		slippers = s; //тапочки
		pool = p; //бассейн
		allyoucaneat_buffet = a_b;
}
void showRoom()
	{
	Room::showRoom();
		cout << "Дополнительные услуги:\n    Халат\n    Тапочки\n    Бассейн\n    Шведский стол\n";
	}
};