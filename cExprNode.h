#pragma once
//*******************************************************
// Purpose: Base class for all expressions
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/4/2015
//
//*******************************************************

#include <string>

#include "cAstNode.h"

class cExprNode : public cAstNode
{
  public:
    cExprNode() : cAstNode()
    { }

    // return the type of the expression
    virtual cDeclNode *GetType() =  0;
	
	virtual void GenerateCode()
	{ }
};

