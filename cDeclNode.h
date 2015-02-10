/***********************************************************
* Author:				Dakota Kanner
* Filename:				cDeclNode.h
************************************************************/

#ifndef C_DECL_NODE_H
#define C_DECL_NODE_H

#pragma once
#include <string>
using namespace std;

/************************************************************************
* virtual string toString() = 0;
*		Pure virtual function to convert data to a string
*
************************************************************************/
class cDeclNode
{
public:
	virtual string toString() = 0;

};
#endif