#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "symbolTable.h"

symbol* symbolTable::insert(std::string newlex) {
	//insert lexeme into the symbol table
	symbol* s = search(newlex);
	if (!s) {
		int hv = hash(newlex);
		s = new symbol;
		s->setLex(newlex);
		s->next = bucket[hv];
		bucket[hv] = s;
	}
	return s;
}

int symbolTable::hash(std::string lexToHash) {
	//simple hashing function
	int sum = 0;
	for (int i = 0; i < (int)lexToHash.length(); i++) {
		sum += (int)lexToHash[i];
	}
	return sum % NUMBER_OF_BUCKETS;
}

symbol* symbolTable::search(std::string searchFor) {
	//search for reference to a given lexeme
	int hv = hash(searchFor);
	symbol* p = bucket[hv];
	//go through every bucket
	while (p) {
		if (p->lexeme == searchFor)
			return p;
		p = p->next;
	}
	//couldn't find it :'(
	return NULL;
}
