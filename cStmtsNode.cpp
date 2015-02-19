/***********************************************************
* Author:				Dakota Kanner
* Filename:				cStmtsNode.cpp
************************************************************/

#include "cStmtsNode.h"

/************************************************************************
* cStmtsNode();
*		C'tor (default)
************************************************************************/
cStmtsNode::cStmtsNode()
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cStmtsNode::toString()
{
	string retValue("STMTS:\n{\n");
	
	for(cStmtNode* i : mStmts)
	{
		retValue += i->toString() + '\n';
	}
	
	retValue += "}";
	
	return retValue;
}

/************************************************************************
* void Add(cStmtNode* newNode);
*		Adds a new Stmt to the list.
************************************************************************/
void cStmtsNode::Add(cStmtNode* newNode)
{
	if(newNode != NULL)
		mStmts.push_back(newNode);
}