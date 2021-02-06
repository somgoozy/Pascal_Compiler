#include "interpreter.h"

void interpreter::push(token top, int prod){
    increment();
    if (top.isNonTerminal()){
        advancement.push({top, prod, 0});
    }
}

void interpreter::increment(){
    if (!advancement.empty()){
        advancement.top().depth++;
        while (PROD[advancement.top().prodNum][advancement.top().depth] == TOK_N_EPSILON || advancement.top().depth > GR_LAST_RHS){
            advancement.pop();
            advancement.top().depth++;
            if (!advancement.empty())
                break;
        }
    }
}
