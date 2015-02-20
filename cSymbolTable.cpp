/***********************************************************
* Author:				Dakota Kanner
* Filename:				cSymbolTable.cpp
************************************************************/
#include "cSymbolTable.h"

cSymbolTable* cSymbolTable::mSymbols = NULL;

/************************************************************************
* cSymbolTable();
*		C'tor (default), creates an initial map. Private.
************************************************************************/
cSymbolTable::cSymbolTable()
{
	// Push inital map
	symbolDeque.push_back(new map<string, cSymbol*>());
	
	//Add char, int, and float manually
	cSymbol* charType = new cSymbol("char", true);
	charType->SetTypeRef("char", "char", nullptr);
	symbolDeque.back()->insert(pair<string,cSymbol*>("char",charType));
	
	cSymbol* intType = new cSymbol("int", true);
	intType->SetTypeRef("int", "int", nullptr);
	symbolDeque.back()->insert(pair<string,cSymbol*>("int",intType));
	
	cSymbol* floatType = new cSymbol("float", true);
	floatType->SetTypeRef("float", "float", nullptr);
	symbolDeque.back()->insert(pair<string,cSymbol*>("float",floatType));
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
* IncreaseScope();
*		Adds a new layer to the top of the deque
************************************************************************/
map<string,cSymbol*>* cSymbolTable::IncreaseScope()
{
	map<string,cSymbol*>* newLayer = new map<string,cSymbol*>();
	symbolDeque.push_back(newLayer);
	return newLayer;
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
    cSymbol * retVal = NULL;

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
* bool Remove(cSymbol* symbol);
*		Removes a symbol from the table. Should not be needed unless a 
* 		d'tor is implemented in the language. 
************************************************************************/
bool cSymbolTable::Remove(cSymbol* symb)
{
	if(symb != NULL)
	{
		symbolDeque.back()->erase(symb->GetSymbol());
		symb->DecrementSymbolCount();
		return true;
	}
	
	return false;
}

/************************************************************************
* cSymbol LookUpLocal(string name);
*		Returns the entry that matches the passed-in name for the top level
************************************************************************/
cSymbol* cSymbolTable::LookUpLocal(string name)
{
	cSymbol * retVal = NULL;

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
	else
	{
		retVal = NULL;
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
	cSymbol * retVal = NULL;

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
