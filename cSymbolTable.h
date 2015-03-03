/***********************************************************
* Author:					Dakota Kanner
* Filename:					cSymbolTable.h
************************************************************/

#ifndef C_SYMBOL_TABLE_H
#define C_SYMBOL_TABLE_H

#include <deque>
#include <string>
#include <map>

#include <iostream>

using namespace std;

#include "cSymbol.h"
#include "SymanticError.h"


/************************************************************************
* static cSymbolTable* GetInstance();
* 		Returns the instance of the symbol table
* 
* cSymbolTable();
*		C'tor (default), creates a new map
*
* ~cSymbolTable();
*		D'tor, deletes allocated memory
*
* bool Insert(string name, cSymbol symb);
*		Insert a new symbol into the table
*
* bool Remove(cSymbol* symbol);
*		Removes a symbol from the table
*
* bool Find(string name);
*		Returns true if the passed-in name exists
*
* cSymbol LookUpLocal(string name);
*		Returns the entry that matches the passed-in name for the top level
*
* cSymbol LookUp(string name);
*		Returns the entry that matches the passed-in name for all levels
************************************************************************/
class cSymbolTable
{
public:
	static cSymbolTable* GetInstance();
	map<string,cSymbol*>* IncreaseScope();
	void DecreaseScope();
	cSymbol* Insert(string symb, bool type = false);
	bool Remove(cSymbol* symb);
	cSymbol* LookUpLocal(string name);
	cSymbol* LookUp(string name);

private:
	cSymbolTable();
	deque<map<string, cSymbol*>*> symbolDeque; 	// Collection containing deque of symbols hashed by name
	static cSymbolTable* mSymbols;
};

#endif