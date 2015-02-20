/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarRef.h
************************************************************/

#ifndef C_VAR_REF_H
#define C_VAR_REF_H

#pragma once

#include "cVarPart.h"
#include "cExprNode.h"
#include "cSymbolTable.h"
#include "cStructDecl.h"

extern cSymbolTable* symbolTableRoot;

/************************************************************************
* cVarRef();
*		C'tor (decault)
*
* virtual string toString();
*		Converts the data to a string.
*
* virtual string GetBaseType();
*		Function to get the base type of the node's parent
*
* virtual string GetType();
*		Function to get the type of the node
*
* cDeclNode* GetTypeRef();
*		Returns the decl_node for the symbol
*
* void Add(cVarPart* part);
*		Adds a new VarPart to the list.
*
* string VRef();
*		Returns the string of each varpart in the format va1.var2.var3...
*
* bool IsSymbolInParent(cVarPart* part);
*		Returns true if the variable is found in the struct
*
* string GetError();
*		Returns the error string
*
* string GetSymbol();
*		Returns the cSymbol
************************************************************************/
class cVarRef : public cExprNode
{
public:
	cVarRef();
	virtual string toString();
	
	virtual string GetType();
	virtual string GetBaseType();
	cDeclNode* GetTypeRef();
	
	void Add(cVarPart* part);
	string VRef();
	bool IsSymbolInParent(cVarPart* part);
	
	string GetError();
	string GetSymbol();

private:
	list<cVarPart*> mVarParts;
	string mError; 
};
#endif