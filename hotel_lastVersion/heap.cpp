#include "heap.h"
#include <fstream>
#include <iostream>
void Heap::up(int c) { //сортировка кучи снизу
	int p;
	p = c / 2; //получаем номер элемента родителя в массиве
	if (p == 0) return; //если родителя нет, то возвращаемся
	if (h[p].date > h[c].date) { //если приоритет родителя выше приоритета потомка
		Item tmp;
		tmp = h[p];
		h[p] = h[c];
		h[c] = tmp; //меняем родителя и потомка местами
		up(p); //проверяем следующего родителя
	}
}

void Heap::down(int p) { //сортировка кучи сверху
	int c;
	c = 2 * p; //находим номер элемента первого потомка в массиве
	if (c > size) return; //если такого потомка нет, то возвращаемся
	if (c + 1 <= size && h[c + 1].date < h[c].date) //проверяем есть ли второй потомок и выбираем потомка с наименьшим приоритетом
	{c++;}; //если у второго потомка приоритет ниже, то переходим к нему
	if (h[c].date < h[p].date) { //если приоритет потомка ниже приоритета родителя
		Item tmp;
		tmp = h[c]; 
		h[c] = h[p]; 
		h[p] = tmp; //меняем их местами
		down(c); //проверяем следующего потомка (проверенного потомка принимаем за родителя) 
	}
}

Heap::Heap() {
	int p, n, ar;
	string name, lName;
	size = 0; //количество элементов в куче=0
	h = new Item[31]; //динамическое выделение памяти под n элементов
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
	if (h) delete [] h; //освобождение памяти из-под кучи
}

void Heap::add(Guest* g, int arrivalDate) { //добавление элемента
	Item x;
	x.g = g; x.date = arrivalDate;
	h[++size] = x; //записываем в следующий элемент кучи новый элемент
	up(size); //сортировка кучи снизу 
}

Guest* Heap::extract_min() {
	if (size == 0) return NULL; //если в куче нет элементов
	Guest* res;
	res= h[1].g; //согласно определнию кучи, минимальный элемент - первый 
	h[1] = h[size--]; //записываем в первый элемент последний
	down(1); //сортировка кучи сверху
	return res;
}

