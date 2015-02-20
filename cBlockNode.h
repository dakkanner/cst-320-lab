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
*		C'tor (with params)
*
* virtual string toString();
*		Converts the data to a string.
*
************************************************************************/
class cBlockNode : public cStmtNode
{
public:
	cBlockNode(map<string,cSymbol*>* symbolTable = NULL, cDeclsNode* decls = NULL, cStmtsNode* stmts = NULL);
	virtual string toString();
	
private:
	map<string,cSymbol*>* mSymbolTable;
	cDeclsNode* mDecls;
	cStmtsNode* mStmts;
};
#endif