/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamNode.h
************************************************************/

#ifndef C_PARAM_NODE_H
#define C_PARAM_NODE_H

#pragma once
#include "cExprNode.h"

/************************************************************************
* cParamNode(cExprNode* expr);
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cParamNode
{
public:
	cParamNode(cExprNode* expr);
	virtual string toString();

private:
	cExprNode* mExpr;
};
#endif