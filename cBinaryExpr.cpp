/***********************************************************
* Author:				Dakota Kanner
* Filename:				cBinaryExpr.cpp
************************************************************/

#include "cBinaryExpr.h"

/************************************************************************
* cBinaryExpr(cExprNode* lhs, char oper, cExprNode* rhs);
*		C'tor (with params)
************************************************************************/
cBinaryExpr::cBinaryExpr(cExprNode* lhs, char oper, cExprNode* rhs)
	:mLHS(lhs), mRHS(rhs), mOper(oper)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cBinaryExpr::toString()
{
	return "(EXPR: " + mLHS->toString() + ' ' + mOper + ' ' + mRHS->toString() + ')';
}

/************************************************************************
* virtual string GetType();
*		Returns the highest level 
************************************************************************/
string cBinaryExpr::GetType()
{
	if(mLHS->GetType() == "float" || mRHS->GetType() == "float")
        return "float";
	//ints/chars already handled normally
    return mLHS->GetType();
}

/************************************************************************
* virtual string GetBaseType();
*		Converts the data to a string.
************************************************************************/
string cBinaryExpr::GetBaseType()
{
	return GetType();
}
