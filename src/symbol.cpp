#include "symbol.h"

symbol::symbol() {
	lexeme = "";
	category = dataType = 0;
	next = NULL;
}

void symbol::setDataType(int dt) {
	dataType = dt;
}

std::string symbol::getLex() {
	return lexeme;
}

int symbol::getCategory() {
	return category;
}

int symbol::getDataType() {
	return dataType;
}

void symbol::setLex(std::string lex) {
	lexeme = lex;
	//check for string literal
	if (lex[0] == '\'') {
		category = SYMCAT_STRING_LIT;
		dataType = DTYPE_STRING;
	}
	//check for int literal
	else if (lex[0] >= '0' && lex[0] <= '9') {
		category = SYMCAT_INT_LIT;
		dataType = DTYPE_INT;
		//check for real literal
		for (int i = 0; i < (int)lex.length(); i++)
			if (lex[i] == '.') {
				category = SYMCAT_REAL_LIT;
				dataType = DTYPE_REAL;
			}
	}
	//who knows?
	else {
		category = SYMCAT_IDENT;
		dataType = DTYPE_UNKNOWN;
	}
}
