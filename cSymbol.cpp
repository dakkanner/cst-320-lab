/***********************************************************
* Author:				Dakota Kanner
* Filename:				cSymbol.cpp
************************************************************/

#include "cSymbol.h"
int cSymbol::symbolCount = 0;

/************************************************************************
* cSymbol();
*		C'tor (default)
************************************************************************/
cSymbol::cSymbol()
{ 
	mSequence = ++symbolCount;
	mValue = "";
}

/************************************************************************
* cSymbol(string value);
*		C'tor (with params)
************************************************************************/
cSymbol::cSymbol(std::string value)
{
	mSequence = ++symbolCount;
	mValue = value;
}

/************************************************************************
* operator= (const cSymbol& rhs)
*		Allows a deep copy when using op-equals
************************************************************************/
cSymbol& cSymbol::operator= (const cSymbol& rhs)
{
	mSequence = rhs.mSequence;
	mValue = rhs.mValue;

	return *this;
}

/************************************************************************
* string GetValue() const;
* 		Getters for all data member
*
* void SetValue(string value);
*			Setters for all data member
************************************************************************/
string cSymbol::GetValue() const
{
	return mValue;
}
void cSymbol::SetValue(string value)
{
	mValue = value;
}

/************************************************************************
* string cSymbol::toString();
* 		Prints the value and sequence number of the symbol
************************************************************************/
string cSymbol::toString()
{
	return "sym: " + mValue + " " + to_string(mSequence);;
}