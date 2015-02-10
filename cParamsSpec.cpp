/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamsSpec.cpp
************************************************************/

#include "cParamsSpec.h"

/************************************************************************
* cParamsSpec();
*		C'tor (default)
************************************************************************/
cParamsSpec::cParamsSpec()
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cParamsSpec::toString()
{
	string retValue("(PARAMS:");
	
	for(cParamSpec* i : mParams)
	{
		retValue += ' ' + i->toString();
	}
	
	retValue += ")\n";
	
	return retValue;
}


/************************************************************************
* void Add(cParamSpec* newNode);
*		Adds a new param to the list.
************************************************************************/
void cParamsSpec::Add(cParamSpec* newNode)
{
	mParams.push_back(newNode);
}