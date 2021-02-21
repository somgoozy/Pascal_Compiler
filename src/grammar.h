#include <iostream>
#include <iomanip>
#include "token.h"
#pragma once

//macros to make the table easier to read
#define E				TOK_N_EPSILON
#define N_PROGRAM		TOK_N_PROGRAM
#define PROGRAM			TOK_PROGRAM
#define IDENT			TOK_IDENT
#define SEMIC			TOK_SEMIC
#define DEC     	    TOK_N_DECLARATIONS
#define CMPD_STMT		TOK_N_CMPD_STMT
#define DOT				TOK_DOT
#define DEFAULT			TOK_DEFAULT
#define ID_LIST			TOK_N_ID_LIST
#define ID_LIST_END		TOK_N_IDLIST_END
#define COMMA			TOK_COMMA
#define VAR				TOK_VAR
#define COLON			TOK_COLON
#define TYPE			TOK_N_TYPE
#define INTEGER			TOK_INTEGER
#define REAL			TOK_REAL
#define STRING			TOK_STRING
#define BEGIN			TOK_BEGIN
#define OPT_STMTS		TOK_N_OPT_STMTS
#define END				TOK_END
#define STMT_LIST		TOK_N_STMT_LIST
#define STMT			TOK_N_STMT
#define STMT_LIST_END	TOK_N_STMT_LIST_END
#define ASSIGN			TOK_ASSIGN
#define EXPR			TOK_N_EXPR
#define IF				TOK_IF
#define COND			TOK_N_COND
#define THEN			TOK_THEN
#define ELSE			TOK_ELSE
#define WHILE			TOK_WHILE
#define DO				TOK_DO
#define RELOP			TOK_N_RELOP
#define VAL				TOK_N_VAL
#define EXPR_END		TOK_N_EXPR_END
#define ARITH			TOK_N_ARITH_OP
#define PLUS			TOK_PLUS
#define MINUS			TOK_MINUS
#define STAR			TOK_STAR
#define SLASH			TOK_SLASH
#define LTHAN			TOK_LTHAN
#define LTHAN_EQ		TOK_LTHAN_EQ
#define GTHAN			TOK_GTHAN
#define GTHAN_EQ		TOK_GTHAN_EQ
#define NOT_EQ			TOK_NOT_EQ
#define EQUAL			TOK_EQUAL
#define INT_LIT			TOK_INT_LIT
#define REAL_LIT		TOK_REAL_LIT
#define STRING_LIT		TOK_STRING_LIT
#define LPAREN			TOK_LPAREN
#define RPAREN			TOK_RPAREN
#define TERM            TOK_TERM

const int GR_NUMPRODS = 41;			// total number of productions in grammar
const int GR_TABLE_WIDTH = 11;		// total number of columns in table
const int GR_LHS = 0;				// index of LHS Non-Terminal
const int GR_FIRST_RHS = 1;			// index of first Term/NT of RHS
const int GR_LAST_RHS = 6;          // index of last Term/NT of RHS
const int GR_FIRST_SELSET = 7;      // index of first member of Select Set
const int GR_LAST_SELSET = 10;      // index of last member of Select Set

