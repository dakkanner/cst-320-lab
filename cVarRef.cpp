/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarRef.cpp
************************************************************/

#include "cVarRef.h"

/************************************************************************
* cVarRef();
*		C'tor (default)
************************************************************************/
cVarRef::cVarRef()
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cVarRef::toString()
{
	string retValue("");
	
	//For each VarPart
	for(cVarPart* i : mVarParts)
	{
		retValue += "(VarRef: " + i->toString();
		
		if(i != mVarParts.front())
            retValue += ')';
        else if(mVarParts.size() > 1)
            retValue += '\n';
	}
	retValue += ')';
	
	return retValue;
}

/************************************************************************
* void Add(cVarPart* part);
*		Adds a new VarPart to the list.
************************************************************************/
void cVarRef::Add(cVarPart* part)
{
	mVarParts.push_back(part);
}