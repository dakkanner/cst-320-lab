/***********************************************************
* Author:				Dakota Kanner
* Filename:				cAssignmentNode.cpp
************************************************************/

#include "cAssignmentNode.h"

/************************************************************************
* cAssignmentNode(cVarRef* lhs, cExprNode* rhs);
*		C'tor (with params)
************************************************************************/
cAssignmentNode::cAssignmentNode(cVarRef* lhs, cExprNode* rhs)
	:mLHS(lhs), mRHS(rhs)
{ 
	//Check if right can be assigned to left
	mSemanticError = CanAssign();
}

/************************************************************************
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cAssignmentNode::toString()
{
	return "(ASSIGN: " + mLHS->toString() + " = " + mRHS->toString() + ')';
}

/************************************************************************
* bool CanAssign();
*		Checks that the data can be assigned to the left hand side
************************************************************************/
bool cAssignmentNode::CanAssign()
{
	bool retVal = true;
	
	//If they're not the same, we have to test.
	if(mLHS->GetType() != mRHS->GetType()
		&& mLHS->GetBaseType() != mRHS->GetBaseType())
	{
		//If the left (float, int) is larger than the right
		if(mLHS->GetBaseType().compare("float") == 0)
		{
			if(    mRHS->GetBaseType().compare("int") == 0 
				|| mRHS->GetBaseType().compare("char") == 0)
			{
				retVal = false;
			}
		}
		else if (mLHS->GetBaseType().compare("int") == 0)
		{
			if(mRHS->GetBaseType().compare("char") == 0)
			{
				retVal = false;
			}
		}
		//Char is handled implicitly 
	}
	else
		retVal = false;
	
	return retVal;
}