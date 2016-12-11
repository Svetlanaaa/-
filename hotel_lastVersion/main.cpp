#include <stdio.h>
#include <locale>
#include <cstring> 
#include <fstream>
#include "room.h"
#include "hotel.h"
#include "guest.h"
#include "suite.h"
#include "luxury_suite.h"


int main(void) {
	
	setlocale(LC_ALL, "RUS");
	int n, pr, num_of_g;
	bool br, t, tv, air, z;
	Hotel new_h;
	ifstream f;
	ofstream f1;
		f.open("test.txt");
		if (f ) {
			f >> n >> z>> pr >> num_of_g >> br >> t >> tv >> air;
			Room r1(z,n, pr, num_of_g, br, t, tv, air);

			f >> n >> z >> pr >> num_of_g >> br >> t >> tv >> air;
			Room r2(z,n, pr, num_of_g, br, t, tv, air);

			f >> n >> z >> pr >> num_of_g >> br >> t >> tv >> air;
			Room r3(z,n, pr, num_of_g, br, t, tv, air);

			f >> n >> z >> pr >> num_of_g >> br >> t >> tv >> air;
			Room r4(z,n, pr, num_of_g, br, t, tv, air);

			f >> n >> z >> pr >> num_of_g >> br >> t >> tv >> air;
			Suite r5(z, n, pr, num_of_g, br, t, tv, air);

			f >> n >> z >> pr >> num_of_g >> br >> t >> tv >> air;
			Luxury_suite r6(z, n, pr, num_of_g, br, t, tv, air);
			f.close();

			new_h.rooms.add(&r1);
			new_h.rooms.add(&r2);
			new_h.rooms.add(&r3);
			new_h.rooms.add(&r4);
			new_h.rooms.add(&r5);
			new_h.rooms.add(&r6);

			string name, last_name;
			int p, a=0;
			cout << "���� ���: "; cin >> name;
			cout << "���� �������: "; cin >> last_name;
			cout << "����� � ����� �������� (��� �������): "; cin >> p;
			Guest g(name, last_name, p);
			
			cout << "\n			����\n1) ������������� �����\n2) �������� �����\n3)�����";\
			do {
				cout << "\n\n������� ����� ���������� ������ ����: ";cin >> a;
				switch (a) {
				case 1:
				{
					cout << "			������������ ������\n";
					g.takeRoom(&new_h);
					break;
				}

				case 2: {
					g.checkOut(&new_h);
					break;
				}
				};
			} while (a != 3);
		}
		else cout << "������";
	system("pause");
	return 0;
};