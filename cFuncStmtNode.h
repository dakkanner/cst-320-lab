#pragma once
//*******************************************************
// Purpose: Class for a function call as a statement
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

class cFuncStmtNode : public cStmtNode
{
  public:
    cFuncStmtNode(cFuncCallNode *call) : cStmtNode()
    {
        mCall = call;
    }

    virtual std::string toString()
    {
        return mCall->toString();
    }

  protected:
    cFuncCallNode *mCall;
};

