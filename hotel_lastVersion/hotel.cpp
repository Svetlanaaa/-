#include "hotel.h";
#include "guest.h"
#include "list.h"
#include <fstream>

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
			if (temp->r->getZ() == 0) //Если комната списка не имеет жителя
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
	int n,k; //номер комнаты,которую хочет снять гость
	List f_rooms; //свободные комнаты
	f_rooms = freeRooms(); //поиск свободных в отеле комнат
	showRooms(f_rooms); //вывод свободных комнат
	cout << "Введите номер комнаты, которую вы хотите снять: ";
	cin >> n;
	cout << "Введите дату заезда: "; cin >> k;
	g->setArrivalDate(k);
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
	guestsOfDec.add(g, g->getArrivalDate());
	cout << "\n\nКуча отеля";
	while (guestsOfDec.getSize() != 0) {

		cout << "\n" << guestsOfDec.extract_min()->getPassport();
	}
	int i = 0;
	ifstream ifs("test.txt");
	string res = "", finded, replaced = "1"; finded = to_string(n);
	while (!ifs.eof())
	{
		string tmp;
		i++;
		ifs >> tmp;
		if (tmp == finded && (i == 1 || i % 8 == 1))
		{
			i++;
			ifs >> tmp;
			tmp = replaced;
			res = res + finded + " " + tmp;
		}
		else  res = res + tmp;
		if (i % 8 == 0) res = res + "\n"; else res = res + " ";

	}
	ofstream ofs("test.txt");
	ofs << res;
	ofs.close();
	ifs.close();
	cout << "Номер успешно забронирован!";
	std::ofstream f1("gs.txt", std::ios::app);
	f1 << "\n" << g->getPassport() << " " << g->getName() << " " << g->getLastname() << " " << to_string(n) << " " << g->getArrivalDate();//записываем переменную в файл
	f1.close();//Закрываем файл*/
	return n;
};

void Hotel::moveOut(Guest* g) //Выселить гостя из комнаты n
{
	int i = 0, f1 = 0;
	ifstream ifs1("gs.txt");
	string res1 = "", finded1; finded1 = to_string(g->getPassport());
	while (!ifs1.eof())
	{
		string tmp;
		i++;
		ifs1 >> tmp;
		if (tmp == finded1)
		{
			f1 = 1;
			for (int j = 1; j < 5; j++)
			{
				i++;
				ifs1 >> tmp;
				if (j == 3) g->setNumber(stoi(tmp));
			};
			if (res1.length())
			{
				res1.erase(res1.length() - 1, 1);
				if (!ifs1.eof()) res1 += "\n";
			}
		}
		else  res1 = res1 + tmp;
		if ((f1 == 0 || f1 == 2) && !ifs1.eof()) if (i % 5 == 0) res1 = res1 + "\n"; else res1 = res1 + " ";
		else f1 = 2;
	}
	ofstream ofs1("gs.txt");
	ofs1 << res1;
	ofs1.close();
	ifs1.close();
	if (f1 == 0) {
		cout << "Забронированных номеров нет";
		return;
	}
	bool f = 0; //гость не выселен
	Node *temp = &rooms.getHead(); //указатель, который изначально равен адресу начала списка
	while (!f) //пока гость не выселен
	{
		if (temp->r->getN() == g->getNumber()) //если указывается на комнату с выбранным гостем номером
		{
			temp->r->moveOut(); //выселить гостя g из комнаты с номером n
			f = 1; //гость выселен
		}
		else { temp = temp->next; }; //Указатель перемещается на следующий элемент
	};
	
	i = 0;
	ifstream ifs("test.txt");
	string res = "", finded, replaced = "0"; finded = to_string(g->getNumber());
	while (!ifs.eof())
	{
		string tmp;
		i++;
		ifs >> tmp;
		if (tmp == finded && (i == 1 || i % 8 == 1))
		{
			i++;
			ifs >> tmp;
			tmp = replaced;
			res = res + finded + " " + tmp;
		}
		else  res = res + tmp;
		if (i % 8 == 0) res = res + "\n"; else res = res + " ";

	}
	ofstream ofs("test.txt");
	ofs << res;
	ofs.close();
	ifs.close();
	cout << "\nБронь отменена";
};