%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu
// Edited by: Dakota Kanner dakota.kanner@oit.edu

#include "cSymbolTable.h"
#include "lex.h"
#include "langparse.h"

#define RETURN(a) return Return(a);
static int Return(int val);
%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

    /* definitions go here. period is an example. */
oper			[+\-*/%<!=]
ident			[a-zA-Z_][a-zA-Z0-9_]*
integer 		[\-]?[0-9]+
floating		[-]?[0-9]*\.?[0-9]+
whitespace		[' '\t\n]+
punct			[()\[\];,.]
comment			"//".*$
junk			.

%%

"if"            RETURN(IF);
"then"          RETURN(THEN);
"else"          RETURN(ELSE);
"for"           RETURN(FOR);
"while"         RETURN(WHILE);
"print"         RETURN(PRINT);
"scan"          RETURN(SCAN);
"int"           RETURN(INT_VAL);
"float"         RETURN(FLOAT);
"struct"        RETURN(STRUCT);
{comment}		//Nothing
{integer}		RETURN(INT_VAL);
{floating}		RETURN(FLOAT_VAL);
{oper}			RETURN(yytext[0]);
{punct}			RETURN(yytext[0]);
{ident}         {  
                    yylval.symbol = symbolTableRoot->Insert(yytext);
                    return (IDENTIFIER);
                }
"{"             {
                    symbolTableRoot->IncreaseScope();  
                    return yytext[0];
                }
"}"             {
                    symbolTableRoot->DecreaseScope();
                    return yytext[0];
                }
{whitespace}	//Nothing
{junk}			RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}