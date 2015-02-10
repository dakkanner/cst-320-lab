/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncCall.cpp
************************************************************/

#include "cFuncCall.h"

/************************************************************************
* cFuncCall(cSymbol* id, cParamsNode* params);
*		C'tor (default)
************************************************************************/
cFuncCall::cFuncCall(cSymbol* id, cParamsNode* params)
	:mID(id), mParams(params)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cFuncCall::toString()
{
	return "(FUNC CALL: " + mID->toString() + mParams->toString() + ")\n";
}