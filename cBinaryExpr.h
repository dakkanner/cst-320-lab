/***********************************************************
* Author:				Dakota Kanner
* Filename:				cBinaryExpr.h
************************************************************/

#ifndef C_BINARY_EXPR_H
#define C_BINARY_EXPR_H

#pragma once

#include "cExprNode.h"

/************************************************************************
* cBinaryExpr(cExprNode* lhs, char oper, cExprNode* rhs);
*		C'tor (with params)
*
* virtual string toString();
*		Converts the data to a string.
*
* virtual string GetType();
*		Returns the highest level 
*
* virtual string GetBaseType();
*		Converts the data to a string.
************************************************************************/
class cBinaryExpr : public cExprNode
{
public:
	cBinaryExpr(cExprNode* lhs, char oper, cExprNode* rhs);
	virtual string toString();
	virtual string GetType();
	virtual string GetBaseType();

private:
	cExprNode* mLHS;
	cExprNode* mRHS;
	char mOper;
};
#endif