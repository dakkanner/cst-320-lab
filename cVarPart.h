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
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* virtual string GetType();
*		Virtual function to get the type of the node
*
* virtual string GetBaseType();
*		Virtual function to get the base type of the node
************************************************************************/
class cVarPart : public cExprNode
{
public:
	cVarPart(cSymbol* id, cArrayVal* arr);
	virtual string toString();
	virtual string GetType();
	virtual string GetBaseType();
	cSymbol* GetId();
	void SetId(cSymbol* id);
	cDeclNode* GetTypeRef();
	string GetSymbol();
	
private:
	cSymbol* mID;
	cArrayVal* mArr;
};
#endif