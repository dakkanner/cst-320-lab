/***********************************************************
* Author:				Dakota Kanner
* Filename:				cIfNode.cpp
************************************************************/

#include "cIfNode.h"

/************************************************************************
* cIfNode(cExprNode* expr);
*		C'tor (default)
************************************************************************/
cIfNode::cIfNode(cExprNode* expr, cStmtNode* stmt1, cStmtNode* stmt2)
	:mExpr(expr), mStmt1(stmt1), mStmt2(stmt2)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cIfNode::toString()
{
	string retValue("(IF: " + mExpr->toString() + '\n' + mStmt1->toString() + '\n');
    
    if(mStmt2 != nullptr)
        retValue += "ELSE:\n" + mStmt2->toString() + '\n';
    
    retValue += ')';
    
    return retValue;
}