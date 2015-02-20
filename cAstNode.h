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
* cAstNode() 
*		C'tor (default)
*
* virtual string toString() = 0;
*		Pure virtual function to convert data to a string
*
* virtual bool GetSemanticError()
*		Returns whether there has been a semantic error.
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