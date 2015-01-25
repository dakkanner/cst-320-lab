/***********************************************************
* Author:				Dakota Kanner
* Filename:				cSymbolTable.cpp
************************************************************/
#include "cSymbolTable.h"

/************************************************************************
* cSymbolTable();
*		C'tor (default), creates a new map
************************************************************************/
cSymbolTable::cSymbolTable()
{
	//symbolStack = new vector<map<string, cSymbol>>();
	// Push inital map
	symbolStack.push(new map<string, cSymbol*>());
}

/************************************************************************
* ~cSymbolTable();
*		D'tor, deletes allocated memory
************************************************************************/
//cSymbolTable::~cSymbolTable()
//{
//	symbolStack->clear();
//	delete symbolStack;
//}

/************************************************************************
* IncreaseScope();
*		Adds a new layer to the top of the stack
************************************************************************/
void cSymbolTable::IncreaseScope()
{
	symbolStack.push(new map<string, cSymbol*>());
}

/************************************************************************
* DecreaseScope();
*		If possible, remove a layer from the top of the stack
************************************************************************/
void cSymbolTable::DecreaseScope()
{
	symbolStack.pop();
}

/************************************************************************
* cSymbol* Insert(string symb)
*		Insert a new symbol into the table
************************************************************************/
cSymbol* cSymbolTable::Insert(string symb) {
    cSymbol * retVal = nullptr;
    map<string,cSymbol*>::iterator Iter = symbolStack.top()->find(symb);
    if (Iter == symbolStack.top()->end())
    {
        retVal = new cSymbol(symb);
        symbolStack.top()->insert(pair<string,cSymbol*>(symb,retVal));
    }
    
    else 
    {
        retVal = Iter->second;
    }
    return retVal;
}

/************************************************************************
* cSymbol LookUpLocal(const string name);
*		Returns the entry that matches the passed-in name for the top level
************************************************************************/
//cSymbol cSymbolTable::LookUpLocal(const string name)
//{
//	// Can't find nothing
//	if ( name.empty() )
//	{
//		throw new std::invalid_argument("Can't look up symbol without a name");
//	}
//	
//	// Find it in the top-most map
//	map<string, cSymbol>::iterator symb = symbolStack->back().find(name);
//	if (symb != symbolStack->back().end())
//	{
//		return symb->second;
//	}
//	// Else return empty cSymbol
//	return cSymbol();
//}
//
///************************************************************************
//* cSymbol LookUp(const string name);
//*		Returns the entry that matches the passed-in name for all levels
//************************************************************************/
//cSymbol cSymbolTable::LookUp(const string name)
//{
//	// Can't find nothing
//	if (name.empty())
//	{
//		throw new std::invalid_argument("Can't look up symbol without a name");
//	}
//	
//	// Find the value in all the maps
//	// Start at the top and work way down. Stop if found.
//	for (vector<map<string, cSymbol>>::reverse_iterator rit = symbolStack->rbegin(); 
//		rit != symbolStack->rend(); ++rit)
//	{
//		map<string, cSymbol>::iterator symb = rit->find(name);
//		if (symb != rit->end())
//		{
//			return symb->second;
//		}
//	}
//	
//	return cSymbol();
//}
//