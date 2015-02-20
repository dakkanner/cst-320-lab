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
*		C'tor (with param)
*
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
class cParamSpec
{
public:
	cParamSpec(cVarNode* node = NULL);
	virtual string toString();

private:
	cVarNode* mParams;
};
#endif