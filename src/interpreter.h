#include "token.h"
#include "grammar.h"
//#include "vector.h"
#include <variant>
#include <stack>
#include <vector>
#pragma once

struct progress {token tok; int prodNum; int depth;};
struct variable {symbol* mySymbol; TOKENID id;};

class interpreter
{
public:
    void                                        push(token top, int prodNum);
                                                interpreter();
private:
    stack <progress>                            advancement;
    vector <variant<int, float, string>>        value;
    vector <variable>                           var;
    void                                        increment();
    void                                        declare(token top);
    token                                       expression(token top);
    void                                        simplify(vector<token>& myList);
};
