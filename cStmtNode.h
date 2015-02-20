/***********************************************************
* Author:				Dakota Kanner
* Filename:				cStmtNode.h
************************************************************/

#ifndef C_STMT_NODE_H
#define C_STMT_NODE_H

#pragma once

#include <string>

#include "cAstNode.h"

using std::string;

/************************************************************************
*
* virtual string toString() = 0;
*		Pure virtual function to convert data to a string
*
************************************************************************/
class cStmtNode : public cAstNode
{
public:
	virtual string toString() = 0;
};
#endif