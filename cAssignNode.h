#pragma once
//*******************************************************
// Purpose: Class for an assignment statement
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
#include "parse.h"

class cAssignNode : public cStmtNode
{
  public:
    cAssignNode(cVarRefNode *lval, cExprNode *expr) : cStmtNode()
    {
        mLval = lval;
        mExpr = expr;
        if (!lval->GetType()->CompatibleWith(expr->GetType()))
        {
            semantic_error("Cannot assign " + 
                    expr->GetType()->GetBaseType()->Name() +
                    " to " + lval->GetType()->GetBaseType()->Name());
        }
    }

    virtual std::string toString()
    {
        std::string result("(ASSIGN: ");
        result += mLval->toString();
        result += " = ";
        result += mExpr->toString();
        result += ")";
        return result;
    }
	
    virtual int ComputeOffsets(int base)
    {
		if(mLval != NULL)
			mLval->ComputeOffsets(base);
		
		if(mExpr != NULL)
			mExpr->ComputeOffsets(base);
		
        return base;
    }
	
	virtual void GenerateCode()
	{
		if(mLval != NULL)
		{
			mLval->GenerateCode();
			EmitString(" = ");
		}
		if(mExpr != NULL)
		{
			mExpr->GenerateCode();
			EmitString(";\n");
		}
	}

  protected:
    cExprNode   *mExpr;     // the rhs of the assignment
    cVarRefNode *mLval;     // the lhs of the assignment`
};

