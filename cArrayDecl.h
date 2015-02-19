/***********************************************************
* Author:				Dakota Kanner
* Filename:				cArrayDecl.h
************************************************************/

#ifndef C_ARRAY_DECL_H
#define C_ARRAY_DECL_H

#pragma once
#include "cSymbol.h"
#include "cDeclNode.h"
#include "cArraySpec.h"

/************************************************************************
* cArrayDecl(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec);
*		C'tor (with params)
*
* string toString();
*		Converts the data to a string.
************************************************************************/
class cArrayDecl : public cDeclNode
{
public:
	cArrayDecl(cSymbol* typeID, cSymbol* id, cArraySpec* arrSpec);
	virtual string toString();

private:
	cSymbol* mTypeID;
	cSymbol* mID;
	cArraySpec* mArrSpec;
};
#endif