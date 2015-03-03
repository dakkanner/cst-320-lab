//*******************************************************
// Purpose: main program for lang compiler
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "lex.h"

extern cAstNode *yyast_root;

int main(int argc, char **argv)
{
    std::cout << "Philip Howard" << std::endl;

    const char *outfile_name;
    int result = 0;
    std::streambuf *cout_buf = std::cout.rdbuf();

    // setup input file from argv[1]
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            std::cout << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    // setup output file from argv[2]
    if (argc > 2)
    {
        outfile_name = argv[2];
    } else {
        outfile_name = "/dev/tty";
    }

    std::ofstream output(outfile_name);
    if (!output.is_open())
    {
        std::cout << "ERROR: Unable to open file " << outfile_name << "\n";
        exit(-1);
    }

    // redirect cout to the output file
    std::cout.rdbuf(output.rdbuf());

    symbolTableRoot = cSymbolTable::CreateDefaultTable();
    result = yyparse();
    if (result == 0)
    {
        std::cout << yyast_root->toString() << std::endl;
    } else {
        std::cout << yynerrs << " Errors in compile" << std::endl;
    }

    // clean up cout so it points back to standard location
    output.close();
    std::cout.rdbuf(cout_buf);

    return result;
}
