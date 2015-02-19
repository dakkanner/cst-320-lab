/***********************************************************
* Author:				Dakota Kanner
* Filename:				cArrayDecl.cpp
************************************************************/

#include "cArrayDecl.h"

/************************************************************************
* cArrayDecl(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec);
*		C'tor (with params)
************************************************************************/
cArrayDecl::cArrayDecl(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec)
	:mTypeID(typeID), mID(id), mArrSpec(arrSpec)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cArrayDecl::toString()
{
	string retValue("ARRAY: ");
	
	retValue += mTypeID->toString() + ' ' + mID->toString();
	
	if(mArrSpec != NULL)
	{
		retValue += ' ' + mArrSpec->toString();
	}
	
	return retValue;
}