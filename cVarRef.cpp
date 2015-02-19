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
		retValue += "(VarRef: " + i->toString() + " ";
		
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

string cVarRef::GetSymbol()
{
	return mVarParts.back()->GetSymbol();
}

string cVarRef::GetBaseType()
{
	return (*mVarParts.rbegin())->GetBaseType();
	
	
	
	//return mVarParts.back()->GetBaseType();
}

string cVarRef::GetType()
{
	return (*mVarParts.rbegin())->GetType();
	
	
	
	
	
	
	
	
	//return mVarParts.back()->GetType();
}

cDeclNode* cVarRef::GetTypeRef()
{
	return mVarParts.back()->GetTypeRef();
}

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

bool cVarRef::IsSymbolInParent(cVarPart* part)
{
	cSymbol* symb = NULL;
	cStructDecl* structDcl = NULL;
	cVarPart* varPt = mVarParts.back();
	
	//See if the parent can be a struct decl
	try
	{
		structDcl = static_cast<cStructDecl*>(varPt->GetTypeRef());
	}
	catch (...)
	{ }
	
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
		symbolTableRoot->Remove(part->GetId());
		part->SetId(symb);
	}
	else
	{
		mError = part->GetId()->GetSymbol() + " is not a field of " + VRef();
		return true;
	}
	
	return false;
}

string cVarRef::GetError()
{
	return mError;
}
