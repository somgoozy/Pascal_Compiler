#include "symbol.h"
#include <vector>
#pragma once

const int NUMBER_OF_BUCKETS = 10000;

class symbolTable{
public:
	symbol* search(string lex);
	symbol* insert(string newlex);
private:
	symbol* bucket[NUMBER_OF_BUCKETS];
	int hash(string lexToHash);
};

