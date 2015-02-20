/***********************************************************
* Author:				Dakota Kanner
* Filename:				cArraySpec.cpp
************************************************************/

#include "cArraySpec.h"

/************************************************************************
* cArraySpec();
*		C'tor (default)
************************************************************************/
cArraySpec::cArraySpec()
{ }

/************************************************************************
* virtual string toString();
*		Converts the data to a string.
************************************************************************/
string cArraySpec::toString()
{
	string retValue("(ARRAYSPEC:");
	
	for(int &i : mArr)
	{
		retValue += ' ' + std::to_string(i);
	}
	
	retValue += ")";
	
	return retValue;
}

/************************************************************************
* void Add(int newVal);
*		Adds a new value to the list.
************************************************************************/
void cArraySpec::Add(int newVal)
{
	mArr.push_back(newVal);
}