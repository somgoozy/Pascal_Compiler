#include <string>
#include <stack>
#include "scanner.h"
#include "grammar.h"
#include "interpreter.h"
#pragma once

class parser {
public:
	string compile(string fn);
private:
	stack<token>            tokStack;
	stack<array<int, 2>>    progress;
	scanner                 scan;
	token                   top, nextToken;
	string                  parseError = "";
	interpreter             myInterpreter;

	int     selectProd();
	void    pushProdRHS(int prodNum);
	bool    startup(string filename);
};
