%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu
// Edited by: Dakota Kanner dakota.kanner@oit.edu

#include "tokens.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


whitespace		[' '' '\t\n]
junk			[@#$:]
ident			[a-zA-Z_][a-zA-Z0-9_]*
oper			[+\-*/&=%]|"&&"|"=="|"\|\|"
floating		[0-9]*\.?[0-9]+
integer 		[0-9]+
punct			[\(\)\{\}\[\]\;\,\.]
comment			\/\/.*
char			.

%%

"if"            RETURN(IF);
"then"          RETURN(THEN);
"else"          RETURN(ELSE);
"for"           RETURN(FOR);
"while"         RETURN(WHILE);
"print"         RETURN(PRINT);
"scan"          RETURN(SCAN);
"int"           RETURN(INT);
"float"         RETURN(FLOAT);
"char"         	RETURN(CHAR);
"struct"        RETURN(STRUCT);
"return"        RETURN(RETURN_TOK);

{comment}		{};
{whitespace}	{};
{ident}			RETURN(IDENTIFIER);
{integer}		RETURN(INT_VAL);
{floating}		RETURN(FLOAT_VAL);
{oper}			RETURN(OPERATOR);
{punct}			RETURN(yytext[0]);
{char}			RETURN(JUNK_TOKEN);

{junk}			RETURN (JUNK_TOKEN);

%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
