/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncDecl.h
************************************************************/

#ifndef C_FUNC_DECL_H
#define C_FUNC_DECL_H

#pragma once
#include "cDeclsNode.h"
#include "cFuncDecl.h"
#include "cFuncHeader.h"
#include "cStmtsNode.h"

/************************************************************************
* cFuncDecl(cFuncHeader* header, cDeclsNode* decls = NULL, cStmtsNode* stmts = NULL);
*		C'tor (withy params)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cFuncDecl : public cDeclNode
{
public:
	cFuncDecl(cFuncHeader* header, cDeclsNode* decls = NULL, cStmtsNode* stmts = NULL);
	string toString();

protected:
	cFuncHeader* mHeader;
	cDeclsNode* mDecls;
	cStmtsNode* mStmts;
};
#endif