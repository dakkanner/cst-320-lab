#pragma once
//*******************************************************
// Purpose: Class for a structure type delcaration
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
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

        return result;
    }

  protected:
    cScope *mSymTab;        // symbol table for this struct
    cDeclsNode *mDecls;     // list of fields
};

