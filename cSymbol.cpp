/***********************************************************
* Author:				Dakota Kanner
* Filename:				cSymbol.cpp
************************************************************/ 

#include "cSymbol.h"
int cSymbol::symbolCount = 0;

/************************************************************************
* cSymbol(string value, bool isType = false);
*		C'tor (with params)
************************************************************************/
cSymbol::cSymbol(string value, bool isType)
	:mValue(value), mSequence(++symbolCount), mIsType(isType), mIsDeclared(false), mTypeRef(""), mBaseType(""), mDecl(NULL)
{ }
/************************************************************************
* string GetSymbol();
* 		Getter for the symbol name
* void SetSymbol(string value);
*		Setter for the symbol name
************************************************************************/
string cSymbol::GetSymbol()
{
	return mValue;
}
void cSymbol::SetSymbol(string value)
{
	mValue = value;
}

/************************************************************************
* void SetTypeRef(string typeRef, string baseType, cDeclNode* decl = NULL);
* 		Sets the type refernece, the base, and the decl_node
************************************************************************/
void cSymbol::SetTypeRef(string typeRef, string baseType, cDeclNode* decl)
{
	mTypeRef = typeRef;
	mBaseType = baseType;
	mDecl = decl;
}
/************************************************************************
* string cSymbol::toString();
* 		Prints the value and sequence number of the symbol
************************************************************************/
string cSymbol::toString()
{
	return "sym: " + mValue + ' ' + to_string(mSequence);;
}

/************************************************************************
* bool GetIsType();
*		Returns whether it is a type
* void SetIsType(bool isType = true);
*  		Sets whether the symbol is a type
* string GetType()
* 		Returns the type
* string GetBaseType()
* 		Returns the type of the base
************************************************************************/
bool cSymbol::GetIsType()
{
	return mIsType;
}
void cSymbol::SetIsType(bool isType)
{
	mIsType = isType;
}
string cSymbol::GetType()
{
	return mTypeRef;
}
string cSymbol::GetBaseType()
{
	return mBaseType;
}

/************************************************************************
* bool GetIsDeclared();
*		Gets whether the symbol has been declared
* void SetIsDeclared(bool isDeclared = true);
* 		Sets whether the symbol has been declared
************************************************************************/
bool cSymbol::GetIsDeclared()
{
	return mIsDeclared;
}
void cSymbol::SetIsDeclared(bool isDeclared)
{
	mIsDeclared = isDeclared;
}

/************************************************************************
* cDeclNode* GetRef();
*		Returns the decl_node for the symbol
************************************************************************/
cDeclNode* cSymbol::GetRef()
{
	return mDecl;
}

/************************************************************************
* void DecrementSymbolCount();
* 		Reduces the count of total symbols
************************************************************************/
void cSymbol::DecrementSymbolCount()
{
	symbolCount--;
}
