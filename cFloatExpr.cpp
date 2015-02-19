/***********************************************************
* Author:				Dakota Kanner
* Filename:				cFloatExpr.cpp
************************************************************/

#include "cFloatExpr.h"

/************************************************************************
* cFloatExpr(float val);
*		C'tor (default)
************************************************************************/
cFloatExpr::cFloatExpr(float val)
	:mVal(val)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cFloatExpr::toString()
{
	return "(EXPR: " + std::to_string(mVal) + ')';
}

/************************************************************************
* virtual string GetType();
*		Virtual function to get the base type of the node
************************************************************************/
string cFloatExpr::GetType()
{
	return "float";
}

/************************************************************************
* virtual string GetBaseType();
*		Virtual function to get the base type of the node
************************************************************************/
string cFloatExpr::GetBaseType()
{
	return GetType();
}
