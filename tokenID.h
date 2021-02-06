#pragma once

enum class TOKENID {
	TOK_NONE, TOK_ERROR, TOK_EOS, TOK_INT_LIT, TOK_REAL_LIT, TOK_STRING_LIT, TOK_IDENT,
	TOK_SEMIC, TOK_PLUS, TOK_MINUS, TOK_STAR, TOK_SLASH, TOK_LBRAC, TOK_RBRAC, TOK_LPAREN, TOK_RPAREN,
	TOK_COMMA, TOK_COLON, TOK_HAT, TOK_DOT, TOK_LTHAN, TOK_LTHAN_EQ, TOK_GTHAN, TOK_GTHAN_EQ,
	TOK_NOT_EQ, TOK_EQUAL, TOK_ASSIGN, TOK_DOTDOT,
	TOK_AND, TOK_ARRAY, TOK_BEGIN, TOK_BOOLEAN, TOK_CASE, TOK_CHAR, TOK_CONST, TOK_DIV, TOK_DO,
	TOK_DOWNTO, TOK_ELSE, TOK_END, TOK_EOF, TOK_FALSE, TOK_FILE, TOK_FOR, TOK_FUNCTION, TOK_GOTO,
	TOK_IF, TOK_IN, TOK_INTEGER, TOK_LABEL, TOK_MAXINT, TOK_MOD, TOK_NIL, TOK_NOT, TOK_OF, TOK_OR,
	TOK_OUTPUT, TOK_PACK, TOK_PACKED, TOK_PROCEDURE, TOK_PROGRAM, TOK_READ, TOK_READLN, TOK_REAL,
	TOK_RECORD, TOK_REPEAT, TOK_SET, TOK_STRING, TOK_THEN, TOK_TO, TOK_TRUE, TOK_TYPE, TOK_UNTIL, TOK_VAR,
	TOK_WHILE, TOK_WITH, TOK_WRITE, TOK_WRITELN,
	TOK_N_EPSILON, TOK_N_PROGRAM, TOK_N_DECLARATIONS, TOK_N_CMPD_STMT, TOK_N_ID_LIST, TOK_N_IDLIST_END,
	TOK_N_TYPE, TOK_N_OPT_STMTS, TOK_N_STMT_LIST, TOK_N_STMT, TOK_N_STMT_LIST_END,
	TOK_N_EXPR, TOK_N_COND, TOK_N_RELOP, TOK_N_VAL, TOK_N_EXPR_END,
	TOK_N_ARITH_OP, TOK_N_SIGN, TOK_DEFAULT
};
