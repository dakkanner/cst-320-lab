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
* string toString();
*		Converts the data to a string.
*
* void Add(cVarPart* part);
*		Adds a new VarPart to the list.
************************************************************************/
class cVarRef : public cExprNode
{
public:
	cVarRef();
	virtual string toString();
	virtual string GetType();
	virtual string GetBaseType();
	void Add(cVarPart* part);
	cDeclNode* GetTypeRef();
	string VRef();
	bool IsSymbolInParent(cVarPart* part);
	string GetError();
	string GetSymbol();

private:
	list<cVarPart*> mVarParts;
	string mError; 
};
#endif