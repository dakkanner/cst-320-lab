/***********************************************************
* Author:				Dakota Kanner
* Filename:				cParamNode.cpp
************************************************************/

#include "cParamNode.h"

/************************************************************************
* cParamNode(cExprNode* expr);
*		C'tor (with param)
************************************************************************/
cParamNode::cParamNode(cExprNode* expr)
	:mExpr(expr)
{ }

/************************************************************************
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cParamNode::toString()
{
	return mExpr->toString();
}