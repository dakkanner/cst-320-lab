/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncDecl.h
************************************************************/

#ifndef C_FUNC_DECL_H
#define C_FUNC_DECL_H

#pragma once
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cParamsSpec.h"

/************************************************************************
* cFuncDecl(cSymbol* header = NULL, cParamsSpec* params; = NULL);
*		C'tor (with params)
*
* virtual string toString();
*		Converts the data to a string.
*
* void SetDecls(cDeclsNode* decls = NULL);
*		Sets mDecls
* cDeclsNode* GetDecls();
*		Returns mDecls
* void SetStmts(cStmtsNode* stmts = NULL);
*		Sets mStmts
* cStmtsNode* GetStmts();
*		Returns mStmts
************************************************************************/
class cFuncDecl : public cDeclNode
{
public:
	cFuncDecl(cSymbol* header = NULL, cParamsSpec* params = NULL);
	virtual string toString();
	
	void SetDecls(cDeclsNode* decls = NULL);
	cDeclsNode* GetDecls();
	void SetStmts(cStmtsNode* stmts = NULL);
	cStmtsNode* GetStmts();
	
private:
	cSymbol* mHeader;
	cDeclsNode* mDecls;
	cStmtsNode* mStmts;
	cParamsSpec* mParams;
};
#endif