const TOKENID PROD[GR_NUMPRODS][GR_TABLE_WIDTH] = {
	{N_PROGRAM,     PROGRAM,    IDENT,          SEMIC,      DEC,    CMPD_STMT,  DOT,    DEFAULT,    E,      E,      E},
	{ID_LIST,       IDENT,      ID_LIST_END,    E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{ID_LIST_END,   COMMA,      ID_LIST,        E,          E,      E,          E,      COMMA,      E,      E,      E},
	{ID_LIST_END,   E,          E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{DEC,           VAR,        ID_LIST,        COLON,      TYPE,   SEMIC,      DEC,    VAR,        E,      E,      E},
	{DEC,           E,          E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{TYPE,          INTEGER,    E,              E,          E,      E,          E,      INTEGER,    E,      E,      E},
	{TYPE,          REAL,       E,              E,          E,      E,          E,      REAL,       E,      E,      E},
	{TYPE,          STRING,     E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{CMPD_STMT,     BEGIN,      OPT_STMTS,      END,        E,      E,          E,      DEFAULT,    E,      E,      E},
	{OPT_STMTS,     E,          E,              E,          E,      E,          E,      END,        E,      E,      E},
	{OPT_STMTS,     STMT_LIST,  E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{STMT_LIST,     STMT,       STMT_LIST_END,  E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{STMT_LIST_END, SEMIC,      STMT_LIST,      E,          E,      E,          E,      SEMIC,      E,      E,      E},
	{STMT_LIST_END, E,          E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{STMT,          IDENT,      ASSIGN,         EXPR,       E,      E,          E,      IDENT,      E,      E,      E},
	{STMT,          IF,         COND,           THEN,       STMT,   ELSE,       STMT,   IF,         E,      E,      E},
	{STMT,          WHILE,      COND,           DO,         STMT,   E,          E,      WHILE,      E,      E,      E},
	{STMT,          CMPD_STMT,  E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{COND,          EXPR,       RELOP,          EXPR,       E,      E,          E,      DEFAULT,    E,      E,      E},
	{EXPR,          VAL,        EXPR_END,       E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{EXPR_END,      ARITH,      VAL,            EXPR_END,   E,      E,          E,      PLUS,       MINUS,  STAR,   SLASH},
	{EXPR_END,      TERM,       E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{ARITH,         PLUS,       E,              E,          E,      E,          E,      PLUS,       E,      E,      E},
	{ARITH,         MINUS,      E,              E,          E,      E,          E,      MINUS,      E,      E,      E},
	{ARITH,         STAR,       E,              E,          E,      E,          E,      STAR,       E,      E,      E},
	{ARITH,         SLASH,      E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{RELOP,         LTHAN,      E,              E,          E,      E,          E,      LTHAN,      E,      E,      E},
	{RELOP,         LTHAN_EQ,   E,              E,          E,      E,          E,      LTHAN_EQ,   E,      E,      E},
	{RELOP,         GTHAN,      E,              E,          E,      E,          E,      GTHAN,      E,      E,      E},
	{RELOP,         GTHAN_EQ,   E,              E,          E,      E,          E,      GTHAN_EQ,   E,      E,      E},
	{RELOP,         NOT_EQ,     E,              E,          E,      E,          E,      NOT_EQ,     E,      E,      E},
	{RELOP,         EQUAL,      E,              E,          E,      E,          E,      DEFAULT,    E,      E,      E},
	{VAL,           IDENT,      E,              E,          E,      E,          E,      IDENT,      E,      E,      E},
	{VAL,           INT_LIT,    E,              E,          E,      E,          E,      INT_LIT,    E,      E,      E},
	{VAL,           REAL_LIT,   E,              E,          E,      E,          E,      REAL_LIT,   E,      E,      E},
	{VAL,           STRING_LIT, E,              E,          E,      E,          E,      STRING_LIT, E,      E,      E},
	{VAL,           LPAREN,     EXPR,           RPAREN,     E,      E,          E,      LPAREN,     E,      E,      E},
	{VAL,           PLUS,       INT_LIT,        E,          E,      E,          E,      PLUS,       E,      E,      E},
	{VAL,           MINUS,      INT_LIT,        E,          E,      E,          E,      DEFAULT,    E,      E,      E},
};

//undefine macros
#undef E
#undef N_PROGRAM
#undef PROGRAM
#undef IDENT
#undef SEMIC
#undef DEC
#undef CMPD_STMT
#undef DOT
#undef DEFAULT
#undef ID_LIST
#undef ID_LIST_END
#undef COMMA
#undef VAR
#undef COLON
#undef TYPE
#undef INTEGER
#undef REAL
#undef STRING
#undef BEGIN
#undef OPT_STMTS
#undef END
#undef STMT_LIST
#undef STMT
#undef STMT_LIST_END
#undef ASSIGN
#undef EXPR
#undef IF
#undef COND
#undef THEN
#undef ELSE
#undef WHILE
#undef DO
#undef RELOP
#undef VAL
#undef EXPR_END
#undef ARITH
#undef PLUS
#undef MINUS
#undef STAR
#undef SLASH
#undef LTHAN
#undef LTHAN_EQ
#undef GTHAN
#undef GTHAN_EQ
#undef NOT_EQ
#undef EQUAL
#undef INT_LIT
#undef REAL_LIT
#undef STRING_LIT
#undef LPAREN
#undef RPAREN
#undef TERM
