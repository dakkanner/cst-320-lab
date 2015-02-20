/***********************************************************
* Author:				Dakota Kanner
* Filename:				cScanNode.cpp
************************************************************/

#include "cScanNode.h"

/************************************************************************
* cScanNode(cExprNode* expr);
*		C'tor (with param)
************************************************************************/
cScanNode::cScanNode(cExprNode* expr)
	:mExpr(expr)
{ }

/************************************************************************
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cScanNode::toString()
{
	if(mExpr != NULL)
		return "SCAN: " + mExpr->toString();
	
	return "";
}