/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarPart.cpp
************************************************************/

#include "cVarPart.h"

/************************************************************************
* cVarPart();
*		C'tor (with params)
************************************************************************/
cVarPart::cVarPart(cSymbol* id, cArrayVal* arr)
	:mID(id), mArr(arr)
{ }

/************************************************************************
* virtual string toString();
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
*		Function to get the type of the node
************************************************************************/
string cVarPart::GetType()
{
	return mID->GetType();
}

/************************************************************************
* virtual string GetBaseType();
*		Function to get the base type of the node's parent
************************************************************************/
string cVarPart::GetBaseType()
{
	if(mArr != NULL)
		return mID->GetBaseType();
	
	return GetType();
}

/************************************************************************
* cSymbol* GetId();
*		Returns the identifying symbol for the varpart
************************************************************************/
cSymbol* cVarPart::GetId()
{
	return mID;
}

/************************************************************************
* void SetId(cSymbol* id);
*		Sets the identifying symbol for the varpart
************************************************************************/
void cVarPart::SetId(cSymbol* id)
{
	mID = id;
}

/************************************************************************
* cDeclNode* GetTypeRef();
*		Returns the decl_node for the symbol
************************************************************************/
cDeclNode* cVarPart::GetTypeRef()
{
	return mID->GetRef();
}

/************************************************************************
* string GetSymbol();
*		Returns the type of the identifying symbol
************************************************************************/
string cVarPart::GetSymbol()
{
	return mID->GetSymbol();
}
