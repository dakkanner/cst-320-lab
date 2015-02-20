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
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cPrintNode::toString()
{
	if(mExpr != NULL)
		return "PRINT: " + mExpr->toString();
	return "";
}
