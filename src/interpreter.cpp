#include "interpreter.h"

interpreter::interpreter() {
	token myToken;
	myToken.setId(TOK_N_PROGRAM);
	advancement.push({ myToken, 0, GR_FIRST_RHS - 1 });
}

void interpreter::push(token top, int prod) {
	static value exp;
	//move everything forward by 1
	increment();
	//if we are done
//needs to be done more smoothly
	if (advancement.empty()) {
		return;
	}
	//push the nonterminal
	else if (top.isNonTerminal()) {
		advancement.push({ top, prod, GR_FIRST_RHS - 1 });
	}
	//declarations
	else if (PROD[advancement.top().prodNum][0] == TOK_N_DECLARATIONS
		|| PROD[advancement.top().prodNum][0] == TOK_N_TYPE
		|| PROD[advancement.top().prodNum][0] == TOK_N_ID_LIST) {
		declare(top);
	}
	//expression
	else if (PROD[advancement.top().prodNum][0] == TOK_N_EXPR
		|| PROD[advancement.top().prodNum][0] == TOK_N_EXPR_END
		|| PROD[advancement.top().prodNum][0] == TOK_N_ARITH_OP
		|| PROD[advancement.top().prodNum][0] == TOK_N_RELOP
		|| PROD[advancement.top().prodNum][0] == TOK_N_VAL) {
		exp = expression(top);
	}
}

void interpreter::increment() {
	//if not empty progress
	if (!advancement.empty()) {
		advancement.top().depth++;
		//if we hit the end we need to pop and make progress
		while (PROD[advancement.top().prodNum][advancement.top().depth] == TOK_N_EPSILON
			|| advancement.top().depth > GR_LAST_RHS) {
			advancement.pop();
			if (advancement.empty())
				break;
			advancement.top().depth++;
		}
	}
}

void interpreter::declare(token top) {
	static stack <token>    idList;
	value                   myVar;
	//push token to stack
	if (PROD[advancement.top().prodNum][0] == TOK_N_ID_LIST) {
		if (PROD[advancement.top().prodNum][advancement.top().depth] == TOK_IDENT) {
			idList.push(top);
		}
	}
	//find out what type tokens are and pop them off the stack and store in the vector
	else if (PROD[advancement.top().prodNum][0] == TOK_N_TYPE) {
		while (!idList.empty()) {
			myVar.tok.setRef(idList.top().getRef());
			myVar.tok.setId(PROD[advancement.top().prodNum][GR_FIRST_RHS]);
			var.push_back(myVar);
			idList.pop();
		}
	}
}

value interpreter::expression(token top) {
	static vector <value> rhs;
	value myVal;

	//if at the end of the expression
	if (PROD[advancement.top().prodNum][advancement.top().depth] == TOK_TERM
		&& PROD[advancement.top().prodNum][GR_LHS] == TOK_N_EXPR_END) {
		if (rhs.size() < 1) {
			simplify(rhs);
		}
		else;
		//throw error
	}
	//if its a terminal then push it to the vector
	else if (!top.isNonTerminal()) {
		if (top.getRef() != NULL) {
			myVal.tokVal = getVal(top);
		}
		myVal.tok.setId(top.getId());
		myVal.tok.setRef(top.getRef());
		rhs.emplace_back(myVal);
	}
	return rhs[0];
}

void interpreter::simplify(vector<value>& myVector) {
	if (myVector.size() > 1) {
		//do parenths
		doParenth(myVector);
		//do math
		for (size_t i = 0; i < myVector.size(); i++) {
			if (myVector[i].tok.getId() == TOK_STAR) {
				if
			}
			//divide
			//and
		}
		for (size_t i = 0; i < myVector.size(); i++) {
			//add
			//subtract
			//or
		}
		for (size_t i = 0; i < myVector.size(); i++) {
			//compare
		}
	}
}

void interpreter::doParenth(vector<value>& myVector) {
	vector<value> subVector;
	int           parenth;

	for (size_t i = 0; i < myVector.size(); i++) {
		//find innermost right parenth
		if (myVector[i].tok.getId() == TOK_LPAREN) {
			parenth = i;
		}
		//find its partner
		else if (myVector[i].tok.getId() == TOK_RPAREN) {
			//remove parenth
			myVector.erase(myVector.begin() + i);
			myVector.erase(myVector.begin() + parenth);
			i -= 2;
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
}

VAL interpreter::getVal(token myToken) {
	if (myToken.getRef()->getCategory() == SYMCAT_IDENT) {
		for (size_t i = 0; i < var.size(); i++) {
			if (var[i].tok.getRef() == myToken.getRef())
				return var[i].tokVal;
		}
		//throw error
		return -1;
	}
	else if (myToken.getRef()->getCategory() == SYMCAT_INT_LIT) {
		return stoi(myToken.getRef()->getLex());
	}
	else if (myToken.getRef()->getCategory() == SYMCAT_REAL_LIT) {
		return stof(myToken.getRef()->getLex());
	}
	else if (myToken.getRef()->getCategory() == SYMCAT_STRING_LIT) {
		return myToken.getRef()->getLex();
	}
	else {
		//throw error
	}
	return -1;
}
