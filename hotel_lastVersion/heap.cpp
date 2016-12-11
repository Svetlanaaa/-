#include "heap.h"
#include <fstream>
#include <iostream>
void Heap::up(int c) { //���������� ���� �����
	int p;
	p = c / 2; //�������� ����� �������� �������� � �������
	if (p == 0) return; //���� �������� ���, �� ������������
	if (h[p].date > h[c].date) { //���� ��������� �������� ���� ���������� �������
		Item tmp;
		tmp = h[p];
		h[p] = h[c];
		h[c] = tmp; //������ �������� � ������� �������
		up(p); //��������� ���������� ��������
	}
}

void Heap::down(int p) { //���������� ���� ������
	int c;
	c = 2 * p; //������� ����� �������� ������� ������� � �������
	if (c > size) return; //���� ������ ������� ���, �� ������������
	if (c + 1 <= size && h[c + 1].date < h[c].date) //��������� ���� �� ������ ������� � �������� ������� � ���������� �����������
	{c++;}; //���� � ������� ������� ��������� ����, �� ��������� � ����
	if (h[c].date < h[p].date) { //���� ��������� ������� ���� ���������� ��������
		Item tmp;
		tmp = h[c]; 
		h[c] = h[p]; 
		h[p] = tmp; //������ �� �������
		down(c); //��������� ���������� ������� (������������ ������� ��������� �� ��������) 
	}
}

Heap::Heap() {
	int p, n, ar;
	string name, lName;
	size = 0; //���������� ��������� � ����=0
	h = new Item[31]; //������������ ��������� ������ ��� n ���������
	static Guest **mas;
	static int l = 0;
	mas = new Guest*[l];
	ifstream f("gs.txt");
	if (f) {
		while (!f.eof()) {
			Guest **m;
			m = new Guest*[l+1]; //1 2 3
			if (l>0) for(int i=0; i<l; i++) m[i] = mas[i];//0  1 2
			delete[] mas;
			f >> p >> name >> lName >> n >> ar;
			m[l] = new Guest(name, lName, p);//0 1 2
			m[l]->setArrivalDate(ar);
			m[l]->setNumber(n);
			l++;//1 2 3
			mas = new Guest*[l];//1 2 3
			for (int i = 0; i<l; i++) mas[i] = m[i];//1 2 3
			delete[] m;
			
		}
		for (int i=0 ; i<l ; i++) this->add(mas[i], mas[i]->getArrivalDate());
	}
	f.close();
}

Heap::~Heap() {
	if (h) delete [] h; //������������ ������ ��-��� ����
}

void Heap::add(Guest* g, int arrivalDate) { //���������� ��������
	Item x;
	x.g = g; x.date = arrivalDate;
	h[++size] = x; //���������� � ��������� ������� ���� ����� �������
	up(size); //���������� ���� ����� 
}

Guest* Heap::extract_min() {
	if (size == 0) return NULL; //���� � ���� ��� ���������
	Guest* res;
	res= h[1].g; //�������� ���������� ����, ����������� ������� - ������ 
	h[1] = h[size--]; //���������� � ������ ������� ���������
	down(1); //���������� ���� ������
	return res;
}

