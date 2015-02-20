/***********************************************************
* Author:				Dakota Kanner
* Filename:				cVarRef.cpp
************************************************************/

#include "cVarRef.h"

/************************************************************************
* cVarRef();
*		C'tor (default)
************************************************************************/
cVarRef::cVarRef()
	:mError("")
{ }

/************************************************************************
* string toString();
*		Converts the data to a string.
************************************************************************/
string cVarRef::toString()
{
	string retValue("");
	
	//For each VarPart
	for(cVarPart* i : mVarParts)
	{
		retValue += "(VarRef: " + i->toString();
		
		//if(i != mVarParts.front())
        //    retValue += ')';
        //else if(mVarParts.size() > 1)
        //    retValue += '\n';
	}
	
	//Now have to close each varpart
	for(int i(mVarParts.size()); i > 0; i--)
	{
		retValue += ')';
	}
	
	return retValue;
}

/************************************************************************
* void Add(cVarPart* part);
*		Adds a new VarPart to the list.
************************************************************************/
void cVarRef::Add(cVarPart* part)
{
	mSemanticError = false;
	
	if(mVarParts.size() > 0)
	{
		mSemanticError = IsSymbolInParent(part);
	}
	else if(!part->GetId()->GetIsDeclared())
	{
		mError = "Symbol " + part->GetId()->GetSymbol() + " not defined";
		mSemanticError = true;
	}
	
	//If nothing went wrong, add it.
	if(!mSemanticError)
	{
		mVarParts.push_back(part);
	}
}

/************************************************************************
* virtual string GetBaseType();
*		Function to get the base type of the node's parent
* virtual string GetType();
*		Function to get the type of the node
* cDeclNode* GetTypeRef();
*		Returns the decl_node for the symbol
************************************************************************/
string cVarRef::GetBaseType()
{
	return (*mVarParts.rbegin())->GetBaseType();
}
string cVarRef::GetType()
{
	return (*mVarParts.rbegin())->GetType();
}
cDeclNode* cVarRef::GetTypeRef()
{
	return mVarParts.back()->GetTypeRef();
}

/************************************************************************
* string VRef();
*		Returns the string of each varpart in the format va1.var2.var3...
************************************************************************/
string cVarRef::VRef()
{
	string retString("");
	int size(mVarParts.size() - 1);
	
	//For each VarPart
	for(cVarPart* i : mVarParts)
	{
		if(size == 0)
			retString += i->GetId()->GetSymbol();
		else
			retString += i->GetId()->GetSymbol() + '.';
		size--;
	}
	
	return retString;
}

/************************************************************************
* bool IsSymbolInParent(cVarPart* part);
*		Returns true if the variable is found in the struct
************************************************************************/
bool cVarRef::IsSymbolInParent(cVarPart* part)
{
	cSymbol* symb = NULL;
	cStructDecl* structDcl = NULL;
	cVarPart* varPt = mVarParts.back();
	
	//See if the parent can be a struct decl
	structDcl = static_cast<cStructDecl*>(varPt->GetTypeRef());
	
	//Find the symbol or throw the error
	if(structDcl != NULL)
	{
		symb = structDcl->Find(part->GetId()->GetSymbol());
	}
	else
	{
		mError = VRef() + " is not a struct";
		return true;
	}
	
	//Set the passed-in symbol to the found one or throw the error
	if(symb != NULL)
	{
		//symbolTableRoot->Remove(part->GetId());
		part->SetId(symb);
	}
	else
	{
		mError = part->GetId()->GetSymbol() + " is not a field of " + VRef();
		return true;
	}
	
	return false;
}

/************************************************************************
* string GetError();
*		Returns the error string
************************************************************************/
string cVarRef::GetError()
{
	return mError;
}

/************************************************************************
* string GetSymbol();
*		Returns the cSymbol
************************************************************************/
string cVarRef::GetSymbol()
{
	return mVarParts.back()->GetSymbol();
}