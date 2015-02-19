/***********************************************************
* Author:				Dakota Kanner
* Filename:				cArrayVal.cpp
************************************************************/

#include "cArrayVal.h"

/************************************************************************
* cArrayVal();
*		C'tor (default)
************************************************************************/
cArrayVal::cArrayVal()
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cArrayVal::toString()
{
	string retValue("(ARRAYVAL:");
	
	for(cExprNode* i : mVals)
	{
		retValue += ' ' + i->toString();
	}
	
	retValue += ")";
	
	return retValue;
}

/************************************************************************
* void Add(cExprNode* newNode);
*		Adds a new ExprNode to the list.
************************************************************************/
void cArrayVal::Add(cExprNode* newNode)
{
	mVals.push_back(newNode);
}