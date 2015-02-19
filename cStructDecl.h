/***********************************************************
* Author:				Dakota Kanner
* Filename:				cStructDecl.h
************************************************************/

#ifndef C_STRUCT_DECL_H
#define C_STRUCT_DECL_H

#pragma once

#include <map>
using std::map;
#include "cDeclsNode.h"
#include "cSymbolTable.h"
#include "cSymbol.h"

/************************************************************************
* cStructDecl(map<string,cSymbol*>* symbolTable, cDeclsNode* decls, cSymbol* symbol);
*		C'tor (with params)
*
* string toString();
*		Converts the data to a string.
*
* void PrintSymbolTable()
*		Prints all of the symbol table
*
* cSymbol* Find(string symbol)
*		Finds a symbol in the symbol table
************************************************************************/
class cStructDecl : public cDeclNode
{
public:
	cStructDecl(map<string,cSymbol*>* symbolTable, cDeclsNode* decls, cSymbol* symbol);
	virtual string toString();
	cSymbol* Find(string name);

private:
	map<string,cSymbol*>* mSymbolTable;
	cDeclsNode* mDecls;
	cSymbol* mSymbol;
};
#endif