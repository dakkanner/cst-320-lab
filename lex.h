/***********************************************************
* Author:				Dakota Kanner
* Filename:				lex.h
************************************************************/
#pragma once
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "cAstNode.h"
#include "cDeclsNode.h"
#include "cDeclNode.h"
#include "cStmtsNode.h"
#include "cStmtNode.h"
#include "cBlockNode.h"
#include "cPrintNode.h"
#include "cIntExpr.h"
#include "cFloatExpr.h"
#include "cBinaryExpr.h"
#include "cVarRef.h"
#include "cVarPart.h"
#include "cVarNode.h"
#include "cArraySpec.h"
#include "cArrayVal.h"
#include "cScanNode.h"
#include "cIfNode.h"
#include "cReturnNode.h"
#include "cWhileNode.h"
#include "cAssignmentNode.h"
#include "cStructDecl.h"
#include "cParamNode.h"
#include "cParamSpec.h"
#include "cParamsNode.h"
#include "cParamsSpec.h"
#include "cFuncPrefix.h"
#include "cFuncHeader.h"
#include "cFuncDecl.h"
#include "cFuncCall.h"
#include "langparse.h"

extern int yyparse();
extern int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;
extern cSymbolTable *symbolTableRoot;
