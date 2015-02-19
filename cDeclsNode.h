/***********************************************************
* Author:				Dakota Kanner
* Filename:				cDeclsNode.h
************************************************************/

#ifndef C_DECLS_NODE_H
#define C_DECLS_NODE_H

#pragma once
#include <list>
using namespace std;
#include "cAstNode.h"
#include "cDeclNode.h"

/************************************************************************
* cDeclsNode();
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* void Add(cDeclNode* newNode);
*		Adds a new Decl to the list.
************************************************************************/
class cDeclsNode : public cAstNode
{
public:
	cDeclsNode();
	virtual string toString();
	void Add(cDeclNode* newNode);

private:
	list<cDeclNode*> mDecls;
};
#endif