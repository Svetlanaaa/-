#pragma once
#include "list.h"

class Hotel {
	public:
		List rooms;   // связный список комнат
		Hotel();   // конструктор
		~Hotel();  // деструктор
		List freeRooms(); //находит свободные комнаты
		void showRooms(); //показать все комнаты
		void showRooms(List); //показать свободные комнаты
		int settle(Guest*); //Заселить нового гостя. На выходе - номер комнаты, в которую он был заселен.
		void moveOut(int); //Выселить гостя из комнаты num

};