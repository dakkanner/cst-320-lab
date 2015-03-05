#pragma once
//*******************************************************
// Purpose: Base class for all statements
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

class cStmtNode : public cAstNode
{
  public:
    cStmtNode() : cAstNode()
    {}
};

