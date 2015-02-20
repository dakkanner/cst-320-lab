/***********************************************************
* Author:				Dakota Kanner
* Filename:				cSymbol.h
************************************************************/ 

#ifndef C_SYMBOL_H
#define C_SYMBOL_H

#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "cAstNode.h"
#include "cDeclNode.h"

/************************************************************************
* cSymbol(string value, bool isType = false);
*		C'tor (with params)
*
* string cSymbol::toString();
* 		Prints the value and sequence number of the symbol
*
* string GetSymbol();
* 		Getter for the symbol name
* void SetSymbol(string value);
*		Setter for the symbol name
*
* void SetTypeRef(string typeRef, string baseType, cDeclNode* decl = NULL);
* 		Sets the type refernece, the base, and the decl_node
*
* bool GetIsType();
*		Returns whether it is a type
* void SetIsType(bool isType = true);
*  		Sets whether the symbol is a type
* string GetType()
* 		Returns the type
* string GetBaseType()
* 		Returns the type of the bas
* bool GetIsDeclared();
*		Gets whether the symbol has been declared
* void SetIsDeclared(bool isDeclared = true);
* 		Sets whether the symbol has been declared
* cDeclNode* GetRef();
*		Returns the decl_node for the symbol
* void DecrementSymbolCount();
* 		Reduces the count of total symbols
************************************************************************/
class cSymbol
{
public:
	cSymbol(string value, bool isType = false);
	
	virtual string toString();
	virtual string GetType();
	virtual string GetBaseType();
	
	string GetSymbol();
	void SetSymbol(string value);
	void SetTypeRef(string typeRef, string baseType, cDeclNode* decl = NULL);
	bool GetIsType();
	void SetIsType(bool isType = true);
	bool GetIsDeclared();
	void SetIsDeclared(bool isDeclared = true);
	cDeclNode* GetRef();
	void DecrementSymbolCount();

private:
	int mSequence; 	  // Unique integer identifier of symbol
	string mValue;	  // Value of symbol
	bool mIsType; 	  // True if this is a type
	bool mIsDeclared; // True if this is declared
	string mTypeRef;  // Reference for the type of the symbol
	string mBaseType;
	cDeclNode* mDecl;
	static int symbolCount;
};

#endif