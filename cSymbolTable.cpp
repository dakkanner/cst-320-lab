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
	//symbolDeque = new vector<map<string, cSymbol>>();
	// Push inital map
	symbolDeque.push_back(new map<string, cSymbol*>());
}

/************************************************************************
* ~cSymbolTable();
*		D'tor, deletes allocated memory
************************************************************************/
//cSymbolTable::~cSymbolTable()
//{
//	symbolDeque->clear();
//	delete symbolDeque;
//}

/************************************************************************
* IncreaseScope();
*		Adds a new layer to the top of the deque
************************************************************************/
void cSymbolTable::IncreaseScope()
{
	symbolDeque.push_back(new map<string, cSymbol*>());
}

/************************************************************************
* DecreaseScope();
*		If possible, remove a layer from the top of the deque
************************************************************************/
void cSymbolTable::DecreaseScope()
{
	symbolDeque.pop_back();
}

/************************************************************************
* cSymbol* Insert(string symb)
*		Insert a new symbol into the table
************************************************************************/
cSymbol* cSymbolTable::Insert(string symb) 
{
    cSymbol * retVal = nullptr;

    map<string,cSymbol*>::iterator Iter = symbolDeque.back()->find(symb);
    if (Iter == symbolDeque.back()->end())
    {
        retVal = new cSymbol(symb);
        symbolDeque.back()->insert(pair<string,cSymbol*>(symb,retVal));
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
cSymbol* cSymbolTable::LookUpLocal(const string name)
{
	cSymbol * retVal = nullptr;

	// Can't find nothing
	if ( name.empty() )
	{
		throw new std::invalid_argument("Can't look up symbol without a name");
	}
	
	// Find it in the top-most map
	map<string, cSymbol*>::iterator symb = symbolDeque.back()->find(name);
	if (symb != symbolDeque.back()->end())
	{
		retVal = symb->second;
	}
	// Else return empty cSymbol
	return retVal;
}

/************************************************************************
* cSymbol LookUp(const string name);
*		Returns the entry that matches the passed-in name for all levels
************************************************************************/
cSymbol* cSymbolTable::LookUp(const string name)
{
	cSymbol * retVal = nullptr;

	// Can't find nothing
	if (name.empty())
	{
		throw new std::invalid_argument("Can't look up symbol without a name");
	}

	// Find the highest-level matching symbol
	for (int i = symbolDeque.size()-1;
		i >= 0; --i)
	{
		map<string, cSymbol*>::iterator symb = map<string, cSymbol*>::iterator();
		symb = symbolDeque[i]->find(name);

		if (symb != symbolDeque[i]->end())
		{
			retVal = symb->second;
			break;
		}
	}
	
	return retVal;
}
