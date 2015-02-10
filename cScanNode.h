/***********************************************************
* Author:				Dakota Kanner
* Filename:				cScanNode.h
************************************************************/

#ifndef C_SCAN_NODE_H
#define C_SCAN_NODE_H

#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

/************************************************************************
* cScanNode(cExprNode* expr);
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cScanNode : public cStmtNode
{
public:
	cScanNode(cExprNode* expr);
	string toString();

protected:
	cExprNode* mExpr;
};
#endif