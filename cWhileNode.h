#pragma once
//*******************************************************
// Purpose: Class for a while statement
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

class cWhileNode : public cStmtNode
{
  public:
    cWhileNode(cExprNode *expr, cStmtNode *stmt) : cStmtNode()
    {
        mExpr = expr;
        mStmt = stmt;
    }

    virtual string toString()
    {
        string result("(WHILE: ");
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
		EmitString("/*While loop starting*/ \n");
		
		string whileStart = GenerateLabel();
		string whileEnd = GenerateLabel();
		
		//Label for the start of the while loop
		EmitString(whileStart + ":\n");
		
		EmitString("if(!(");
		if(mExpr != NULL)
			mExpr->GenerateCode();
		EmitString("))\n");
		EmitString("\tgoto " + whileEnd + ";\n");
		
		if(mStmt != NULL)
			mStmt->GenerateCode();
		EmitString("\n");
		
		//Go back to check if loop should run again
		EmitString("goto " + whileStart + ";\n");
		
		//Label for the end of the while loop
		EmitString(whileEnd + ": ; \n");
		EmitString("/*While loop ending*/ \n");
	}

  protected:
    cExprNode *mExpr;       // conditional expression
    cStmtNode *mStmt;       // statement to execute while true
};

