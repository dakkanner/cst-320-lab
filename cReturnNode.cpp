/***********************************************************
* Author:				Dakota Kanner
* Filename:				cReturnNode.cpp
************************************************************/

#include "cReturnNode.h"

/************************************************************************
* cReturnNode(cExprNode* expr);
*		C'tor (default)
************************************************************************/
cReturnNode::cReturnNode(cExprNode* expr)
	:mExpr(expr)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cReturnNode::toString()
{
    return "RETURN: " + mExpr->toString();
}