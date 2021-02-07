#include "interpreter.h"

void interpreter::push(token top, int prod){
    //move everything forward by 1
    increment();
    //if we are done
//needs to be done more smoothly
    if(advancement.empty()){
        return;
    }
    //push the nonterminal
    else if (top.isNonTerminal()){
        advancement.push({top, prod, GR_FIRST_RHS - 1});
    }
    //declarations
    else if (PROD[advancement.top().prodNum][0] == TOK_N_DECLARATIONS ||
             PROD[advancement.top().prodNum][0] == TOK_N_TYPE ||
             PROD[advancement.top().prodNum][0] == TOK_N_ID_LIST){
        declare(top);
    }
}

void interpreter::increment(){
    //if not empty progress
    if (!advancement.empty()){
        advancement.top().depth++;
        //if we hit the end we need to pop and make progress
        while (PROD[advancement.top().prodNum][advancement.top().depth] == TOK_N_EPSILON
               || advancement.top().depth > GR_LAST_RHS){
            advancement.pop();
            if(advancement.empty())
                break;
            advancement.top().depth++;
        }
    }
}

void interpreter::declare(token top){
    static stack <token>    idList;

    if (PROD[advancement.top().prodNum][0] == TOK_N_ID_LIST){
        if (PROD[advancement.top().prodNum][advancement.top().depth] == TOK_IDENT){
            idList.push(top);
        }
    }
    else if (PROD[advancement.top().prodNum][0] == TOK_N_TYPE){
        for (int i = 0; i < idList.size(); i++){
            var.push_back({idList.top().getRef(), PROD[advancement.top().prodNum][GR_FIRST_RHS]});
            idList.pop();
        }
    }
}
