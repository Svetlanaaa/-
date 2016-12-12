#pragma once
#include "list.h"
#include "heap.h"
#include "hash.h"

class Hotel {
	public:
		Hash myHash;
		Heap guestsOfDec;
		List rooms;   // связный список комнат
		Hotel();   // конструктор
		~Hotel();  // деструктор
		List freeRooms(); //находит свободные комнаты
		void showRooms(); //показать все комнаты
		void showRooms(List); //показать свободные комнаты
		int settle(Guest*); //Заселить нового гостя. На выходе - номер комнаты, в которую он был заселен.
		void moveOut(Guest*); //Выселить гостя из комнаты num

};
