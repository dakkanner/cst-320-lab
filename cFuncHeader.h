/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFuncHeader.h
************************************************************/

#ifndef C_FUNC_HEADER_H
#define C_FUNC_HEADER_H

#pragma once
#include "cFuncPrefix.h"
#include "cParamsSpec.h"

/************************************************************************
* cFuncHeader(cFuncPrefix* prefix, cParamsSpec* params = NULL);
*		C'tor (withy params)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cFuncHeader
{
public:
	cFuncHeader(cFuncPrefix* prefix, cParamsSpec* params = NULL);
	string toString();

protected:
	cFuncPrefix* mPrefix;
	cParamsSpec* mParams;
};
#endif