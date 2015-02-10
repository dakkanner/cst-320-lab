/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarPart.cpp
************************************************************/

#include "cVarPart.h"

/************************************************************************
* cVarPart();
*		C'tor (default)
************************************************************************/
cVarPart::cVarPart(cSymbol* val, cArrayVal* arr)
	:mVal(val), mArr(arr)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cVarPart::toString()
{
	string retValue(mVal->toString());
	
	if(mArr != NULL)
	{
		retValue += '[' + mArr->toString() + ']';
	}
	
	return retValue;
}