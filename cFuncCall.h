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
*		C'tor (withy params)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cFuncCall : public cStmtNode, public cExprNode
{
public:
	cFuncCall(cSymbol* id, cParamsNode* params);
	string toString();

protected:
	cSymbol* mID;
	cParamsNode* mParams;
};
#endif