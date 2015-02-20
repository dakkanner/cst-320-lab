/***********************************************************
* Author:				Dakota Kanner
* Filename:				cWhileNode.h
************************************************************/

#ifndef C_WHILE_NODE_H
#define C_WHILE_NODE_H

#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

/************************************************************************
* cWhileNode(cExprNode* expr, cStmtNode* stmt);
*		C'tor (with params)
*
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
class cWhileNode : public cStmtNode
{
public:
	cWhileNode(cExprNode* expr = NULL, cStmtNode* stmt = NULL);
	virtual string toString();

private:
	cExprNode* mExpr;
	cStmtNode* mStmt;
};
#endif