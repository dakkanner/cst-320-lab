#pragma once
//*******************************************************
// Purpose: Class for floating point constants
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/4/2015
//
//*******************************************************

#include <string>

#include "cSymbol.h"
#include "cSymbolTable.h"
#include "cExprNode.h"

class cFloatExprNode : public cExprNode
{
  public:
    cFloatExprNode(double value) : cExprNode()
    {
        mFloatVal = value;
    }

    // lookup and return type of 'float' in symbol table
    virtual cDeclNode *GetType()
    {
        cSymbol *type = symbolTableRoot->Lookup("float");
        return type->GetType();
    }

    virtual std::string toString()
    {
        std::string result("(EXPR: ");
        result += std::to_string(mFloatVal);
        result += ")";

        return result;
    }
	
	virtual int ComputeOffsets(int base)
	{ return base; }
	
	virtual void GenerateCode()
	{
		//Float to string
		EmitFloat(mFloatVal);
	}

  protected:
    double mFloatVal;       // value of float constant
};

