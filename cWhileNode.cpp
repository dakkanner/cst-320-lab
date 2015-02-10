/***********************************************************
* Author:				Dakota Kanner
* Filename:				cWhileNode.cpp
************************************************************/

#include "cWhileNode.h"

/************************************************************************
* cWhileNode(cExprNode* expr);
*		C'tor (default)
************************************************************************/
cWhileNode::cWhileNode(cExprNode* expr, cStmtNode* stmt)
	:mExpr(expr), mStmt(stmt)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cWhileNode::toString()
{
    return "(WHILE: " + mExpr->toString() + '\n' + mStmt->toString() + "\n)";
}