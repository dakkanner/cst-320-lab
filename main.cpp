// parser
//
// Dakota Kanner
//
// Dakota.Kanner@oit.edu

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

//#include "cSymbolTable.h"
#include "lex.h"
//#include "cAstNode.h"
//#include "cProgramNode.h"
//#include "langparse.h"

extern cAstNode *yyast_root;
cSymbolTable * symbolTableRoot;

int main(int argc, char **argv)
{
    symbolTableRoot = cSymbolTable::GetInstance();
	
    std::cout << "Dakota Kanner" << std::endl;

    const char *outfile_name;
    int result = 0;
    std::streambuf *cout_buf = std::cout.rdbuf();

    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    if (argc > 2)
    {
        outfile_name = argv[2];
    } else {
        outfile_name = "/dev/tty";
    }

    std::ofstream output(outfile_name);
    if (!output.is_open())
    {
        std::cerr << "ERROR: Unable to open file " << outfile_name << "\n";
        exit(-1);
    }
    std::cout.rdbuf(output.rdbuf());

    result = yyparse();
    if (yyast_root != NULL)
    {
        if (result == 0)
        {
            output << yyast_root->toString() << std::endl;
        } else {
            output << "Errors in compile\n";
            return result;
        }
    }

    if (yylex() != 0)
    {
        std::cout << "Junk at end of program\n";
    }

    output.close();
    std::cout.rdbuf(cout_buf);

    return result;
}
