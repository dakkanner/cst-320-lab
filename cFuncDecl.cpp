/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncDecl.cpp
************************************************************/

#include "cFuncDecl.h"

/************************************************************************
* cFuncDecl(cFuncHeader* header, cDeclsNode* decls = NULL, cStmtsNode* stmts = NULL);
*		C'tor (withy params)
************************************************************************/
cFuncDecl::cFuncDecl(cFuncHeader* header, cDeclsNode* decls, cStmtsNode* stmts)
	:mHeader(header), mDecls(decls), mStmts(stmts)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cFuncDecl::toString()
{
	string retValue("(FUNC: ");
	retValue += mHeader->toString();
	
	if(mDecls != NULL)
	    retValue += mDecls->toString();
	if(mStmts != NULL)
	    retValue += mStmts->toString();
	
	retValue += "\n)";
	
    return retValue;
}