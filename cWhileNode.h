#pragma once
//*******************************************************
// Purpose: Class for a while statement
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

class cWhileNode : public cStmtNode
{
  public:
    cWhileNode(cExprNode *expr, cStmtNode *stmt) : cStmtNode()
    {
        mExpr = expr;
        mStmt = stmt;
    }

    virtual std::string toString()
    {
        std::string result("(WHILE: ");
        result += mExpr->toString();
        result += "\n" + mStmt->toString();
        result += "\n)";
        return result;
    }
	
    virtual int ComputeOffsets(int base)
    {		
		if(mExpr != NULL)
			mExpr->ComputeOffsets(base);
		if(mStmt != NULL)
			mStmt->ComputeOffsets(base);
		
        return base;
    }
	
	virtual void GenerateCode()
	{
		EmitString("while(");
		if(mExpr != NULL)
			mExpr->GenerateCode();
		EmitString(")\n{\n");
		
		if(mStmt != NULL)
			mStmt->GenerateCode();
		
		EmitString("\n}");
	}

  protected:
    cExprNode *mExpr;       // conditional expression
    cStmtNode *mStmt;       // statement to execute while true
};

