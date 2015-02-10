/***********************************************************
* Author:				Dakota Kanner
* Filename:				cArraySpec.h
************************************************************/

#ifndef C_ARRAY_SPEC_H
#define C_ARRAY_SPEC_H

#pragma once
#include <list>
#include <string>
using namespace std;

/************************************************************************
* cArraySpec();
*		C'tor (default)
*
* string toString();
*		Converts the data to a string.
*
* void Add(int newVal);
*		Adds a new value to the list.
************************************************************************/
class cArraySpec
{
public:
	cArraySpec();
	string toString();
	void Add(int newNode);

protected:
	list<int> mArr;
};
#endif