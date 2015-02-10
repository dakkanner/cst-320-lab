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
************************************************************************/
class cFloatExpr : public cExprNode
{
public:
	cFloatExpr(float val);
	string toString();

protected:
	float mVal;
};
#endif