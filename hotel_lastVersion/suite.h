#pragma once
#include "room.h"

class Suite : public Room {
	bool morning_gown; //халат
	bool  slippers; //тапочки
	bool  pool; //бассейн
	bool allyoucaneat_buffet; //шведский стол

public:
	Suite( bool z, int n, int pr, int num_of_g, bool br, bool t, bool tv, bool air) :Room(z, n, pr, num_of_g, br, t, tv, air) {
		morning_gown = 1;
		slippers = 1; //тапочки
		pool = 1; //бассейн
		allyoucaneat_buffet = 1;
}
void showRoom()
	{
	Room::showRoom();
		cout << "Дополнительные услуги:\n    Халат\n    Тапочки\n    Бассейн\n    Шведский стол\n";
	}
};