/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarPart.h
************************************************************/

#ifndef C_VAR_PART_H
#define C_VAR_PART_H

#pragma once

#include "cSymbol.h"
#include "cExprNode.h"
#include "cArrayVal.h"

/************************************************************************
* cVarPart();
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cVarPart : public cExprNode
{
public:
	cVarPart(cSymbol* val, cArrayVal* arr);
	string toString();

protected:
	cSymbol* mVal;
	cArrayVal* mArr;
};
#endif