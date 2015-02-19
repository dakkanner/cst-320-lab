/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarPart.cpp
************************************************************/

#include "cVarPart.h"

/************************************************************************
* cVarPart();
*		C'tor (default)
************************************************************************/
cVarPart::cVarPart(cSymbol* id, cArrayVal* arr)
	:mID(id), mArr(arr)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cVarPart::toString()
{
	string retValue(mID->toString());
	
	if(mArr != NULL)
	{
		retValue += '[' + mArr->toString() + ']';
	}
	
	return retValue;
}

/************************************************************************
* virtual string GetType();
*		Virtual function to get the base type of the node
************************************************************************/
string cVarPart::GetType()
{
	return mID->GetType();
}

/************************************************************************
* virtual string GetBaseType();
*		Virtual function to get the base type of the node
************************************************************************/
string cVarPart::GetBaseType()
{
	if(mArr != NULL)
		return mID->GetBaseType();
	
	return GetType();
}

/************************************************************************
* cSymbol* cVarPart::GetId()
*		Virtual function to get the base type of the node
************************************************************************/
cSymbol* cVarPart::GetId()
{
	return mID;
}

/************************************************************************
* void SetId(cSymbol* id);
*		Virtual function to get the base type of the node
************************************************************************/
void cVarPart::SetId(cSymbol* id)
{
	mID = id;
}

/************************************************************************
* cDeclNode* GetTypeRef();
*		Virtual function to get the base type of the node
************************************************************************/
cDeclNode* cVarPart::GetTypeRef()
{
	return mID->GetRef();
}

/************************************************************************
* string GetSymbol();
*		Virtual function to get the base type of the node
************************************************************************/
string cVarPart::GetSymbol()
{
	return mID->GetSymbol();
}
