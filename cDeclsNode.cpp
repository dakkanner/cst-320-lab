/***********************************************************
* Author:				Dakota Kanner
* Filename:				cDeclsNode.cpp
************************************************************/

#include "cDeclsNode.h"

/************************************************************************
* cDeclsNode();
*		C'tor (default)
************************************************************************/
cDeclsNode::cDeclsNode()
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cDeclsNode::toString()
{
	string retValue("DECLS:\n{\n");
	
	for(cDeclNode* i : mDecls)
	{
		retValue += i->toString() + '\n';
	}
	
	retValue += "}\n";
	
	return retValue;
}

/************************************************************************
* void Add(cDeclNode* newNode);
*		Adds a new Decl to the list.
************************************************************************/
void cDeclsNode::Add(cDeclNode* newNode)
{
	mDecls.push_back(newNode);
}