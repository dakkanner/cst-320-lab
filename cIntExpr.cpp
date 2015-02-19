/***********************************************************
* Author:				Dakota Kanner
* Filename:				cIntExpr.cpp
************************************************************/

#include "cIntExpr.h"

/************************************************************************
* cIntExpr(int val);
*		C'tor (default)
************************************************************************/
cIntExpr::cIntExpr(int val)
	:mVal(val)
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cIntExpr::toString()
{
	return "(EXPR: " + std::to_string(mVal) + ')';
}


/************************************************************************
* virtual string GetType();
*		Virtual function to get the base type of the node
************************************************************************/
string cIntExpr::GetType()
{
	if(mVal >= -128 && mVal < 128)
        return "char";
	return "int";
}

/************************************************************************
* virtual string GetBaseType();
*		Pure virtual function to get the base type of the node
************************************************************************/
string cIntExpr::GetBaseType()
{
	return GetType();
}
