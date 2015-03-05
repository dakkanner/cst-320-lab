#pragma once
//*******************************************************
// Purpose: Class for a variable declaration
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
#include "cDeclNode.h"
#include "cStructDeclNode.h"
#include "cSymbol.h"

#include "parse.h"

class cVarDeclNode : public cDeclNode
{
  public:
    cVarDeclNode(cSymbol *type, cSymbol *id) : cDeclNode()
    {
		mOffset = -1;
        cSymbol *localId = symbolTableRoot->LocalLookup(id->Name());
        if (localId != NULL)
        {
            semantic_error("Symbol " + id->Name() +
                    " already defined in current scope");
        }
        // We may have an id from an outter scope. This will either
        // create a new symbol or return the already existing symbol
        // in the current scope.
        id = symbolTableRoot->Insert(id);

        mType = type->GetType();
        mId = id;
        mId->SetType(this);
    }

    // return the decl of the type
    virtual cDeclNode *GetBaseType()
    {
        return mType;
    }

    virtual bool IsArray()  { return mType->IsArray(); }
    virtual bool IsStruct() { return mType->IsStruct(); }
    virtual bool IsFloat()  { return mType->IsFloat(); }
    virtual bool IsInt()    { return mType->IsInt(); }

    virtual std::string toString()
    {
        std::string result("VAR: ");
        result += mType->TypeId();
        result += " " + mId->toString();
		
		if(mSize > -1)
			result += " size: " + std::to_string(mSize);
		if(mOffset > -1)
			result += " offset: " + std::to_string(mOffset);
		
        return result;
    }
	
    virtual int ComputeOffsets(int base)
    {
		if(mType->Size() >= WORD_SIZE)
		{
			// Word Align
			if(base % WORD_SIZE != 0)
			{
				base = (base + WORD_SIZE)/WORD_SIZE; //Yeah?
				base *= WORD_SIZE;
			}
		}
		
		mOffset = base;
		mSize = mType->Size();
		
		//result += mSize;
        return mOffset + mSize;
    }

  protected:
    cDeclNode *mType;   // the type for the decl
                        // NOTE: this class inherits members from cDeclNode
};

