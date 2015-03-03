#pragma once
//*******************************************************
// Purpose: Class to represent a block
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cStmtNode.h"
#include "cStmtsNode.h"
#include "cDeclsNode.h"

// blocks can be statements (e.g. if (cond) {block}
class cBlockNode : public cStmtNode
{
  public:
    cBlockNode(cDeclsNode *decls, cStmtsNode *stmts) : cStmtNode()
    {
        mDecls = decls;
        mStmts = stmts;
    }

    virtual std::string toString()
    {
        std::string result("BLOCK: ");
        result += "\n{\n";
        if (mDecls != NULL) result += mDecls->toString();
        if (mStmts != NULL) result += mStmts->toString();
        result += "}\n";
        
        return result;
    }

  protected:
    cDeclsNode *mDecls;     // declarations
    cStmtsNode *mStmts;     // statements
};

