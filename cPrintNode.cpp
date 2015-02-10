/***********************************************************
* Author:				Dakota Kanner
* Filename:				cPrintNode.cpp
************************************************************/

#include "cPrintNode.h"

/************************************************************************
* cPrintNode();
*		C'tor (default)
************************************************************************/
cPrintNode::cPrintNode(cExprNode* expr)
	:mExpr(expr)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cPrintNode::toString()
{
	return "PRINT: " + mExpr->toString();
}
