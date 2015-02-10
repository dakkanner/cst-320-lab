/***********************************************************
* Author:				Dakota Kanner
* Filename:				cBlockNode.h
************************************************************/

#ifndef C_BLOCK_NODE_H
#define C_BLOCK_NODE_H

#pragma once

#include "cSymbolTable.h"
#include "cSymbol.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cStmtNode.h"

/************************************************************************
* cBlockNode(cSymbolTable* symbolTable, cDeclsNode* decls = NULL, cStmtsNode* stmts = NULL);
*		C'tor
*
* string toString();
*		Function to convert data to a string
*
************************************************************************/
class cBlockNode : public cStmtNode
{
public:
	cBlockNode(cSymbolTable* symbolTable, cDeclsNode* decls = NULL, cStmtsNode* stmts = NULL);
	string toString();
	
protected:
	cSymbolTable* mSymbolTable;
	cDeclsNode* mDecls;
	cStmtsNode* mStmts;
};
#endif