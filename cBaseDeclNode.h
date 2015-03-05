#pragma once
//*******************************************************
// Purpose: Decl class for primitive types
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/4/2015
//
//*******************************************************

#include <string>

#include "cDeclNode.h"
#include "cSymbol.h"

class cBaseDeclNode : public cDeclNode
{
  public:
    cBaseDeclNode(cSymbol *id, int size, int isFloat) : cDeclNode()
    {
        mId = id;
        mSize = size;
        mIsFloat = isFloat;
    }

    virtual bool IsInt()   { return !mIsFloat; }
    virtual bool IsFloat() { return mIsFloat; }
    virtual bool IsType()  { return true; }

    virtual std::string toString()
    {
        return mId->toString();
    }

  protected:
    bool mIsFloat;      // flag indicating a floating point primitive type
};

