#include <iostream>
#include "lex.h"
#include "parse.h"
#include "tokens.h"

int yylval = 0;
int token = -1;
int oldToken = -1;

//*******************************************
int GetToken()
{
    if (token > 0)
    {
        oldToken = token;
        token = -1;
    } else {
        oldToken = yylex();
    }
    return oldToken;
}
//*******************************************
void UnGetToken()
{
    token = oldToken;
}
//*******************************************
void Error(std::string expecting)
{
    std::cout << "Found " << yytext << " when expecting a '" << expecting;
    std::cout << "' in line " << yylineno << std::endl;
	
    int dumpToken = GetToken();
    while (dumpToken != ';' &&  dumpToken != END)
    {
        dumpToken = GetToken();
    }
}
//*******************************************
bool FindPROG()
{
    // Program
	// PROG	-> STMTS end
	
	// Check if it's at the end already
	int lToken = GetToken();
	if (lToken != END)
	{
		UnGetToken();
		// Find statements; error if there are none
		if (!FindSTMTS()) 
		{
			Error("Program");
			return false;
		}
		
		// Check for the "end"; error if not
		lToken = GetToken();
		if (lToken != END)
		{
			Error("End");
			return false;
		}
		else
		{
			return true;
		}
	}
	
    return true;
}
//*******************************************
bool FindSTMTS()
{
    // Statements
	// STMTS	-> STMT STMTS
	// STMTS	-> NULL
	
	// Try to peel away first remaining statement
    if (!FindSTMT())
    {
        int lToken = GetToken();
        if (lToken == END)
        {
			// Went to the end. Put it back.
            UnGetToken();
            return true;
        }
        UnGetToken();
		// Recursively call itself for more statement finding
        if (!FindSTMTS()) 
            return true;
    }	// Recursively call itself for more statement finding
    else if (!FindSTMTS()) 
        return false;

    return true;
}
//*******************************************
bool FindSTMT()
{
    // Statement
	// STMT	-> EXPR ;
	
	// Find the expression
    if ( !FindEXPR() ) 
		return false;
    
    int lToken = GetToken();
	// Find the semicolon; error if not found
    if (lToken != ';')
    {
		Error(";");
        return false;
    }
	std::cout << "Found a statement" << std::endl;
    return true;
}
//*******************************************
bool FindEXPR()
{
    // Expression
	// EXPR	-> (EXPR) EXPR’
	// 		-> Term
	int lToken = GetToken();
	
	if (lToken != '(')
	{
		UnGetToken();
		// If it's not a (, it must be a term.
		return FindTERM();
	}
	else
	{
		// Find the expression part of (EXPR)
		if (!FindEXPR()) 
			return false;
	
		lToken = GetToken();
		// If there is a (, there must be a ) or an EXPR'
		if (lToken != ')')
		{
			Error(")");
			return false;
		}
		else
		{
			return FindEXPR_P();
		}
		
		if (!FindEXPR_P()) return false;
	}
	
    return true;
}
//*******************************************
bool FindEXPR_P()
{
    // Expression prime
	// EXPR’	-> PLUSOP (EXPR) EXPR’
	// 			-> NULL
	
	// First thing found must be a +/- or nothing
	if (FindPLUSOP()) 
	{
		// Error if any of the next steps fail
		int lToken = GetToken();
		if (lToken != '(')
		{
			Error("(");
			return false;
		}
		if (!FindEXPR()) 
			return false;
		
		lToken = GetToken();
		if (lToken != ')')
		{
			Error(")");
			return false;
		}
		else 
			return FindEXPR_P();
	}
	
    return true;
}
//*******************************************
bool FindPLUSOP()
{
    //Plus Operator
	
	//If it's not a +/-, fail. Do not error.
    int lToken = GetToken();
    if (yytext[0] != '+' && yytext[0] != '-')
    {
        UnGetToken();
        return false;
    }

    return true;
}
//*******************************************
bool FindTERM()
{		
	// Term 
	// TERM	-> [EXPR] TERM’
	// 		-> number
	
	// Check if it's 
    int lToken = GetToken();
    if (lToken == INT_VAL || lToken == FLOAT_VAL)
    {
        return true;
    }
	else if (lToken == '[')
	{	
		if (!FindEXPR()) 
			return false;
		
		lToken = GetToken();
		if (lToken != ']')
		{
			UnGetToken();
			Error("]");
			return false;
		}
		
		return FindTERM_P();
	}
	else 
	{
		UnGetToken();
		return false;
	}
    return true;
}
//*******************************************
bool FindTERM_P()
{		
	// Term prime
	// TERM’	-> TIMESOP [EXPR] TERM’
	// 			-> NULL
	
	if (FindTIMESOP())
	{
		int lToken = GetToken();
		if (lToken != '[')
		{
			Error("[");
			return false;
		}

		if (!FindEXPR()) 
		{
			return false;
		}
		
		lToken = GetToken();
		if (lToken == ']')
		{
			return FindTERM_P();
		}
		else
		{
			return false;
		}
	}

    return true;
}
//*******************************************
bool FindTIMESOP()
{	
    //Times Operator
	// Term prime
	// TERM’	-> *
	// 			-> /
	
	//If it's not a * or /, fail. Do not error.
    int lToken = GetToken();
    if (yytext[0] != '*' && yytext[0] != '/')
    {
        UnGetToken();
        return false;
    }

    return true;
}
/*******************************************
bool FindExample()
{
    if (!FindPART1()) return false;
    
    int token = GetToken();
    if (token != '+')
    {
        UnGetToken();
        return false;
    }

    if (!FindPART2()) return false;

    return true;
}
*/

