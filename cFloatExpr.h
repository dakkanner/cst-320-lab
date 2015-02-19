/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFloatExpr.h
************************************************************/

#ifndef C_FLOAT_EXPR_H
#define C_FLOAT_EXPR_H

#pragma once

#include "cExprNode.h"

/************************************************************************
* cFloatExpr(float val);
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
class cFloatExpr : public cExprNode
{
public:
	cFloatExpr(float val = -1.0);
	virtual string toString();
	virtual string GetType();
	virtual string GetBaseType();

private:
	float mVal;
};
#endif