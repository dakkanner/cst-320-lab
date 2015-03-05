#pragma once
//*******************************************************
// Purpose: Class to represent a block
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
		
		mSize = -1;
    }

    virtual std::string toString()
    {
        std::string result("BLOCK: ");
		
		if(mSize > -1)
			result += "size: " + std::to_string(mSize);
		
        result += "\n{\n";
        if (mDecls != NULL) result += mDecls->toString();
        if (mStmts != NULL) result += mStmts->toString();
        result += "}\n";
        
        return result;
    }
	
	virtual int ComputeOffsets(int base)
	{
		int off(base);
		
		if(mDecls != NULL)
			off = mDecls->ComputeOffsets(off);
		if (mStmts != nullptr)
			off = mStmts->ComputeOffsets(off);
        
        mSize = off - base;
		
		return base;
	}

  protected:
    cDeclsNode *mDecls;     // declarations
    cStmtsNode *mStmts;     // statements
	int mSize;
};

