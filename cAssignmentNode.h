/***********************************************************
* Author:				Dakota Kanner
* Filename:				cAssignmentNode.h
************************************************************/

#ifndef C_ASSIGNMENT_NODE_H
#define C_ASSIGNMENT_NODE_H

#pragma once
#include "cStmtNode.h"
#include "cVarRef.h"
#include "cExprNode.h"

/************************************************************************
* cAssignmentNode(cVarRef* lhs, cExprNode* rhs);
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cAssignmentNode : public cStmtNode
{
public:
	cAssignmentNode(cVarRef* lhs, cExprNode* rhs);
	string toString();

protected:
	cVarRef* mLHS;
	cExprNode* mRHS;
};
#endif