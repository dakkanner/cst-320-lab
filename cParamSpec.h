/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamSpec.h
************************************************************/

#ifndef C_PARAM_SPEC_H
#define C_PARAM_SPEC_H

#pragma once
#include <string>
#include "cVarNode.h"
using std::string;

/************************************************************************
* cParamSpec();
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* void Add(cVarNode* newNode);
*		Adds a new param to the list.
************************************************************************/
class cParamSpec
{
public:
	cParamSpec(cVarNode* node);
	string toString();

protected:
	cVarNode* mParams;
};
#endif