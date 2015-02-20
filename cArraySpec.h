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
* virtual string toString();
*		Converts the data to a string.
*
* void Add(int newVal);
*		Adds a new value to the list.
************************************************************************/
class cArraySpec
{
public:
	cArraySpec();
	virtual string toString();
	void Add(int newNode);

private:
	list<int> mArr;
};
#endif