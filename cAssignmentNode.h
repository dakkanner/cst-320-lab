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
*		C'tor (with params)
*
* virtual string toString();
*		Converts the data to a string.
*
* bool CanAssign();
*		Checks that the data can be assigned to the left hand side
************************************************************************/
class cAssignmentNode : public cStmtNode
{
public:
	cAssignmentNode(cVarRef* lhs, cExprNode* rhs);
	virtual string toString();
	bool CanAssign();

private:
	cVarRef* mLHS;
	cExprNode* mRHS;
};
#endif