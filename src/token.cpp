#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "token.h"

symbol* token::getRef() {
	return ref;
}

TOKENID token::getId() {
	return id;
}

void token::setId(TOKENID tid) {
	id = tid;
}

void token::setRef(symbol* tref) {
	ref = tref;
}

std::string token::getPrintString() {
	std::string myString = "";
	myString += "TOK: ID=" + std::to_string((int)id) + " " + TOKENID_STR[(int)id];
	if (ref)
        myString += " LEX=" + (ref->getLex());
	else if ((int)id <= LAST_TOK_RESWD_NDX)
        myString += " RESWD";
	else
        myString += " NON-TERM";
	return myString;
}

bool token::isNonTerminal() {
	//check for nonterminals
	if (id == TOK_N_PROGRAM ||
		id == TOK_N_DECLARATIONS ||
		id == TOK_N_CMPD_STMT ||
		id == TOK_N_ID_LIST ||
		id == TOK_N_IDLIST_END ||
		id == TOK_N_TYPE ||
		id == TOK_N_OPT_STMTS ||
		id == TOK_N_STMT_LIST ||
		id == TOK_N_STMT ||
		id == TOK_N_STMT_LIST_END ||
		id == TOK_N_EXPR ||
		id == TOK_N_COND ||
		id == TOK_N_RELOP ||
		id == TOK_N_VAL ||
		id == TOK_N_EXPR_END ||
		id == TOK_N_ARITH_OP ||
		id == TOK_DEFAULT)
		return true;
	else return false;
}

int token::getLineNo() {
    return lineNo;
}

void token::setLineNo(int num) {
    lineNo = num;
}
