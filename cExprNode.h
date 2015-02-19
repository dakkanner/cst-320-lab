/***********************************************************
* Author:				Dakota Kanner
* Filename:				cExprNode.h
************************************************************/

#ifndef C_EXPR_NODE_H
#define C_EXPR_NODE_H

#pragma once
#include <string>
using std::string;

#include "cAstNode.h"
#include "cDeclNode.h"

/************************************************************************
* virtual string toString() = 0;
*		Pure virtual function to convert data to a string
*
* virtual string GetType() = 0;
*		Pure virtual function to get the type of the node
*
* virtual string GetBaseType() = 0;
*		Pure virtual function to get the base type of the node
*
************************************************************************/
class cExprNode : public cAstNode
{
public:
	//virtual string toString() = 0;
	virtual string GetType() = 0;
	virtual string GetBaseType() = 0;
	virtual cDeclNode* GetTypeRef()
	{ return NULL; }
	
};
#endif