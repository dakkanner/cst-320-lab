/***********************************************************
* Author:				Dakota Kanner
* Filename:				cIfNode.h
************************************************************/

#ifndef C_IF_NODE_H
#define C_IF_NODE_H

#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

/************************************************************************
* cIfNode(cExprNode* expr, cStmtNode* stmt1, cStmtNode* stmt2 = NULL);
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cIfNode : public cStmtNode
{
public:
	cIfNode(cExprNode* expr, cStmtNode* stmt1, cStmtNode* stmt2 = NULL);
	string toString();

protected:
	cExprNode* mExpr;
	cStmtNode* mStmt1;
	cStmtNode* mStmt2;
};
#endif