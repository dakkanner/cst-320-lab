/***********************************************************
* Author:				Dakota Kanner
* Filename:				cIntExpr.h
************************************************************/

#ifndef C_INT_EXPR_H
#define C_INT_EXPR_H

#pragma once

#include "cExprNode.h"

/************************************************************************
* cIntExpr(int val = -1);
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* virtual string GetType();
*		Virtual function to get the type of the node
*
* virtual string GetBaseType();
*		Virtual function to get the base type of the node
************************************************************************/
class cIntExpr : public cExprNode
{
public:
	cIntExpr(int val = -1);
	virtual string toString();
	virtual string GetType();
	virtual string GetBaseType();

private:
	int mVal;
};
#endif