/*� ���� ���� ����� ��������� ����� ����� �������� ���� �� ������
��� ������� ������ ���� - ���� ���� */

#include "guest.h"

typedef struct {
	Guest *g; //�����
	int date; // ���� ������ 
} Item;

class Heap {
	Item *h;
	int size; //������ ����

public:
	int getSize() { return size; };
	void up(int); //���������� ���� �����
	void down(int); //���������� ���� ������
	Heap();
	~Heap();
	void add(Guest*, int); //���������� ������ ����� � ���� � ����������� �� ���� ������
	Guest* extract_min();  //����� �����, ������� ������� ������ 
};