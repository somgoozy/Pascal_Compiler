#include <fstream>
#include <string>
#include "FSA.h"
#include "token.h"
#pragma once

class scanner {
public:
	int	            open(std::string source);
	std::string     getError();
	bool            isError();
	token           getNextToken();
	void            close();
private:
	std::string     error = "";
	bool            is_error = false;
	int             lineNo = 1;
	std::ifstream   f;

	CHAR_CAT	    categorize(char c);
	void		    setError(std::string method, char c, std::string msg);
	int			    getTrans(FSA_STATE currState, char c);
	std::string		getFSAerror(CHAR_CAT cc, FSA_STATE state);
	std::string		getNextLexeme();
	TOKENID		    resWordToTokenId(std::string lex);
	symbolTable	    symbolTbl;
	std::string		upcase(std::string s);
	TOKENID		    symCatToTokId(int cat);
};
