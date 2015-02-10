/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncPrefix.cpp
************************************************************/

#include "cFuncPrefix.h"

/************************************************************************
* cFuncPrefix(cSymbol* typeId, cSymbol* id);
*		C'tor (default)
************************************************************************/
cFuncPrefix::cFuncPrefix(cSymbol* typeId, cSymbol* id)
	:mTypeID(typeId), mID(id)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cFuncPrefix::toString()
{
	return mID->toString();
}