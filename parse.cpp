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
    //Program
	
	int lToken = GetToken();
	if (lToken != END)
	{
		UnGetToken();
		if (!FindSTMTS()) 
		{
			Error("Program");
			return false;
		}
			
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
    if (!FindSTMT())
    {
        int t = GetToken();
        if (t == END)
        {
            UnGetToken();
            return true;
        }
        UnGetToken();
        if (!FindSTMTS()) 
            return true;
    }     
    else if (!FindSTMTS()) 
        return false;

    return true;
}
//*******************************************
bool FindSTMT()
{
    //Statement
	
    if ( !FindEXPR() ) 
		return false;
    
    int lToken = GetToken();
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
    //Expression		
	int lToken = GetToken();
	
	if (lToken != '(')
	{
		UnGetToken();
		return FindTERM();
	}
	else
	{
		if (!FindEXPR()) 
			return false;
	
		lToken = GetToken();
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
    //Expression_P
	
	if (FindPLUSOP()) 
	{
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
    //Term
	
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

