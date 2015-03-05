/* lang.y */

%{
#include <iostream>
#include <string>
#include "lex.h"
%}

%locations

%union{
    int                 int_val;
    double              float_val;
    cSymbol*            symbol;
    cScope*             sym_table;
    cAstNode*           ast_node;
    cBlockNode*         block;
    cDeclsNode*         decls;
    cDeclNode*          decl;
    cVarDeclNode*       varDecl;
    cStructDeclNode*    structDecl;
    cArrayDeclNode*     arrayDecl;
    cFuncDeclNode*      funcDecl;
    cParamsSpecNode*    paramsSpec;
    cArraySpecNode*     arraySpec;
    cFuncCallNode*      funcCall;
    cStmtsNode*         stmts;
    cStmtNode*          stmt;
    cVarRefNode*        varRef;
    cVarPartNode*       varPart;
    cArrayValNode*      arrayVal;
    cParamNode*         param;
    cExprNode*          expr;
    }

%{
    int yyerror(const char *msg);
    int semantic_error(std::string msg);

    cBlockNode *yyast_root;
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>    INT_VAL
%token <float_val>  FLOAT_VAL

%token  ARRAY
%token  SCAN PRINT
%token  WHILE IF ELSE 
%token  STRUCT
%token  RETURN
%token  JUNK_TOKEN

%type <block> program
%type <block> block
%type <sym_table> open
%type <sym_table> close
%type <decls> decls
%type <decl> decl
%type <varDecl> var_decl
%type <structDecl> struct_decl
%type <arrayDecl> array_decl
%type <funcDecl> func_decl
%type <funcDecl> func_header
%type <funcDecl> func_prefix
%type <funcCall> func_call
%type <paramsSpec> paramsspec
%type <varDecl> paramspec
%type <arraySpec> arrayspec
%type <stmts> stmts
%type <stmt> stmt
%type <varRef> lval
%type <arrayVal> arrayval
%type <param> params
%type <expr> param
%type <expr> expr
%type <expr> term
%type <expr> fact
%type <varRef> varref
%type <varPart> varpart

%%

program: block                  { $$ = $1;
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:   open decls stmts close { $$ = new cBlockNode($2, $3); }
       | open stmts close       { $$ = new cBlockNode(NULL, $2); }
open:   '{'                     { $$ = symbolTableRoot->IncreaseScope(); }

close:  '}'                     { $$ = symbolTableRoot->DecreaseScope(); }

decls:      decls decl          { $$ = $1; 
                                  $1->AddNode($2); 
                                }
        |   decl                { $$ = new cDeclsNode($1); }

decl:       var_decl ';'        { $$ = $1; }
        |   struct_decl ';'     { $$ = $1; }
        |   func_decl           { $$ = $1; }
        |   array_decl ';'      { $$ = $1; }
        |   error ';'           { $$ = NULL; }

var_decl:   TYPE_ID IDENTIFIER 
                                { $$ = new cVarDeclNode($1, $2); }
struct_decl:  STRUCT open decls close IDENTIFIER    
                                { $$ = new cStructDeclNode($2, $3, $5); }
array_decl:   ARRAY  TYPE_ID IDENTIFIER arrayspec
                                { $$ = new cArrayDeclNode($2, $3, $4); }
func_decl:  func_header ';'
                          {
                            symbolTableRoot->DecreaseScope();
                            $$ = $1;
                          }
        |   func_header '{' decls stmts '}'
                          {
                            symbolTableRoot->DecreaseScope();
                            $$ = $1;
                            $1->SetBody($3,$4);
                          }
        |   func_header '{' stmts '}'
                          {
                            symbolTableRoot->DecreaseScope();
                            $$ = $1;
                            $1->SetBody(NULL,$3);
                          }

func_header:  func_prefix paramsspec ')' 
                          {
                            $$ = $1;
                            $1->SetParams($2);
                          }
        |     func_prefix ')'
                          { $$ = $1;
                            $1->SetParams(NULL);
                          }
func_prefix: TYPE_ID IDENTIFIER '('
                          { $$ = new cFuncDeclNode($1, $2);
                            symbolTableRoot->IncreaseScope(); 
                          }
paramsspec:     
            paramsspec',' paramspec 
                                { $$ = $1;
                                  $1->AddNode($3); 
                                }
        |   paramspec           { $$ = new cParamsSpecNode($1); }

paramspec:  var_decl            { $$ = $1;}

arrayspec:  arrayspec '[' INT_VAL ']'
                            {
                                $$ = $1;
                                $1->AddNode($3);
                            }
arrayspec:  '[' INT_VAL ']' { $$ = new cArraySpecNode($2); }

stmts:      stmts stmt          { $$ = $1; 
                                  $1->AddNode($2); 
                                }
        |   stmt                { $$ = new cStmtsNode($1); }

stmt:       IF '(' expr ')' stmt ELSE stmt
                                { $$ = new cIfNode($3, $5, $7); }
        |   IF '(' expr ')' stmt
                                { $$ = new cIfNode($3, $5, NULL); }
        |   WHILE '(' expr ')' stmt
                                { $$ = new cWhileNode($3, $5); }
        |   PRINT '(' expr ')' ';'
                                { $$ = new cPrintNode($3); }
        |   SCAN '(' lval ')' ';'
                                { $$ = new cScanNode($3); }
        |   lval '=' expr ';'   { $$ = new cAssignNode($1, $3); }
        |   func_call ';'       { $$ = new cFuncStmtNode($1); }
        |   block               { $$ = $1; }
        |   RETURN expr ';'     { $$ = new cReturnNode($2); }
        |   error ';'           { $$ = NULL; }

func_call:  IDENTIFIER '(' params ')' 
                                { $$ = new cFuncCallNode($1, $3); }
        |   IDENTIFIER '(' ')' 
                                { $$ = new cFuncCallNode($1, NULL); }
varref:   varref '.' varpart    { $$ = $1;
                                  $$->AddNode($3);
                                  if ($$->SemanticError()) YYERROR;
                                }
        | varpart               { $$ = new cVarRefNode($1); 
                                  if ($$->SemanticError()) YYERROR;
                                }

varpart:  IDENTIFIER arrayval   { $$ = new cVarPartNode($1, $2); }

lval:     varref                { $$ = $1; }
arrayval: arrayval '[' expr ']' 
                              { if ($1 == NULL)
                                  $$ = new cArrayValNode($3);
                                else 
                                {
                                  $$ = $1;
                                  $1->AddNode($3);
                                }
                              }
        |   /* empty */         { $$ = NULL; }

params:     params',' param
                                { $$ = $1;
                                  $1->AddNode($3);
                                }
        |   param               { $$ = new cParamNode($1); }

param:      expr                { $$ = $1; }

expr:       expr '+' term       { $$ = new cBinaryExprNode($1, '+', $3); }
        |   expr '-' term       { $$ = new cBinaryExprNode($1, '-', $3); }
        |   term                { $$ = $1; }

term:       term '*' fact       { $$ = new cBinaryExprNode($1, '*', $3); }
        |   term '/' fact       { $$ = new cBinaryExprNode($1, '/', $3); }
        |   term '%' fact       { $$ = new cBinaryExprNode($1, '%', $3); }
        |   fact                { $$ = $1; }

fact:        '(' expr ')'       { $$ = $2; }
        |   INT_VAL             { $$ = new cIntExprNode($1); }
        |   FLOAT_VAL           { $$ = new cFloatExprNode($1); }
        |   varref              { $$ = $1; }
        |   func_call           { $$ = $1; }

%%

int yyerror(const char *msg)
{
    std::cout << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
int semantic_error(std::string msg)
{
    std::cout << "ERROR: " << msg << " on line " << yylineno << "\n";
    
    yynerrs++;

    return 0;
}
