#include "parser.h"
string parser::compile(string fn) {
	//get started
	if (!startup(fn))
		return "Error opening file.\n";
	//while not errored or at the end
	while (top.getId() != TOK_EOS && top.getId() != TOK_ERROR) {
		//pop the top and grab the data
		top.setId(tokStack.top().getId());
		top.setRef(tokStack.top().getRef());
		tokStack.pop();
		//push top to interpreter
		myInterpreter.push(top, selectProd());
		//if NT choose what to push on the stack
		if (top.isNonTerminal()) {
			pushProdRHS(selectProd());
		}
		//if the next token matches the top then get get the next token
		else if (top.getId() == nextToken.getId()) {
			nextToken = scan.getNextToken();
		}
		else if (top.getId() == TOK_TERM) {
			//do nothing
			;
		}
		//error
		else {
			parseError = "Parser expected " + top.getPrintString() + " but got " + nextToken.getPrintString() + "\n";
			return parseError;
		}
	}
	//we did it
	return "Compilation successful!";
}

int parser::selectProd() {
	//loop through the grammar.h table
	for (int i = 0; i < GR_NUMPRODS; i++) {
		//look for the LHS to match the top
		if (PROD[i][GR_LHS] == top.getId()) {
			//loop through the select set of specified row
			for (int j = GR_FIRST_SELSET; j <= GR_LAST_SELSET; j++) {
				//does any of the select set match the next token
				if (PROD[i][j] == nextToken.getId() || PROD[i][j] == TOK_DEFAULT) {
					return i;
				}
			}
		}
	}
	return -1;
}

void parser::pushProdRHS(int prodNum) {
	token myToken;
	//if error push error
	if (prodNum == -1) {
		myToken.setId(TOK_ERROR);
		tokStack.push(myToken);
	}
	//otherwise push all productions except for E onto the stack
	for (int i = GR_LAST_RHS; i >= GR_FIRST_RHS; i--) {
		if (PROD[prodNum][i] != TOK_N_EPSILON) {
			myToken.setId(PROD[prodNum][i]);
			tokStack.push(myToken);
		}
	}
}

bool parser::startup(string filename) {
	//open the file
	if (scan.open(filename) != 1)
		return false;
	//push program and end to stack
	token myToken;
	myToken.setId(TOK_EOS);
	tokStack.push(myToken);
	myToken.setId(TOK_N_PROGRAM);
	tokStack.push(myToken);
	//set progress stack
	progress.push({ 0, GR_FIRST_RHS });
	//get first token from source
	nextToken = scan.getNextToken();
	return true;
}
