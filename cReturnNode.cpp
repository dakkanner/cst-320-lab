/***********************************************************
* Author:				Dakota Kanner
* Filename:				cReturnNode.cpp
************************************************************/

#include "cReturnNode.h"

/************************************************************************
* cReturnNode(cExprNode* expr);
*		C'tor (with param)
************************************************************************/
cReturnNode::cReturnNode(cExprNode* expr)
	:mExpr(expr)
{ }

/************************************************************************
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cReturnNode::toString()
{
	if(mExpr != NULL)
		return "RETURN: " + mExpr->toString();
	return "";
}