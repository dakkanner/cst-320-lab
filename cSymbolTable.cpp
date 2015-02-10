/***********************************************************
* Author:				Dakota Kanner
* Filename:				cSymbolTable.cpp
************************************************************/
#include "cSymbolTable.h"

cSymbolTable* cSymbolTable::mSymbols = NULL;

/************************************************************************
* cSymbolTable();
*		C'tor (default), creates a new map
************************************************************************/
cSymbolTable::cSymbolTable()
{
	// Push inital map
	symbolDeque.push_back(new map<string, cSymbol*>());
	
	Insert("char", true);
	Insert("int", true);
	Insert("float", true);
}

/************************************************************************
* cSymbolTable* GetInstance();
*		Returns the instance of the table. Creates it if it didn't 
* 		exist before
************************************************************************/
cSymbolTable* cSymbolTable::GetInstance()
{
    if(mSymbols == NULL)
        mSymbols = new cSymbolTable();
    
    return mSymbols;
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
map<string,cSymbol*>* cSymbolTable::IncreaseScope()
{
	symbolDeque.push_back(new map<string, cSymbol*>());
	return symbolDeque.back();
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
cSymbol* cSymbolTable::Insert(string symb, bool type) 
{
    cSymbol * retVal = nullptr;

    map<string,cSymbol*>::iterator iter = symbolDeque.back()->find(symb);
    if (iter == symbolDeque.back()->end())
    {
        retVal = new cSymbol(symb, type);
        symbolDeque.back()->insert(pair<string,cSymbol*>(symb,retVal));
    }
    else 
    {
        retVal = iter->second;
    }
    return retVal;
}

/************************************************************************
* cSymbol LookUpLocal(string name);
*		Returns the entry that matches the passed-in name for the top level
************************************************************************/
cSymbol* cSymbolTable::LookUpLocal(string name)
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
* cSymbol LookUp(string name);
*		Returns the entry that matches the passed-in name for all levels
************************************************************************/
cSymbol* cSymbolTable::LookUp(string name)
{
	cSymbol * retVal = nullptr;

	// Can't find nothing
	if (name.empty())
	{
		throw new std::invalid_argument("Can't look up symbol without a name");
	}	
	
	deque<map<string, cSymbol*>*>::iterator symb;
	for(symb = symbolDeque.begin(); symb != symbolDeque.end(); ++symb)
	{
		//Search map for the symbol
		map<string,cSymbol*>::iterator sym = (*symb)->find(name);
		
		//If found return the symbol
		if(sym != (*symb)->end())	
			retVal = sym->second;
	}
	
	return retVal;
}