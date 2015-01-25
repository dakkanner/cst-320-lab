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
}

/************************************************************************
* cSymbol(string value);
*		C'tor (with params)
************************************************************************/
cSymbol::cSymbol(std::string value)
{
	mSequence = ++symbolCount;
	mName = value;
	mValue = value;
}

/************************************************************************
* ~cSymbol();
*		D'tor
************************************************************************/
//cSymbol::~cSymbol()
//{
//	--symbolCount;
//}
//
///************************************************************************
//* operator= (const cSymbol& rhs)
//*		Allows a deep copy when using op-equals
//************************************************************************/
//cSymbol& cSymbol::operator= (const cSymbol& rhs)
//{
//	this->SetName(rhs.GetName());
//	this->SetValue(rhs.GetValue());
//
//	return *this;
//}
//
///************************************************************************
//* void SetSequence(int sequence);
//* void SetName(string name);
//* void SetValue(string value);
//*	Setters for all data members
//*
//* int GetSequence();
//* string GetName();
//* string GetValue();
//* 		Getters for all data members
//************************************************************************/
//int cSymbol::GetSequence() const
//{
//	return mSequence;
//}
//void cSymbol::SetSequence(int sequence)
//{
//	mSequence = sequence;
//}
//
//string cSymbol::GetName() const
//{
//	return mName;
//}
//void cSymbol::SetName(string name)
//{
//	mName = name;
//}
//
//string cSymbol::GetValue() const
//{
//	return mValue;
//}
//void cSymbol::SetValue(string value)
//{
//	mValue = value;
//}
//
///************************************************************************
//* bool IsEmpty();
//*		Returns true if mName or mValue is empty
//************************************************************************/
//bool cSymbol::IsEmpty() const
//{
//	bool result(false);
//
//	if (mName.empty())
//	{
//		result = true;
//	}
//	else if ( mValue.empty() )
//	{
//		result = true;
//	}
//	
//	return result;
//}


string cSymbol::toString()
{
	return "sym: " + mValue + " " + to_string(mSequence);;
}