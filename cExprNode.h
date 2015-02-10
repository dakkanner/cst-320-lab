/***********************************************************
* Author:				Dakota Kanner
* Filename:				cExprNode.h
************************************************************/

#ifndef C_EXPR_NODE_H
#define C_EXPR_NODE_H

#pragma once
#include <string>
using std::string;

/************************************************************************
* virtual string toString() = 0;
*		Pure virtual function to convert data to a string
*
************************************************************************/
class cExprNode
{
public:
	virtual string toString() = 0;
	
protected:
	cExprNode* mExpr;
};
#endif