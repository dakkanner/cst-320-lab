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
	string retValue("(FUNC CALL: ");
	
	if(mID != NULL)
		retValue += mID->toString();
	
	if(mParams != NULL)
		retValue += mParams->toString();
	
	return retValue + ")\n";
}

/************************************************************************
* virtual string GetType();
*		Virtual function to get the base type of the node
************************************************************************/
string cFuncCall::GetType()
{
	return mID->GetType();
}

/************************************************************************
* virtual string GetBaseType();
*		Virtual function to get the base type of the node
************************************************************************/
string cFuncCall::GetBaseType()
{
	return GetType();
}
