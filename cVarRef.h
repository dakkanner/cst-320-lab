/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarRef.h
************************************************************/

#ifndef C_VAR_REF_H
#define C_VAR_REF_H

#pragma once

#include "cVarPart.h"
#include "cExprNode.h"

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
	string toString();
	void Add(cVarPart* part);

protected:
	list<cVarPart*> mVarParts;
};
#endif