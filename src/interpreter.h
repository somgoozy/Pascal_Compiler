#include "token.h"
#include "grammar.h"
#include <variant>
#include <stack>
#include <vector>

#define VAL variant<int, string, bool, float>

#pragma once

struct progress { token tok; int prodNum; int depth; };
struct value { token tok; VAL tokVal; };


class interpreter
{
public:
	void                push(token top, int prodNum);
	interpreter();
private:
	stack<progress>     advancement;
	vector<value>       var;
	void                increment();
	void                declare(token top);
	value               expression(token top);
	void                simplify(vector<value>& myList);
	void                doParenth(vector<value>& myVector);
	VAL                 getVal(token myToken);
};
