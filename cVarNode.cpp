/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarNode.cpp
************************************************************/

#include "cVarNode.h"

/************************************************************************
* cVarNode(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec);
*		C'tor (with params)
************************************************************************/
cVarNode::cVarNode(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec)
	:mTypeID(typeID), mID(id), mArrSpec(arrSpec)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cVarNode::toString()
{
	string retValue("VAR: ");
	
	retValue += mTypeID->toString() + ' ' + mID->toString();
	
	if(mArrSpec != NULL)
	{
		retValue += ' ' + mArrSpec->toString();
	}
	
	return retValue;
}