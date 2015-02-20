/***********************************************************
* Author:				Dakota Kanner
* Filename:				cStmtsNode.h
************************************************************/

#ifndef C_STMTS_NODE_H
#define C_STMTS_NODE_H

#pragma once

#include <list>
using std::list;

#include "cStmtNode.h"

/************************************************************************
* cStmtsNode();
*		C'tor (default)
*
* virtual string toString();
*		Converts the data to a string.
*
* void Add(cStmtsNode* newNode);
*		Adds a new Stmt to the list.
************************************************************************/
class cStmtsNode : public cAstNode
{
public:
	cStmtsNode();
	virtual string toString();
	void Add(cStmtNode* newNode = NULL);

private:
	list<cStmtNode*> mStmts;
};
#endif