/***********************************************************
* Author:				Dakota Kanner
* Filename:				cSymbol.cpp
************************************************************/ 

#include "cSymbol.h"
int cSymbol::symbolCount = 0;

/************************************************************************
* cSymbol(string value);
*		C'tor (with params)
************************************************************************/
cSymbol::cSymbol(std::string value, bool type)
	:mValue (value), mType(type)
{
	mSequence = ++symbolCount;
}

/************************************************************************
* operator= (cSymbol& rhs)
*		Allows a deep copy when using op-equals
************************************************************************/
cSymbol& cSymbol::operator= (cSymbol& rhs)
{
	mSequence = rhs.mSequence;
	mValue = rhs.mValue;
	mType = rhs.mType;

	return *this;
}

/************************************************************************
* string GetSymbol();
* 		Getters for all data member
*
* void SetSymbol(string value);
*			Setters for all data member
************************************************************************/
string cSymbol::GetSymbol() 
{
	return mValue;
}
void cSymbol::SetSymbol(string value)
{
	mValue = value;
}

/************************************************************************
* string cSymbol::toString();
* 		Prints the value and sequence number of the symbol
************************************************************************/
string cSymbol::toString()
{
	return "sym: " + mValue + ' ' + to_string(mSequence);;
}

/************************************************************************
* bool IsType();
*		Returns the type
* void SetType();
*		Sets the type to true
************************************************************************/
bool cSymbol::IsType()
{
    return mType;
}
void cSymbol::SetType()
{
    mType = true;
}

