/***********************************************************
* Author:				Dakota Kanner
* Filename:				lang.y
************************************************************/

%{
#include <iostream>
#include "lex.h"
%}

%locations

%union{
	int             int_val;
	double          float_val;
	cAstNode*       ast_node;
	cSymbol*        symbol;
	map<string,cSymbol*>*   sym_table;
	cBlockNode*     block_node;
	cDeclNode*      decl_node;
	cDeclsNode*     decls_node;
	cExprNode*      expr_node;
	cStmtNode*      stmt_node;
	cStmtsNode*     stmts_node;
	cArraySpec*     ary_node;
	cArrayVal*      ary_val;
	cVarRef*        var_node;
	cVarPart*       var_part;
    cParamNode*     param_node;
    cParamsNode*    params_node;
    cParamsSpec*    params_spec;
    cParamSpec*     param_spec;
    cFuncCall*      func_node;
	}
	
%{
    int yyerror(string msg);
	void semantic_error(string msg);
    cAstNode *yyast_root;
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>   INT_VAL
%token <float_val> FLOAT_VAL

%token  SCAN PRINT
%token  WHILE IF ELSE 
%token  STRUCT
%token  RETURN
%token  JUNK_TOKEN
%token  ARRAY

%type <ast_node> program
%type <block_node> block
%type <sym_table> open
%type <sym_table> close
%type <decls_node> decls
%type <decl_node> decl
%type <decl_node> var_decl
%type <decl_node> struct_decl
%type <decl_node> array_decl
%type <decl_node> func_decl
%type <decl_node>  func_header
%type <symbol>  func_prefix
%type <func_node> func_call
%type <params_spec> paramsspec
%type <param_spec> paramspec
%type <ary_node> arrayspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <expr_node> lval
%type <ary_val> arrayval
%type <params_node> params
%type <param_node> param
%type <expr_node> expr
%type <expr_node> term
%type <expr_node> fact
%type <var_node> varref
%type <var_part> varpart

%%

program: block                  { $$ = $1;
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  open decls stmts close  {
									$$ = new cBlockNode($1, $2, $3);
								}
    |   open stmts close        {
									$$ = new cBlockNode($1, NULL, $2);
								}
open:   '{'                     {
									$$ = symbolTableRoot->IncreaseScope();
								}
close:  '}'                     {
									symbolTableRoot->DecreaseScope();
								}
decls:      decls decl          {
									$$ = $1;
									$$->Add($2);
								}
        |   decl                {
									$$ = new cDeclsNode();
									$$->Add($1);
								}
decl:       var_decl ';'        {
									$$ = $1;
								}
        |   struct_decl ';'     {
									$$ = $1;
								}
        |   func_decl           {
									$$ = $1;
								}
        |   array_decl ';'      {
									$$ = $1;
								}
        |   error ';'           {
									
								}
var_decl:   TYPE_ID IDENTIFIER
					{					
						if(symbolTableRoot->LookUpLocal($2->GetSymbol()) != NULL && $2->GetIsDeclared())
						{
							$$ = nullptr;
							semantic_error("Symbol " + $2->GetSymbol() + " already defined in current scope");
							YYERROR;
						}
						else
						{
							$2 = symbolTableRoot->Insert($2->GetSymbol());
							$2->SetIsDeclared();
							$$ = new cVarNode($1, $2);
							$2->SetTypeRef($1->GetType(), $1->GetBaseType(), $1->GetRef());
						}
					}
array_decl: ARRAY TYPE_ID IDENTIFIER arrayspec
					{
						if(symbolTableRoot->LookUpLocal($3->GetSymbol()) != NULL && $3->GetIsDeclared())
						{
							$$ = nullptr;
							semantic_error("Symbol " + $3->GetSymbol() + " already defined in current scope");
							YYERROR;
						}
						else
						{
							$3 = symbolTableRoot->Insert($3->GetSymbol());
							$3->SetIsType();
							$3->SetIsDeclared();
							$$ = new cArrayDecl($2, $3, $4);
							$3->SetTypeRef($3->GetSymbol(), $2->GetSymbol(), $$);
						}
					}
struct_decl:  STRUCT open decls close IDENTIFIER    
					{
						//cout << "CALLED struct_decl:  STRUCT open decls close IDENTIFIER" << endl;
						
						if(symbolTableRoot->LookUpLocal($5->GetSymbol()) != NULL && $5->GetIsDeclared())
						{
							$$ = nullptr;
							semantic_error("Symbol " + $5->GetSymbol() + " already defined in current scope");
							YYERROR;
						}
						else
						{
							$5 = symbolTableRoot->Insert($5->GetSymbol());
							$5->SetIsType();
							$5->SetIsDeclared();
							$$ = new cStructDecl($2, $3, $5);
							$5->SetTypeRef($5->GetSymbol(), $5->GetSymbol(), $$);
						}
					}
func_decl:  func_header ';'
                                {
									$$ = $1;
									symbolTableRoot->DecreaseScope();
								}
        |   func_header  '{' decls stmts '}'
                                {
									$$ = $1;
									cFuncDecl* funcDcl = dynamic_cast<cFuncDecl*>($$);
									funcDcl->SetDecls($3);
									funcDcl->SetStmts($4);
									symbolTableRoot->DecreaseScope();
								}
        |   func_header  '{' stmts '}'
                                {
									$$ = $1;
									dynamic_cast<cFuncDecl*>($$)->SetStmts($3);
									symbolTableRoot->DecreaseScope();
								}
func_header: func_prefix paramsspec ')'
                                {
									$$ = new cFuncDecl($1, $2);
								}
        |    func_prefix ')'    {
									$$ = new cFuncDecl($1);
								}
func_prefix: TYPE_ID IDENTIFIER '('
					{
						//cout << "CALLED struct_decl:  STRUCT open decls close IDENTIFIER" << endl;
						
						if(symbolTableRoot->LookUpLocal($2->GetSymbol()) && $2->GetIsDeclared())
						{
							$$ = nullptr;
							semantic_error("Symbol " + $2->GetSymbol() + " already defined in current scope");
							YYERROR;
						}
						else
						{
							$$ = symbolTableRoot->Insert($2->GetSymbol());
							$$->SetIsDeclared();
							$$->SetTypeRef($1->GetSymbol(), $1->GetSymbol(), $1->GetRef());
							symbolTableRoot->IncreaseScope();
						}
					}
paramsspec:     
            paramsspec',' paramspec 
                                {
									if($1 == nullptr)
										$1 = new cParamsSpec();
									$$ = $1;
									$$->Add($3);
								}
        |   paramspec           {
									$$ = new cParamsSpec();
									$$->Add($1);
								}

paramspec:  var_decl            {
									$$ = new cParamSpec((cVarNode*)$1);
								}

arrayspec:  arrayspec '[' INT_VAL ']'
                                {
									if($1 == NULL)
									    $1 = new cArraySpec();
									$$ = $1;
									$$->Add($3);
								}
        |   /* empty */         {
									$$ = NULL;
								}

stmts:      stmts stmt          {
									$$ = $1;
									$$->Add($2);
								}
        |   stmt                {
									$$ = new cStmtsNode();
									$$->Add($1);
								}

stmt:       IF '(' expr ')' stmt 
                                {
									$$ = new cIfNode($3, $5);
								}
        |   IF '(' expr ')' stmt ELSE stmt
                                {
									$$ = new cIfNode($3, $5, $7);
								}
        |   WHILE '(' expr ')' stmt
                                {
									$$ = new cWhileNode($3, $5);
								}
        |   PRINT '(' expr ')' ';'
                                {
									$$ = new cPrintNode($3);
								}
        |   SCAN '(' lval ')' ';'
                                {
									$$ = new cScanNode($3);
								}
        |   lval '=' expr ';'   {
		
									$$ = new cAssignmentNode((cVarRef*)$1, $3);
									if($$->GetSemanticError())
									{
										$$ = NULL;
										semantic_error("Cannot assign " + $3->GetBaseType() + " to " + $1->GetBaseType());
									}
									
								}
        |   func_call ';'       {
									$$ = $1;
								}
        |   block               {
									$$ = $1;
								}
        |   RETURN expr ';'     {
									$$ = new cReturnNode($2);
								}
        |   error ';'           {
									
								}

func_call:  IDENTIFIER '(' params ')' 
                                {
									$$ = new cFuncCall($1, $3); 
								}
varref:   varref '.' varpart    {
									if($1 == NULL)
									    $1 = new cVarRef();
									$$ = $1;
									$$->Add($3);
									if($$->GetSemanticError())
									{
										semantic_error($$->GetError());
										YYERROR;
									}
								}
        | varpart               {
									$$ = new cVarRef();
									$$->Add($1);
									if($$->GetSemanticError())
									{
										semantic_error($$->GetError());
										YYERROR;
									}
								}

varpart:  IDENTIFIER arrayval   {
									$$ = new cVarPart($1,$2);
								}

lval:     varref                {
									$$ = $1;
								}
arrayval: arrayval '[' expr ']' {
									if($1 == NULL)
									    $1 = new cArrayVal();
									$$ = $1;
									$$->Add($3);
								}
        |   /* empty */         {
									$$ = NULL;
								}

params:     params',' param     {
									if($1 == nullptr)
										$1 = new cParamsNode();
									$$ = $1;
									$$->Add($3);
								}
        |   param               {
									 $$ = new cParamsNode();
									 $$->Add($1);
								}

param:      expr                {
									$$ = new cParamNode($1);
								}
        |   /* empty */         {
									$$ = NULL;
								}

expr:       expr '+' term       {
									$$ = new cBinaryExpr($1, '+', $3);
								}
        |   expr '-' term       {
									$$ = new cBinaryExpr($1, '-', $3);
								}
        |   term                {
									$$ = $1;
								}

term:       term '*' fact       {
									$$ = new cBinaryExpr($1, '*', $3);
								}
        |   term '/' fact       {
									$$ = new cBinaryExpr($1, '/', $3);
								}
        |   term '%' fact       {
									$$ = new cBinaryExpr($1, '%', $3);
								}
        |   fact                {
									$$ = $1;
								}

fact:        '(' expr ')'       {
									$$ = $2;
								}
        |   INT_VAL             {
									$$ = new cIntExpr($1);
								}
        |   FLOAT_VAL           {
									$$ = new cFloatExpr($1);
								}
        |   varref              {
									$$ = $1;
								}
        |   func_call           {
									$$ = $1;
								}

%%

int yyerror(string msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

void semantic_error(string msg)
{
    std::cout << "ERROR: " << msg << 
                 " on line " << yylineno << std::endl;

    yynerrs++;
}
