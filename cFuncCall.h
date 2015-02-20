/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncCall.h
************************************************************/

#ifndef C_FUNC_CALL_H
#define C_FUNC_CALL_H

#pragma once
#include "cSymbol.h"
#include "cParamsNode.h"
#include "cExprNode.h"
#include "cStmtNode.h"

/************************************************************************
* cFuncCall(cSymbol* id, cParamsNode* params);
*		C'tor (with params)
*
* virtual string toString();
*		Converts the data to a string.
*
* virtual string GetType();
*		Virtual function to get the type of the node
*
* virtual string GetBaseType();
*		Virtual function to get the base type of the node
************************************************************************/
class cFuncCall : public cStmtNode, public cExprNode
{
public:
	cFuncCall(cSymbol* id, cParamsNode* params);
	virtual string toString();
	virtual string GetType();
	virtual string GetBaseType();

private:
	cSymbol* mID;
	cParamsNode* mParams;
};
#endif