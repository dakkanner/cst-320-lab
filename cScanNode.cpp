/***********************************************************
* Author:				Dakota Kanner
* Filename:				cScanNode.cpp
************************************************************/

#include "cScanNode.h"

/************************************************************************
* cScanNode(cExprNode* expr);
*		C'tor (default)
************************************************************************/
cScanNode::cScanNode(cExprNode* expr)
	:mExpr(expr)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cScanNode::toString()
{
	if(mExpr != NULL)
		return "SCAN: " + mExpr->toString();
	
	return "";
}