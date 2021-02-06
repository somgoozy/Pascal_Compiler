#include "token.h"
#include "grammar.h"
#include <stack>
#pragma once
struct progress {token tok; int prodNum; int depth;};

class interpreter
{
public:
    void                push(token top, int prodNum);
private:
    stack <progress>    advancement;
    void                increment();
};
