#pragma once
//*******************************************************
// Purpose: Class for a structure type delcaration
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/4/2015
//
//*******************************************************

#include <string>
#include "cAstNode.h"
#include "cDeclsNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cScope.h"

class cStructDeclNode : public cDeclNode
{
  public:
    cStructDeclNode(cScope *symTab, cDeclsNode *decls, cSymbol *id) 
        : cDeclNode()
    {
        mSymTab = symTab;
        mId = id;
        mDecls = decls;
        id->SetType(this);

        symbolTableRoot->Insert(id);
    }

    virtual bool IsStruct() { return true; }
    virtual bool IsType()   { return true; }

    // Lookup a field name to see if it is a member of this struct
    cSymbol *Lookup(std::string id)
    {
        return mSymTab->Lookup(id);
    }

    virtual std::string toString()
    {
        std::string result("STRUCT: ");
        result += mDecls->toString();
        result += " " + mId->toString();
		
		result += " size: " + std::to_string(mSize);
		
        return result;
    }
	
	int ComputeOffsets(int base)
	{
		mOffset = base;
		mDecls->ComputeOffsets(0);
		mSize = mDecls->Size();

		return mOffset;
	}

  protected:
    cScope *mSymTab;        // symbol table for this struct
    cDeclsNode *mDecls;     // list of fields
	int mOffset;
};

