/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarPart.h
************************************************************/

#ifndef C_VAR_PART_H
#define C_VAR_PART_H

#pragma once
#include <iostream>
using std::cout;
#include "cSymbol.h"
#include "cExprNode.h"
#include "cArrayVal.h"

/************************************************************************
* cVarPart();
*		C'tor (with params)
*
* virtual string toString();
*		Converts the data to a string.
*
* virtual string GetType();
*		Function to get the type of the node
*
* virtual string GetBaseType();
*		Function to get the base type of the node's parent
*
* cDeclNode* GetTypeRef();
*		Returns the decl_node for the symbol
*
* cSymbol* GetId();
*		Returns the identifying symbol for the varpart
*
* void SetId(cSymbol* id);
*		Sets the identifying symbol for the varpart
*
* string GetSymbol();
*		Returns the type of the identifying symbol
************************************************************************/
class cVarPart : public cExprNode
{
public:
	cVarPart(cSymbol* id, cArrayVal* arr);
	virtual string toString();
	virtual string GetType();
	virtual string GetBaseType();
	cDeclNode* GetTypeRef();
	cSymbol* GetId();
	void SetId(cSymbol* id);
	string GetSymbol();
	
private:
	cSymbol* mID;
	cArrayVal* mArr;
};
#endif