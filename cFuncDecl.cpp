/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncDecl.cpp
************************************************************/

#include "cFuncDecl.h"

/************************************************************************
* cFuncDecl(cSymbol* header, cParamsSpec* params; = NULL);
*		C'tor (withy params)
************************************************************************/
cFuncDecl::cFuncDecl(cSymbol* header, cParamsSpec* params)
	:mHeader(header), mParams(params), mDecls(NULL), mStmts(NULL)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cFuncDecl::toString()
{
	string retValue("(FUNC: ");
	retValue += mHeader->toString();
	
	if(mParams != nullptr)
		retValue += " " + mParams->toString();
	else
		retValue += "()";

	if(mDecls != NULL)
	    retValue += '\n' + mDecls->toString();
	
	if(mStmts != NULL)
	    retValue += '\n' + mStmts->toString();
	
	retValue += "\n)";
	
    return retValue;
}

/************************************************************************
* void SetDecls(cDeclsNode* decls = NULL);
*		Sets mDecls
* cDeclsNode* GetDecls();
*		Returns mDecls
* void SetStmts(cStmtsNode* stmts = NULL);
*		Sets mStmts
* cStmtsNode* GetStmts();
*		Returns mStmts
************************************************************************/
void cFuncDecl::SetDecls(cDeclsNode* decls)
{
	mDecls = decls;
}
cDeclsNode* cFuncDecl::GetDecls()
{
	return mDecls;
}
void cFuncDecl::SetStmts(cStmtsNode* stmts)
{
	mStmts = stmts;
}
cStmtsNode* cFuncDecl::GetStmts()
{
	return mStmts;
}
