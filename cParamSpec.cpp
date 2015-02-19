/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamSpec.cpp
************************************************************/

#include "cParamSpec.h"

/************************************************************************
* cParamSpec();
*		C'tor (default)
************************************************************************/
cParamSpec::cParamSpec(cVarNode* node)
	:mParams(node)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cParamSpec::toString()
{
	if(mParams != NULL)
		return mParams->toString();
	
	return "";
}