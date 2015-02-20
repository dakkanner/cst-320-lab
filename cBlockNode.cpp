/***********************************************************
* Author:				Dakota Kanner
* Filename:				cBlockNode.cpp
************************************************************/

#include "cBlockNode.h"

/************************************************************************
* cBlockNode(map<string,cSymbol*>* symbolTable, cDeclsNode* decls, cStmtsNode* stmts);
*		C'tor (with params)
************************************************************************/
cBlockNode::cBlockNode(map<string,cSymbol*>* symbolTable, cDeclsNode* decls, cStmtsNode* stmts)
	:mSymbolTable(symbolTable), mDecls(decls), mStmts(stmts)
{ }

/************************************************************************
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cBlockNode::toString()
{
	string retValue("BLOCK: \n{\n");
	
	if (mDecls != NULL)
		retValue += mDecls->toString();
	if (mStmts != NULL)
		retValue += mStmts->toString();
	
	retValue += "\n}";
	
	return retValue;
}