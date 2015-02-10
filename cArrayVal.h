/***********************************************************
* Author:				Dakota Kanner
* Filename:				cArrayVal.h
************************************************************/

#ifndef C_ARRAY_VAL_H
#define C_ARRAY_VAL_H

#pragma once
#include <list>
#include <string>
using namespace std;
#include "cExprNode.h"

/************************************************************************
* cArrayVal();
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* void Add(ExprNode* newNode);
*		Adds a new ExprNode to the list.
************************************************************************/
class cArrayVal
{
public:
	cArrayVal();
	string toString();
	void Add(cExprNode* newNode);

protected:
	list<cExprNode*> mVals;
};
#endif