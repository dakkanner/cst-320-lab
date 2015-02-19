/***********************************************************
* Author:				Dakota Kanner
* Filename:				cStructDecl.cpp
************************************************************/

#include "cStructDecl.h"

/************************************************************************
* cStructDecl(cSymbolTable* symbolTable, cDeclsNode* decls, cSymbol* symbol);
*		C'tor (with params)
************************************************************************/
cStructDecl::cStructDecl(map<string,cSymbol*>* symbolTable, cDeclsNode* decls, cSymbol* symbol)
	:mSymbolTable(symbolTable), mDecls(decls), mSymbol(symbol)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cStructDecl::toString()
{
	string retValue("STRUCT: ");
	
	if(mDecls != NULL)
		retValue += mDecls->toString();
	
	if(mSymbol != NULL)
		retValue += ' ' + mSymbol->toString();
	
	return retValue;
}

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
cSymbol* cStructDecl::Find(string name)
{
	cSymbol* retVal = NULL;

	// Can't find nothing
	if ( name.empty() || mSymbolTable == NULL)
	{
		return NULL;
	}
	
	// Find it in the top-most map
	map<string,cSymbol*>::iterator symb = mSymbolTable->find(name);
	if (symb != mSymbolTable->end())
	{
		retVal = symb->second;
	}
	
	return retVal;
}