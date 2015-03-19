#pragma once
//*******************************************************
// Purpose: A list of actual params passed to a function
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

#include "cAstNode.h"
#include "cExprNode.h"
#include "cAstList.h"

using std::list;

class cParamNode: public cAstNode
{
  public:
    // place the first param in the list
    cParamNode(cExprNode *param) : cAstNode()
    {
        mList = new list<cExprNode *>();
        if (param != NULL) mList->push_back(param);
    }

    // place the next param in the list
    void AddNode(cExprNode *param) 
    {
        mList->push_back(param);
    }

    // return a specific param
    cExprNode *GetParam(int index)
    {
        return ListGetItem(mList, index);
    }

    int NumParams()
    { return mList->size(); }

    virtual std::string toString()
    {
        std::string result("(PARAM:");
        result += ListToString(mList, false);
        result += ")\n";

        return result;
    }
	  
	int ComputeOffsets(int base)
	{
		for(cExprNode* i : (*mList))
			i->ComputeOffsets(base);

		return base;
	}
	
	virtual void GenerateCode()
	{
		for(cExprNode* expr : (*mList))
		{
			if(expr->GetType()->IsInt())
				EmitString("*(int*)(&Memory[Stack_Pointer]) = ");
			else   	// Float
				EmitString("*(double*)(&Memory[Stack_Pointer]) = ");
		
			expr->GenerateCode();
			EmitString(";\n");
			EmitString("Stack_Pointer += 4;\n");
		}
	}

  protected:
    list<cExprNode*> *mList;       // list of parameters
};

