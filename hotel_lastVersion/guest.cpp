#include "guest.h"
#include "hotel.h"

void Guest::takeRoom(Hotel *H) { //сн€ть номер
	int n;
	n = H->settle(this);  //вызов метода класса Hotel. n - номер комнаты, которую сн€л гость. 
	number = n; //запись в поле "Ќомер комнаты" номера, в котором живет гость
};

void Guest::checkOut(Hotel *H) { //¬ыехать из номера.
	H->moveOut(this);
};