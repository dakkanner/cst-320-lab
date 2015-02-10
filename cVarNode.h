/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarNode.h
************************************************************/

#ifndef C_VAR_NODE_H
#define C_VAR_NODE_H

#pragma once

#include "cSymbol.h"
#include "cDeclNode.h"
#include "cArraySpec.h"

/************************************************************************
* cVarNode(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec);
*		C'tor (with params)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cVarNode : public cDeclNode
{
public:
	cVarNode(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec);
	string toString();

protected:
	cSymbol* mTypeID;
	cSymbol* mID;
	cArraySpec* mArrSpec;
};
#endif