#include <string>
#include <stack>
#include "scanner.h"
#include "grammar.h"
#include "interpreter.h"
#pragma once

class parser {
public:
	std::string                     compile(std::string fn);
private:
	std::stack<token>               tokStack;
	std::stack<std::array<int, 2>>  progress;
	scanner                         scan;
	token                           top, nextToken;
	std::string                     parseError = "";
	interpreter                     myInterpreter;
	int                             selectProd();
	void                            pushProdRHS(int prodNum);
	bool                            startup(std::string filename);
};
