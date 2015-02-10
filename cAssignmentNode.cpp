/***********************************************************
* Author:				Dakota Kanner
* Filename:				cAssignmentNode.cpp
************************************************************/

#include "cAssignmentNode.h"

/************************************************************************
* cAssignmentNode(cVarRef* lhs, cExprNode* rhs);
*		C'tor (default)
************************************************************************/
cAssignmentNode::cAssignmentNode(cVarRef* lhs, cExprNode* rhs)
	:mLHS(lhs), mRHS(rhs)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cAssignmentNode::toString()
{
	return "(ASSIGN: " + mLHS->toString() + " = " + mRHS->toString() + ')';
}
