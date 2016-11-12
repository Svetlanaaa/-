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
	void up(int); //���������� ���� �����
	void down(int); //���������� ���� ������
	Heap(int);
	~Heap();
	void add(Guest*, int); //���������� ������ ����� � ���� � ����������� �� ���� ������
	Guest* extract_min();  //����� �����, ������� ������� ������ 
};

