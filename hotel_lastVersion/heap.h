/*В этой куче будут храниться гости отеля согласно дате их заезда
Для каждого месяца года - своя куча */

#include "guest.h"

typedef struct {
	Guest *g; //гость
	int date; // дата заезда 
} Item;

class Heap {
	Item *h;
	int size; //размер кучи

public:
	int getSize() { return size; };
	void up(int); //сортировка кучи снизу
	void down(int); //сортировка кучи сверху
	Heap();
	~Heap();
	void add(Guest*, int); //добавление нового гостя в кучу в зависимости от даты заезда
	Guest* extract_min();  //взять гостя, который приедет первым 
};