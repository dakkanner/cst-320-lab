#pragma once
//*******************************************************
// Purpose: a symbol e.g. variable, type, etc.
//
// Author: Dakota Kanner
// Email:  Dakota.Kanner@oit.edu
// Original author: Phil Howard, phil.howard@oit.edu
//
// Date: 3/4/2015
//
//*******************************************************

#include <string>
#include "cAstNode.h"
#include "cDeclNode.h"

class cSymbol
{
    public:
        // create a Symbol for the given name n
        cSymbol(std::string n) 
        {
            name = n; 
            sequence = ++totalSymbols;
            mType = NULL;
        }

        // return the name of the symbol
        std::string Name() {return name;}

        // Indicate what type of thing this symbol is
        void SetType(cDeclNode *type)
        { mType = type; }

        // return the declaration of this symbol
        cDeclNode *GetType()
        { return mType; }

        // return a string representation of the symbol
        virtual std::string toString()
        {
            std::string result("sym: ");
            result += name + " ";
            result += std::to_string(static_cast<long long>(sequence));

            return result;
        }
	
		//virtual int ComputeOffsets(int base)
		//{
		//	int result(base);
		//	result = mType->ComputeOffsets(result);
		//	return result;
		//}

    protected:
        std::string name;           // name of the symbol
        int sequence;               // unique ID for symbol
        cDeclNode *mType;           // Declaration of this ID
        static int totalSymbols;    // STATIC: keeps track of total number of
                                    // symbols that have been created. Used
                                    // to assign sequence: unique ID
};
