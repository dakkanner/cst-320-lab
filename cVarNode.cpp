/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarNode.cpp
************************************************************/

#include "cVarNode.h"

/************************************************************************
* cVarNode(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec);
*		C'tor (with params)
************************************************************************/
cVarNode::cVarNode(cSymbol* typeID, cSymbol* id)
	:mTypeID(typeID), mID(id)
{ }

/************************************************************************
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cVarNode::toString()
{
	string retValue("VAR: ");
	
	if(mTypeID != NULL)
	{
		retValue += mTypeID->toString();
	}
	if(mID != NULL)
	{
		retValue += ' ' + mID->toString();
	}
	
	return retValue;
}

/************************************************************************
* cSymbol* GetSymbol()
*		Returns the ID cSymbol
************************************************************************/
cSymbol* cVarNode::GetSymbol()
{
	return mID;
}