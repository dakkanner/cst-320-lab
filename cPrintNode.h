#pragma once
//*******************************************************
// Purpose: Class for a print statement
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/4/2015
//
//*******************************************************

#include <string>

#include "cStmtNode.h"
#include "cExprNode.h"

class cPrintNode : public cStmtNode
{
  public:
    cPrintNode(cExprNode *expr) : cStmtNode()
    {
        mExpr = expr;
    }

    virtual std::string toString()
    {
        std::string result("PRINT: ");
        result += mExpr->toString();
        return result;
    }
	
	virtual int ComputeOffsets(int base)
	{
		mExpr->ComputeOffsets(base);
		return base;
	}
	
	virtual void GenerateCode()
	{
		if(mExpr->GetType()->IsInt())
			EmitString("Temp = ");
		else   	// Float
			EmitString("Temp_F = ");
		
		if(mExpr != NULL)
			mExpr->GenerateCode();
		
		EmitString(";\n");
		
		if(mExpr->GetType()->IsInt())
			EmitPrintTemp();
		else   	// Float
			EmitPrintTemp_F();
	}

  protected:
    cExprNode *mExpr;       // expression to be printed
};

