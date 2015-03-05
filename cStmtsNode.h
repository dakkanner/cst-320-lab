#pragma once
//*******************************************************
// Purpose: Class for a list of statements
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/4/2015
//
//*******************************************************

#include <string>
#include <list>
using std::list;

#include "cAstNode.h"
#include "cAstList.h"

class cStmtsNode : public cAstNode
{
  public:
    // create the list and insert the first statement
    cStmtsNode(cStmtNode *stmt) : cAstNode()
    {
        mList = new list<cStmtNode *>();
        mList->push_back(stmt);
    }

    // add a statement to the list
    void AddNode(cStmtNode *stmt) 
    {
        mList->push_back(stmt);
    }

    virtual std::string toString()
    {
        std::string result("STMTS:\n{\n");
        result += ListToString(mList, true);
        result += "}\n";

        return result;
    }
	
	virtual int ComputeOffsets(int base)
	{
		int offset = base;

		for(cStmtNode* i : (*mList))
			offset = i->ComputeOffsets(offset);

		mSize = offset - base;

		return offset;
	}

  protected:
    list<cStmtNode *> *mList;   // list of statements
	int mSize;
};

