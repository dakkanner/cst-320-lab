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
whitespace		[' '\t\n\r]+
punct			[()\[\];,.]
comment			"//".*$
junk			.

%%

"if"            RETURN(IF);
"else"          RETURN(ELSE);
"while"         RETURN(WHILE);
"print"         RETURN(PRINT);
"scan"          RETURN(SCAN);
"struct"        RETURN(STRUCT);
"return"		RETURN(RETURN);
"array"			RETURN(ARRAY);
{comment}		//Nothing
{oper}			RETURN(yytext[0]);
{punct}			RETURN(yytext[0]);
{integer}		{
					yylval.int_val = atoi(yytext);
					RETURN(INT_VAL);
				}
{floating}		{
					yylval.float_val = atof(yytext);
					RETURN(FLOAT_VAL);
				}
{ident}         {  
					yylval.symbol = symbolTableRoot->LookUp(yytext);
					if(yylval.symbol != NULL)
					{
						if(yylval.symbol->GetIsType())
							RETURN(TYPE_ID);
					}
					else
					{
						yylval.symbol = symbolTableRoot->Insert(yytext);
					}
					//return yytext[0];
                    return (IDENTIFIER);
                }
"{"             {
                    return yytext[0];
                }
"}"             {
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