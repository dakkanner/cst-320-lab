#pragma once
//*******************************************************
// Purpose: Base class for all declarations
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
#include "cDeclNode.h"

using std::list;

class cDeclsNode : public cAstNode
{
  public:
    // constructor places first decl in list
    cDeclsNode(cDeclNode *decl) : cAstNode()
    {
        mList = new list<cDeclNode *>();
        mList->push_back(decl);
		mSize = -1;
    }

    // add a declaration to the list
    void AddNode(cDeclNode *decl) 
    {
        mList->push_back(decl);
    }

    virtual std::string toString()
    {
        std::string result("DECLS:\n{\n");
        result += ListToString<cDeclNode *>(mList, true);
        result += "}\n";

        return result;
    }
	
	int Size()
	{
		return mSize;
	}
	
	virtual int ComputeOffsets(int base)
	{
		int off = base;

		for(cDeclNode* i : (*mList))
			off = i->ComputeOffsets(off);

		mSize = off - base;

		return off;
	}
	
	virtual void GenerateCode()
	{
		EmitString("/*cDeclsNode*/\n");
		if(mList != NULL)
		{
			for(cDeclNode* i : (*mList))
				i->GenerateCode();
		}
	}


  protected:
    list<cDeclNode*> *mList;       // list of delcarations
	int mSize;
};

