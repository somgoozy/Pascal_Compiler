#include "token.h"
#include "grammar.h"
#include "bucket.h"
#include <variant>
#include <stack>
#include <vector>
#pragma once

struct progress { token tok; int prodNum; int depth; };
struct value { token tok; bucket tokVal; };


class interpreter {
public:
	void                push(token top, int prodNum);
	interpreter();
private:
	std::stack<progress>    advancement;
	std::vector<value>      var;
	void                    increment();
	void                    declare(token top);
	value                   expression(token top);
	void                    simplify(std::vector<value>& myList);
	void                    doParenth(std::vector<value>& myVector);
	bucket                  getVal(token myToken);
};
