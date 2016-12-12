#pragma once
#include "guest.h"

const int MAX = 180;
typedef struct{
	int index;   /* логический индекс */
	Guest* g;     /* собственно значение элемента данных */
	hashType *next; /* указатель на следующий элемент с таким же
						хэш-адресом */
} hashType;

class Hash {
	hashType hashMas[MAX];
public:
	Hash() {
		for (int i = 0; i < MAX; i++) {
			hashMas[i].index = -1;
			hashMas[i].next = NULL;  
			hashMas[i].g = NULL;
		}
	}

	int hashF(Guest *g)
	{
		int res;
		res = (g->getPassport() % 6) / MAX;
		res = res + (g->getPassport() / 6) / MAX;
		return res;
	}

	void add(Guest *g)
	{
		int h;
		hashType *p;
		h = hashF(g);

		if (hashMas[h].index == -1) {
			hashMas[h].index = h;
			hashMas[h].g = g;
		}
		else
		{
			hashType *temp = new hashType; 
			temp->next = hashMas[h].next; 
			temp->index = h;
			temp->g = g;
			hashMas[h].next = temp;
		}
	}

	Guest* find(Guest *g)
	{
		int h;
		hashType *p;
		h = hashF(g);
		if (hashMas[h].g == g) return(hashMas[h].g);
		else { 
			p = hashMas[h].next;
			while (p) {
				if (p->g == g) return p->g;
				p = p->next;
			}
			return NULL;
		}
	}
}