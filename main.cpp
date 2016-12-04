#include <stdio.h>
#include <locale>
#include <fstream>
#include "room.h"
#include "hotel.h"
#include "guest.h"
#include "suite.h"
#include "luxury_suite.h"


int main(void) {
	
	setlocale(LC_ALL, "RUS");
	int n, pr, num_of_g;
	bool br, t, tv, air, m_g, s, p, a_b, k;
	Hotel new_h;
	ifstream f;
	ofstream f1;
		f.open("test.txt");
		if (f ) {
			f >> n >> pr >> num_of_g >> br >> t >> tv >> air;
			Room r1(n, pr, num_of_g, br, t, tv, air);

			f >> n >> pr >> num_of_g >> br >> t >> tv >> air;
			Room r2(n, pr, num_of_g, br, t, tv, air);

			f >> n >> pr >> num_of_g >> br >> t >> tv >> air;
			Room r3(n, pr, num_of_g, br, t, tv, air);

			f >> n >> pr >> num_of_g >> br >> t >> tv >> air;
			Room r4(n, pr, num_of_g, br, t, tv, air);

			f >> n >> pr >> num_of_g >> br >> t >> tv >> air >> m_g >> s >> p >> a_b;
			Suite r5(m_g, s, p, a_b, n, pr, num_of_g, br, t, tv, air);

			f >> n >> pr >> num_of_g >> br >> t >> tv >> air >> m_g >> s >> k;
			Luxury_suite r6(m_g, s, k, n, pr, num_of_g, br, t, tv, air);
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
					if (g.getNumber() != 0) {
						cout << "����� ��� ������������";
						break;
					}
					g.takeRoom(&new_h);
					cout << "����� ������� ������������!";
					std::ofstream f1("gs.txt", std::ios::app);
					f1 << g.getPassport() << " " << g.getName() << " " << g.getLastname() << " " << g.getNumber() << " " << g.getArrivalDate() << "\n";//���������� ���������� � ����
					f1.close();//��������� ����
					break;
				}
				case 2: {
					if (g.getNumber() == 0) {
						cout << "��������������� ������� ���";
						break;
					}
					g.checkOut(&new_h);
					cout << "\n����� ��������";
				/*	int ar, p1, i=0;
					ifstream f1("gs.txt");
					while (!f1.eof()) {
							i++;
							f1 >> p1 >> name >> last_name >> n >> ar;
							if (p == p1) break;
					}
					int i_number_line_now = 0; //������� �����
					string line; //��� �������� ������
					string line_file_text = ""; //��� �������� ������ �����

					while (getline(f1, line))
					{
						i_number_line_now++;
						if (!(i_number_line_now == i))
						{
							line_file_text = line_file_text + line; /*�������� ������*/
						/*}
					}
					f1.close();
					ofstream f2;
					f2.open("gs.txt"); //������� � ��������		
					f2 << line_file_text;
					f2.close();*/
					break;
				}
				};
			} while (a != 3);

		
		}
		else cout << "������";
	system("pause");
	return 0;
};