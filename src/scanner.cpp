#include <iostream>
#include "scanner.h"

std::string scanner::getError() {
	return error;
}

bool scanner::isError() {
	return is_error;
}

int	scanner::open(std::string source) {
	f.open(source);
	if (f.fail()) {
		setError("open()", ' ', "Unable to open input file.");
		return 0;
	}
	return 1;
}

void scanner::close() {
	f.close();
}

CHAR_CAT scanner::categorize(char c) {
	if (isalpha(c)) return CHAR_CAT::ALPHA;
	if (isdigit(c)) return CHAR_CAT::DIGIT;
	switch (c) {
	case -1:   return CHAR_CAT::EOFL;
	case '\n': lineNo++; return CHAR_CAT::EOL;
	case '\r': return CHAR_CAT::EOL;
	case ' ':
	case '\t': return CHAR_CAT::WHITESP;
	case '\'': return CHAR_CAT::QUOTE;
	case '{':  return CHAR_CAT::LBRACE;
	case '}':  return CHAR_CAT::RBRACE;
	case '_':  return CHAR_CAT::UNDERSC;
	case '.':  return CHAR_CAT::DOTC;
	case '>':  return CHAR_CAT::GTHANC;
	case '<':  return CHAR_CAT::LTHANC;
	case ':':  return CHAR_CAT::COLON;
	case '=':  return CHAR_CAT::EQUAL;
	}
	const std::string psi = "+-/*[],;^()";
	if (psi.find(c) != std::string::npos) return CHAR_CAT::SYMBOL;
	if (c >= ' ' && c < '~') return CHAR_CAT::OTHER;

	// unidentified
	setError("categorize()", c, "Invalid character found in source.");
	return CHAR_CAT::UNKNOWN;
}

std::string scanner::getFSAerror(CHAR_CAT cc, FSA_STATE state) {
	switch (state) {
	case FSA_STATE::START:
		if (cc == CHAR_CAT::RBRACE) return "Beginning of comment expected.";
		return "Invalid beginning of lexeme.";
	case FSA_STATE::CMNT:  return "End of comment expected.";
	case FSA_STATE::SLIT:
		if (cc == CHAR_CAT::EOL)  return "End of line found in string literal.";
		if (cc == CHAR_CAT::EOFL) return "End of file found in string literal.";
		return "STATE=SLIT No transition from state found.";

	case FSA_STATE::SLITQ: return "Single quote expected.";
	case FSA_STATE::DECPT: return "Digit expected.";
	default:    return "Unknown error for STATE=" + FSA_STATE_STR[static_cast<int>(state)] + ".";
	}
}

int scanner::getTrans(FSA_STATE currState, char c) {
	CHAR_CAT cc = categorize(c);
	if (is_error) return -1;
	char la = f.peek();
	CHAR_CAT lacc = categorize(f.peek());

	for (int i = 0; i < NUM_FSA_TRANS; i++) {
		if ((trans[i].from == currState) &&
			(trans[i].ccat == cc || trans[i].ccat == CHAR_CAT::ANY) &&
			(trans[i].la == lacc || trans[i].la == CHAR_CAT::ANY))
			return i;
	}
	setError("getTrans()", c, getFSAerror(cc, currState));
	return -1;
}

std::string scanner::getNextLexeme() {
	FSA_STATE   state = FSA_STATE::START;
	char        c;
	int         transNo;
	std::string lex = "";

	while (state != FSA_STATE::HALT && !is_error) {
		c = f.get();
		transNo = getTrans(state, c);
		if (!is_error) {
			if (trans[transNo].to == FSA_STATE::ERR)
				setError("getNextLexeme()", c, getFSAerror(categorize(c), state));
			else {
				state = trans[transNo].to;
				if (trans[transNo].act == ACTION::KEEP)
					lex += c;
				else if (trans[transNo].act == ACTION::PUTB) {
					if (f.fail()) f.clear();
					f.putback(c);
				}
				// else discard c
			}
		}
	}

	if (is_error) return ""; else return lex;
}

TOKENID scanner::resWordToTokenId(std::string lex) {
	for (unsigned int i = FIRST_TOK_RESWD_NDX; i < NUM_TOKENIDS; i++)
		if (lex == TOKENID_STR[i]) return ((TOKENID)i);
	return TOKENID::TOK_NONE; // not found, lex is not a Pascal reserved word or symbol
}

std::string scanner::upcase(std::string s) {
	std::string x = s;
	for (unsigned int i = 0; i < s.length(); i++) x[i] = toupper(x[i]);
	return x;
}

TOKENID scanner::symCatToTokId(int cat) {
	switch (cat) {
	case SYMCAT_IDENT:      return TOKENID::TOK_IDENT;
	case SYMCAT_INT_LIT:    return TOKENID::TOK_INT_LIT;
	case SYMCAT_REAL_LIT:   return TOKENID::TOK_REAL_LIT;
	case SYMCAT_STRING_LIT: return TOKENID::TOK_STRING_LIT;
	default:                return TOKENID::TOK_NONE;
	}
}

token scanner::getNextToken() {
	token t;
	TOKENID tid = TOKENID::TOK_NONE;
	symbol* tref = NULL;
	std::string lex = getNextLexeme();

	if (is_error)
		tid = TOKENID::TOK_ERROR;
	else if (lex == "")
		tid = TOKENID::TOK_EOS;
	else {
		lex = upcase(lex);
		tid = resWordToTokenId(lex);
		if (tid == TOKENID::TOK_NONE) {
			tref = symbolTbl.insert(lex);
			tid = symCatToTokId(tref->getCategory());
		}
	}
	t.setId(tid);
	t.setRef(tref);
	return t;
}

void scanner::setError(std::string method, char c, std::string msg) {
	std::string sc = " ";
	sc[0] = c;
	error = "SCANERROR::" + method + "  Line=" + std::to_string(lineNo) + " Character=";
	int ascii = (int)c;
	if (ascii <= 32 || ascii >= 127)
		error += "UNPRINTABLE (";
	else
		error += "'" + sc + "' (";
	error += std::to_string(ascii) + ")\n" + msg;
	is_error = true;
}
