/***********************************************************
* Author:				Dakota Kanner
* Filename:				cSymbol.h
************************************************************/ 

#ifndef C_SYMBOL_H
#define C_SYMBOL_H

#pragma once
#include <string>
using namespace std;
//using std::string;
//using std::to_string;

/************************************************************************
* cSymbol();
*		C'tor (default)
*
* cSymbol(string type, string use, string value);
*		C'tor (with params)
*
* ~cSymbol();
*		D'tor
*
* void SetType(string type);
* void SetUse(string use);
* void SetValue(string value);
*		Setters for all data members
*
* string GetType();
* string GetUse();
* string GetValue();
*		Getters for all data members
*
* void IncrementSymbolCount();
* void DecrementSymbolCount();
* int GetSymbolCount();
*		Get and increment/decrement the total symbol count
*
* bool IsType();
*		Returns the type
************************************************************************/
class cSymbol
{
public:
	cSymbol(string value, bool type = false);
	cSymbol& operator= (cSymbol& rhs);
	string GetSymbol();
	void SetSymbol(string value);
	string toString();
	bool IsType();
	void SetType();

protected:
	int mSequence; 	// Unique integer identifier of symbol
	string mValue;	// Value of symbol
	bool mType;
	static int symbolCount;
};

#endif