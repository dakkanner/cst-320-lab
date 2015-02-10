/***********************************************************
* Author:				Dakota Kanner
* Filename:				cStructDecl.cpp
************************************************************/

#include "cStructDecl.h"

/************************************************************************
* cStructDecl(cSymbolTable* symbolTable, cDeclsNode* decls, cSymbol* symbol);
*		C'tor (with params)
************************************************************************/
cStructDecl::cStructDecl(cSymbolTable* symbolTable, cDeclsNode* decls, cSymbol* symbol)
	:mSymbolTable(symbolTable), mDecls(decls), mSymbol(symbol)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cStructDecl::toString()
{
	return string("STRUCT: " + mDecls->toString() + ' ' + mSymbol->toString());
}