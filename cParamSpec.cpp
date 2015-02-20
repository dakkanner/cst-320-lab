/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamSpec.cpp
************************************************************/

#include "cParamSpec.h"

/************************************************************************
* cParamSpec();
*		C'tor (with param)
************************************************************************/
cParamSpec::cParamSpec(cVarNode* node)
	:mParams(node)
{ }

/************************************************************************
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cParamSpec::toString()
{
	if(mParams != NULL)
		return mParams->toString();
	
	return "";
}