/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamsNode.h
************************************************************/

#ifndef C_PARAMS_NODE_H
#define C_PARAMS_NODE_H

#pragma once
#include <list>
#include "cStmtNode.h"
#include "cParamNode.h"
using std::list;

/************************************************************************
* cParamsNode(cVarRef* lhs, cExprNode* rhs);
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* void Add(cParamNode* newNode);
*		Adds a new param to the list.
************************************************************************/
class cParamsNode : public cStmtNode
{
public:
	cParamsNode();
	virtual string toString();
	void Add(cParamNode* newNode);

private:
	list<cParamNode*> mParams;
};
#endif