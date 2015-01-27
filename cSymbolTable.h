/***********************************************************
* Author:					Dakota Kanner
* Filename:					cSymbolTable.h
************************************************************/

#ifndef C_SYMBOL_TABLE_H
#define C_SYMBOL_TABLE_H

#include <deque>
#include <string>
#include <map>
//#include <vector>

using namespace std;
//using std::deque;
//using std::map;
//using std::vector;
//using std::pair;

#include "cSymbol.h"


/************************************************************************
* cSymbolTable();
*		C'tor (default), creates a new map
*
* ~cSymbolTable();
*		D'tor, deletes allocated memory
*
* bool Insert(const string name, const cSymbol symb);
*		Insert a new symbol into the table
*
* bool Find(const string name);
*		Returns true if the passed-in name exists
*
* cSymbol LookUpLocal(const string name);
*		Returns the entry that matches the passed-in name for the top level
*
* cSymbol LookUp(const string name);
*		Returns the entry that matches the passed-in name for all levels
************************************************************************/
class cSymbolTable
{
public:
	cSymbolTable();
	//~cSymbolTable();
	void IncreaseScope();
	void DecreaseScope();
	cSymbol* Insert(string symb);
	cSymbol* LookUpLocal(const string name);
	cSymbol* LookUp(const string name);

protected:
	deque<map<string, cSymbol*>*> symbolDeque; 	// Collection containing deque of symbols hashed by name
};

#endif