#include "interpreter.h"

interpreter::interpreter(){
    token myToken;
    myToken.setId(TOK_N_PROGRAM);
    advancement.push({myToken, 0, GR_FIRST_RHS - 1});
}

void interpreter::push(token top, int prod){
    static token exp;
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
    else if (PROD[advancement.top().prodNum][0] == TOK_N_DECLARATIONS
          || PROD[advancement.top().prodNum][0] == TOK_N_TYPE
          || PROD[advancement.top().prodNum][0] == TOK_N_ID_LIST){
        declare(top);
    }
    //expression
    else if (PROD[advancement.top().prodNum][0] == TOK_N_EXPR
          || PROD[advancement.top().prodNum][0] == TOK_N_EXPR_END
          || PROD[advancement.top().prodNum][0] == TOK_N_ARITH_OP
          || PROD[advancement.top().prodNum][0] == TOK_N_RELOP
          || PROD[advancement.top().prodNum][0] == TOK_N_VAL){
        exp = expression(top);
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
    //push token to stack
    if (PROD[advancement.top().prodNum][0] == TOK_N_ID_LIST){
        if (PROD[advancement.top().prodNum][advancement.top().depth] == TOK_IDENT){
            idList.push(top);
        }
    }
    //find out what type tokens are and pop them off the stack and store in the vector
    else if (PROD[advancement.top().prodNum][0] == TOK_N_TYPE){
        while (!idList.empty()){
            var.push_back({idList.top().getRef(), PROD[advancement.top().prodNum][GR_FIRST_RHS]});
            idList.pop();
        }
    }
}

token interpreter::expression(token top){
    static vector <token> rhs;

    //if at the end of the expression
    if (PROD[advancement.top().prodNum][advancement.top().depth] == TOK_TERM
        && PROD[advancement.top().prodNum][GR_LHS] == TOK_N_EXPR_END){
        if (rhs.size() < 1){
            simplify(rhs);
        }
        else;
//throw error
    }
    //if its a terminal then push it to the vector
    else if (!top.isNonTerminal()){
        rhs.emplace_back(top);
    }
    return rhs[0];
}

void interpreter::simplify (vector<token>& myVector){
    vector<token> subVector;
    vector<token> vectorEnd;
    int           parenth;

    if (myVector.size() > 1){
        //do parenths
        for (size_t i = 0; i < myVector.size(); i++){
            //find innermost right parenth
            if (myVector[i].getId() == TOK_LPAREN){
                parenth = i;
            }
            //find its partner
            else if (myVector[i].getId() == TOK_RPAREN){
                //remove parenth
                myVector.erase(myVector.begin() + i);
                myVector.erase(myVector.begin() + parenth);
                i--;
                i--;
                //move elements into subvector
                copy(myVector.begin() + parenth, myVector.begin() + i, subVector.begin());
                myVector.erase(myVector.begin() + parenth, myVector.begin() + i);
                //simplify the expression
                simplify(subVector);
                //reunite the vectors
                copy(subVector.begin(), subVector.end(), myVector.begin() + parenth);
                //empty subvector for future use
                subVector.erase(subVector.begin(), subVector.end());
                //start loop from beginning
                i = 0;
            }
        }
    //do math

    }
}












