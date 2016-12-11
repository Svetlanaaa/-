#pragma once
#include "list.h"
#include "heap.h"

class Hotel {
	public:
		Heap guestsOfDec;
		List rooms;   // ������� ������ ������
		Hotel();   // �����������
		~Hotel();  // ����������
		List freeRooms(); //������� ��������� �������
		void showRooms(); //�������� ��� �������
		void showRooms(List); //�������� ��������� �������
		int settle(Guest*); //�������� ������ �����. �� ������ - ����� �������, � ������� �� ��� �������.
		void moveOut(Guest*); //�������� ����� �� ������� num

};