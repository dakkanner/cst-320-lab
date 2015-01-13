#include <iostream>
#include "lex.h"
#include "parse.h"

int yylval = 0;
int token = -1;
int oldToken = -1;

//*******************************************
void Error(std::string expecting)
{
    std::cout << "Found " << yytext << " when expecting a " << expecting;
    std::cout << " in line " << yylineno << std::endl;
}
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
bool FindPROG()
{
    //Program
    if (!FindSTMTS()) return false;
    
    int token = GetToken();
    if (token != END)
    {
        UnGetToken();
		Error("end");
        return false;
    }

	std::cout << "Found a program";
    return true;
}
//*******************************************
bool FindSTMTS()
{
    //Statements
    int token = GetToken();
    if (token == 0)
    {
        return true;
    }
	else
	{
		UnGetToken();
		if (!FindSTMT()) return false;
		if (!FindSTMTS()) return false;
	}

    return true;
}
//*******************************************
bool FindSTMT()
{
    //Statement
    if (!FindEXPR()) return false;
    
    int token = GetToken();
    if (token != ';')
    {
        UnGetToken();
		Error(";");
        return false;
    }
	
	std::cout << "Found a statement";
    return true;
}
//*******************************************
bool FindEXPR()
{
    //Expression
	if (FindTERM() == true) 
	{
		
	}
	else{	
		int token = GetToken();
		if (token != '(')
		{
			UnGetToken();
			Error("(");
			return false;
		}
		
		if (!FindEXPR()) return false;
		
		int token = GetToken();
		if (token != ')')
		{
			UnGetToken();
			Error(")");
			return false;
		}
		
		if (!FindEXPR_P()) return false;
	}
    return true;
}
//*******************************************
bool FindEXPR_P()
{
    //Expression_P
	
    int token = GetToken();
    if (token == 0)
    {
        return true;
    }
	else
	{ 
		UnGetToken();
		if (!FindPLUSOP()) return false;

		//int token = GetToken();
		if (token != '(')
		{
			UnGetToken();
			Error("(");
			return false;
		}
		
		if (!FindEXPR()) return false;
		
		int token = GetToken();
		if (token != ')')
		{
			UnGetToken();
			Error(")");
			return false;
		}
		
		if (!FindEXPR_P()) return false;
	}
	
    return true;
}
//*******************************************
bool FindPLUSOP()
{
    //Plus Operator
	
    int token = GetToken();
    if (token != '+' && token != '-')
    {
        UnGetToken();
		Error("+ or -");
        return false;
    }

    return true;
}
//*******************************************
bool FindTERM()
{
    //Term
	
    int token = GetToken();
    if (token == INT_VAL || token == FLOAT_VAL)
    {
        return true;
    }
	else if (token == "[")
	{	
		if (!FindEXPR()) return false;
		
		int token = GetToken();
		if (token != ']')
		{
			UnGetToken();
			Error("]");
			return false;
		}
		
		if (!FindTERM_P()) return false;
	}
	else 
	{
		UnGetToken();
		Error("[");
		return false;
	}
    return true;
}
//*******************************************
bool FindTERM_P()
{
    //Error("Term_P");
	
    int token = GetToken();
    if (token == 0)
    {
        return true;
    }
	else
	{
		UnGetToken();
		
		if (!FindTIMESOP()) return false;
		
		int token = GetToken();
		if (token != '[')
		{
			UnGetToken();
			Error("[");
			return false;
		}

		if (!FindEXPR()) return false;
		
		int token = GetToken();
		if (token != ']')
		{
			UnGetToken();
			Error("]");
			return false;
		}

		if (!FindTERM_P()) return false;
	}

    return true;
}
//*******************************************
bool FindTIMESOP()
{
    //Times Operator
	
    int token = GetToken();
    if (token != '*' && token != '/')
    {
        UnGetToken();
		Error("* or /");
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

