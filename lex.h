#pragma once
//*******************************************************
// Purpose: include all AST nodes, parser globals and scanner globals
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include "cAstNode.h"
#include "cBlockNode.h"
#include "cIntExprNode.h"
#include "cFloatExprNode.h"
#include "cBinaryExprNode.h"
#include "cPrintNode.h"
#include "cScanNode.h"
#include "cReturnNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cVarDeclNode.h"
#include "cStructDeclNode.h"
#include "cArrayDeclNode.h"
#include "cVarRefNode.h"
#include "cVarPartNode.h"
#include "cIfNode.h"
#include "cWhileNode.h"
#include "cAssignNode.h"
#include "cFuncDeclNode.h"
#include "cFuncCallNode.h"
#include "cFuncStmtNode.h"
#include "cParamsSpecNode.h"
#include "cParamNode.h"
#include "cArraySpecNode.h"
#include "cArrayValNode.h"

#include "langparse.h"

#include "parse.h"

int yylex();

extern char *yytext;
extern int yylineno;
extern int yynerrs;
extern FILE *yyin;
