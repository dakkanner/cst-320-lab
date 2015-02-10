/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncHeader.cpp
************************************************************/

#include "cFuncHeader.h"

/************************************************************************
* cFuncHeader(cFuncPrefix* prefix, cParamsSpec* params = NULL);
*		C'tor (default)
************************************************************************/
cFuncHeader::cFuncHeader(cFuncPrefix* prefix, cParamsSpec* params)
	:mPrefix(prefix), mParams(params)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cFuncHeader::toString()
{
	string retValue = mPrefix->toString();
	
	if(mParams != NULL)
	    retValue += " " + mParams->toString();
	else
	    retValue += "()";

    return retValue;
}