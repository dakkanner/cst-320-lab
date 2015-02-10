/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamsNode.cpp
************************************************************/

#include "cParamsNode.h"

/************************************************************************
* cParamsNode();
*		C'tor (default)
************************************************************************/
cParamsNode::cParamsNode()
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cParamsNode::toString()
{
	string retValue("(PARAM:");
	
	for(cParamNode* i : mParams)
	{
		retValue += i->toString() + ' ';
	}
	
	retValue += ")\n";
	
	return retValue;
}


/************************************************************************
* void Add(cParamNode* newNode);
*		Adds a new param to the list.
************************************************************************/
void cParamsNode::Add(cParamNode* newNode)
{
	mParams.push_back(newNode);
}