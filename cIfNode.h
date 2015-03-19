#pragma once
//*******************************************************
// Purpose: Class for an if statement
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/18/2015
//
//*******************************************************

#include <string>
using std::string;

#include "cStmtNode.h"
#include "cExprNode.h"

class cIfNode : public cStmtNode
{
  public:
    cIfNode(cExprNode *expr, cStmtNode *ifPart, cStmtNode *elsePart) 
        : cStmtNode()
    {
        mExpr = expr;
        mStmt = ifPart;
        mElse = elsePart;
    }

    virtual std::string toString()
    {
        std::string result("(IF: ");
        result += mExpr->toString();
        result += "\n" + mStmt->toString();
        if (mElse != NULL) result += "\nELSE:\n" + mElse->toString();
        result += "\n)";
        return result;
    }
	
	virtual int ComputeOffsets(int base)
	{
		if(mExpr != NULL)
		{
			mExpr->ComputeOffsets(base);
		}
		if(mStmt != NULL)
		{
			mStmt->ComputeOffsets(base);
		}

		return base;
	}
	
	virtual void GenerateCode()
	{
		EmitString("/*If/else block starting*/ \n");
		
		string ifStart = GenerateLabel();
		string elseStart = GenerateLabel();
		string elseEnd = GenerateLabel();
		
		EmitString("if(");
		mExpr->GenerateCode();
		EmitString(") \n");
		EmitString("\tgoto " + ifStart + ";\n");
		
		if(mElse != NULL)
			EmitString("goto " + elseStart + ";\n");
		else
			EmitString("goto " + elseEnd + ";\n");
		
		//If block
		if(mStmt != NULL)
		{
			EmitString("/*Begin if(true) stmt*/ \n");
			EmitString(ifStart + ":\n");
			mStmt->GenerateCode();
			EmitString("goto " + elseEnd + ";\n");
		}
		
		//else
		if(mElse != NULL)
		{
			EmitString("/*Begin else stmt*/ \n");
			EmitString(elseStart + ":\n");
			mElse->GenerateCode();
			//EmitString("goto " + elseEnd + ";\n");
		}
		
		EmitString(elseEnd + ": ;\n"); 		//Apparently we need that semicolon there.
		EmitString("/*Done with if/else block*/ \n");
	}

  protected:
    cExprNode *mExpr;       // conditional expression
    cStmtNode *mStmt;       // statements for if cond is true
    cStmtNode *mElse;       // optional statements for if cond is false
};

