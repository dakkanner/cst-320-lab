/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamsSpec.h
************************************************************/

#ifndef C_PARAMS_SPEC_H
#define C_PARAMS_SPEC_H

#pragma once
#include "cStmtNode.h"
#include "cParamSpec.h"

/************************************************************************
* cParamsSpec();
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* void Add(cParamNode* newNode);
*		Adds a new param to the list.
************************************************************************/
class cParamsSpec : public cStmtNode
{
public:
	cParamsSpec();
	string toString();
	void Add(cParamSpec* newNode);

protected:
	list<cParamSpec*> mParams;
};
#endif