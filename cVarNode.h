/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarNode.h
************************************************************/

#ifndef C_VAR_NODE_H
#define C_VAR_NODE_H

#pragma once

#include "cSymbol.h"
#include "cDeclNode.h"

/************************************************************************
* cVarNode(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec);
*		C'tor (with params)
*
* string toString();
*		Converts the data to a string.
*
* cSymbol* GetSymbol()
*		Returns the ID
************************************************************************/
class cVarNode : public cDeclNode
{
public:
	cVarNode(cSymbol* typeID, cSymbol* id);
	virtual string toString();
	cSymbol* GetSymbol();

private:
	cSymbol* mTypeID;
	cSymbol* mID;
};
#endif