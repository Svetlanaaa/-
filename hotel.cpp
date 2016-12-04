#include "hotel.h";
#include "guest.h"
#include "list.h"


using namespace std;

Hotel::Hotel() {
	
};

Hotel::~Hotel()// деструктор
{ //удалить связный список из комнат
//	delete &rooms;
};

List Hotel::freeRooms() //находит свободные комнаты
{
	Node *temp = &rooms.getHead(); //указатель, который изначально равен адресу начала списка
	List freeR; //список свободных комнат
	while (temp != NULL) //пока не встретит пустое значени
	{
			if (temp->r->getGuestRoom() == NULL) //Если комната списка не имеет жителя
			{
				freeR.add(temp->r); //Добавить эту комнату в список свободных комнат
			}
			temp = temp->next; //Указатель перемещается на следующий элемент
		};
	return freeR; 
};

void Hotel::showRooms() //Показать все комнаты
{
	rooms.show();
};

void Hotel::showRooms(List f_rooms) //Показать свободные комнаты
{
	f_rooms.show();
};

int Hotel::settle(Guest* g) //Заселить нового гостя. На выходе - номер комнаты, в которую он был заселен.
{
	int n; //номер комнаты,которую хочет снять гость
	List f_rooms; //свободные комнаты
	f_rooms = freeRooms(); //поиск свободных в отеле комнат
	showRooms(f_rooms); //вывод свободных комнат
	cout << "Введите номер комнаты, которую вы хотите снять: ";
	cin >> n;
	bool f = 0; //гость не заселен
	Node *temp = &rooms.getHead(); //указатель, который изначально равен адресу начала списка
	while (!f) //пока гость не заселен
	{
		if (temp->r->getN() == n) //если указывается на комнату с выбранным гостем номером
		{
			temp->r->settle(g); //заселить гостя g в комнату с номером n
			f = 1; //гость заселен
		}
		else { temp = temp->next; }; //Указатель перемещается на следующий элемент
	};	
	//guestsOfDec.add(g, g->getArrivalDate());
	return n;
};

void Hotel::moveOut( int n) //Выселить гостя из комнаты num
{
	bool f = 0; //гость не выселен
	Node *temp = &rooms.getHead(); //указатель, который изначально равен адресу начала списка
	while (!f) //пока гость не выселен
	{
		if (temp->r->getN() == n) //если указывается на комнату с выбранным гостем номером
		{
			temp->r->moveOut(); //выселить гостя g из комнаты с номером n
			f = 1; //гость выселен
		}
		else { temp = temp->next; }; //Указатель перемещается на следующий элемент
	};

};