#pragma once
//*******************************************************
// Purpose: Class for a scan statement
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
#include "cVarRefNode.h"

class cScanNode : public cStmtNode
{
  public:
    cScanNode(cVarRefNode *lval) : cStmtNode()
    {
        mLval = lval;
    }

    virtual std::string toString()
    {
        std::string result("SCAN: ");
        result += mLval->toString();
        return result;
    }

  protected:
    cVarRefNode *mLval;     // variable to receive the scanned value
};

