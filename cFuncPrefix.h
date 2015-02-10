/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncPrefix.h
************************************************************/

#ifndef C_FUNC_PREFIX_H
#define C_FUNC_PREFIX_H

#pragma once
#include "cSymbol.h"

/************************************************************************
* cFuncPrefix(cSymbol* typeId, cSymbol* ID);
*		C'tor (withy params)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cFuncPrefix
{
public:
	cFuncPrefix(cSymbol* typeId, cSymbol* id);
	string toString();

protected:
	cSymbol* mID;
	cSymbol* mTypeID;
};
#endif