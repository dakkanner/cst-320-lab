#pragma once
//*******************************************************
// Purpose: Base class for all AST nodes
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/4/2015
//
//*******************************************************

#include <iostream>
#include <string>

class cAstNode
{
  public:
    cAstNode() {mSemanticError = false;}

    // return a string representation of the class
    virtual std::string toString() = 0;
	
    // return the memory offset of this node
    virtual int ComputeOffsets(int base)
	{ return base; }

    // return true if a semantic error was detected in this node
    virtual bool SemanticError() { return mSemanticError; }

  protected:
    bool mSemanticError;        // true indicates this node has a semantic error
	
};

