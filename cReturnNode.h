#pragma once
//*******************************************************
// Purpose: Class for a return statement
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cStmtNode.h"
#include "cExprNode.h"

class cReturnNode : public cStmtNode
{
  public:
    cReturnNode(cExprNode *expr) : cStmtNode()
    {
        mExpr = expr;
    }

    virtual std::string toString()
    {
        std::string result("RETURN: ");
        result += mExpr->toString();
        return result;
    }

  protected:
    cExprNode *mExpr;       // value to be returned
};

