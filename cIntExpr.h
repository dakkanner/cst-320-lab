/***********************************************************
* Author:				Dakota Kanner
* Filename:				cIntExpr.h
************************************************************/

#ifndef C_INT_EXPR_H
#define C_INT_EXPR_H

#pragma once

#include "cExprNode.h"

/************************************************************************
* cIntExpr(int val);
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cIntExpr : public cExprNode
{
public:
	cIntExpr(int val);
	string toString();

protected:
	int mVal;
};
#endif