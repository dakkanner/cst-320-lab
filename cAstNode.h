/***********************************************************
* Author:				Dakota Kanner
* Filename:				cAstNode.h
************************************************************/

#ifndef C_AST_NODE_H
#define C_AST_NODE_H

#pragma once
#include <string>
using namespace std;

/************************************************************************
*
* virtual string toString() = 0;
*		Pure virtual function to convert data to a string
*
************************************************************************/
class cAstNode
{
public:
	cAstNode() 
	{ }
	virtual bool GetSemanticError()
		{ return mSemanticError; }
	virtual string toString() = 0;
	
protected:
	bool mSemanticError;
};
#endif