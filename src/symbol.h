#include <string>
#pragma once
using namespace std;

// symbol category constants
const int SYMCAT_IDENT = -1;
const int SYMCAT_INT_LIT = -2;
const int SYMCAT_REAL_LIT = -3;
const int SYMCAT_STRING_LIT = -4;

// symbol data type constants
const int DTYPE_UNKNOWN = 0;
const int DTYPE_INT = 1;
const int DTYPE_REAL = 2;
const int DTYPE_STRING = 3;

class symbol {
public:
	friend class symbolTable;
	symbol();
	void   setLex(string lex);
	void   setDataType(int dt);
	string getLex();
	int    getCategory();
	int    getDataType();
private:
	string		lexeme;				// spelling of an ident or literal
	int			category;			// one of SYMCAT_
	int			dataType;			// one of DTYPE_
	symbol*		next;				// linked list next pointer
};
