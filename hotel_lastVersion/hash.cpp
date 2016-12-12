#include "hash.h"

Hash::Hash() {
	for (int i = 0; i < MAX; i++) {
		hashMas[i].index = -1;
		hashMas[i].next = NULL;
		hashMas[i].g = NULL;
	}
	string name, lName; int p, n, ar;
	static Guest **mas;
	static int l = 0;
	mas = new Guest*[l];
	ifstream f("gs.txt");
	if (f) {
		while (!f.eof()) {
			Guest **m;
			m = new Guest*[l + 1];
			if (l>0) for (int i = 0; i<l; i++) m[i] = mas[i];
			delete[] mas;
			f >> p >> name >> lName >> n >> ar;
			m[l] = new Guest(name, lName, p);
			m[l]->setArrivalDate(ar);
			m[l]->setNumber(n);
			l++;
			mas = new Guest*[l];
			for (int i = 0; i<l; i++) mas[i] = m[i];
			delete[] m;

		}
		for (int i = 0; i<l; i++) this->add(mas[i]);
	}
	f.close();
	
}

int Hash::hashF(Guest *g)
{
	int res;
	res = g->getPassport() % MAX;
	return res;
}

void Hash::add(Guest *g)
{
	int h;
	struct hashType *p;
	h = hashF(g);

	if (hashMas[h].index == -1) {
		hashMas[h].index = h;
		hashMas[h].g = g;
	}
	else
	{
		struct hashType *temp = new struct hashType;
		temp->next = hashMas[h].next;
		temp->index = h;
		temp->g = g;
		hashMas[h].next = temp;
	}
}

Guest* Hash::find(Guest *g)
{
	int h;
	struct hashType *p;
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