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
* cStructDecl(cSymbolTable* symbolTable, cDeclsNode* decls, cSymbol* symbol);
*		C'tor (with params)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cStructDecl : public cDeclNode
{
public:
	cStructDecl(cSymbolTable* symbolTable, cDeclsNode* decls, cSymbol* symbol);
	string toString();

protected:
	cSymbolTable* mSymbolTable;
	cDeclsNode* mDecls;
	cSymbol* mSymbol;
};
#endif