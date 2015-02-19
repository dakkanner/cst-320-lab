/***********************************************************
* Author:					Dakota Kanner
* Filename:					SymanticError.h
************************************************************/
#include <string>
using std::string;

extern int yynerrs;

void semantic_error(string msg);