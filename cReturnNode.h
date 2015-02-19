/***********************************************************
* Author:				Dakota Kanner
* Filename:				cReturnNode.h
************************************************************/

#ifndef C_RETURN_NODE_H
#define C_RETURN_NODE_H

#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

/************************************************************************
* cReturnNode(cExprNode* expr);
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cReturnNode : public cStmtNode
{
public:
	cReturnNode(cExprNode* expr = NULL);
	virtual string toString();

private:
	cExprNode* mExpr;
};
#endif