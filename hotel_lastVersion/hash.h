#pragma once
#include "guest.h"
#include <fstream>

const int MAX = 97; 
struct hashType {
	int index;   
	Guest* g;    
	struct hashType *next; 
};

class Hash {
	struct hashType hashMas[MAX];
public:
	struct hashType* getHash() { return hashMas; };
	Hash();
	int hashF(Guest*);
	void add(Guest*);
	Guest* find(Guest*);
};
