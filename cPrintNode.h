/***********************************************************
* Author:				Dakota Kanner
* Filename:				cPrintNode.h
************************************************************/

#ifndef C_PRINT_NODE_H
#define C_PRINT_NODE_H

#pragma once

#include "cStmtNode.h"
#include "cExprNode.h"

/************************************************************************
* cPrintNode();
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* void Add(cPrintNode* newNode);
*		Adds a new Stmt to the list.
************************************************************************/
class cPrintNode : public cStmtNode
{
public:
	cPrintNode(cExprNode* expr = NULL);
	virtual string toString();

private:
	cExprNode* mExpr;
};
#endif