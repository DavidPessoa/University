	%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "compiler.h"

	extern int yylineno;
	int yylex(void);				
	void yyerror(const char *);		
%}

%error-verbose  

%union{
	int integer;
    double real;
    char *name;
    char *id;
    struct Gdeclpar *gdeclpar;
    struct More_Gdecl *more_gdecl;
    struct Gdecl *gdecl;
    struct Var *var;
    struct Function *function;
    struct Body *body;
    struct Formal_Arg *formal_arg;
    struct More_Formal_Arg *more_formal_arg;
    struct OP *op;
    struct Statementpar *statementpar;
    struct Statement *statement;
    struct More_Statements *more_statements;
    struct Expression2 *expression2;
    struct Expression *expression;  
    struct Expression *expression1;  
    struct More_Expressions *more_expressions;
    struct More_Decl *more_decl;
    struct Declaration *declaration;
    struct Bool_Val *bool_val;
    struct Scope *scope;
    struct Type *type;
    

}

%token <integer> INTEGER
%token <name> NAME
%token ID
%token PARRE PARRD PARE PARD COMMA SEMICOLON TWODOT DOT
%token VAR
%token LOCAL
%token ARG
%token FUN
%token BODY
%token CALL
%token PRINT
%token IF
%token WHILE
%token OR
%token AND 
%token EQ
%token NE
%token LT
%token LE
%token GT
%token GE
%token PLUS 
%token MINUS
%token TIMES
%token DIV
%token MOD
%token NOT
%token INV
%token INT_LITERAL
%token REAL_LITERAL
%token TRUE
%token FALSE
%token TOREAL
%token INT
%token <real> REAL 
%token BOOL
%token ASSIGN
%token NIL

%type <gdeclpar> gdeclpar
%type <more_gdecl> more_gdecl
%type <gdecl> gdecl
%type <var> var
%type <function> function
%type <body> body
%type <formal_arg> formal_arg
%type <more_formal_arg> more_formal_arg
%type <op> op
%type <statementpar> statementpar
%type <statement> statement
%type <more_statements> more_statements
%type <expression2> expression2
%type <expression> expression
%type <more_expressions> more_expressions
%type <more_decl> more_decl
%type <declaration> declaration
%type <bool_val> bool_val
%type <scope> scope
%type <type> type 


%% 

program: gdeclpar  						 {root($1);};   


gdeclpar: PARE gdecl PARD  				{$$ = newGdeclpar(pare_gdecl, $2, NULL);};
		| more_gdecl					{$$ = newGdeclpar(more_gdecl_, NULL, $1);};
		

more_gdecl: gdeclpar PARE gdecl PARD    {$$ = newMore_Gdecl($1, $3);};


gdecl: function						 {$$ = newGdecl(function, $1, NULL);};	
	 | var   						 {$$ = newGdecl(var, NULL, $1);};


var: VAR PARE ID NAME VAR type PARD more_expressions   {$$ = newVar(var_exp, $4, $6, $8);};
   | VAR PARE ID NAME VAR type PARD NIL				   {$$ = newVar(var_nil, $4, $6, NULL);};


//DECLARATION PODE SER VAZIO, SUBSTITUIR [] POR [EMPTY- DECLARATION]
function: FUN NAME PARRE more_formal_arg PARRD PARE BODY PARRE more_decl PARRD body PARD      {$$ = newFunction($2, $4, $9, $11);};


body: statementpar more_expressions    {$$ = newBody(statement_expression, $1, $2);};
    | NIL more_expressions				{$$ = newBody(nil_expression, NULL, $2);};
    | statementpar NIL 					{$$ = newBody(statement_nil, $1, NULL);};

			  
formal_arg: ARG NAME type 				{$$ = newFormalArg($2, $3);};	  


more_formal_arg: PARE formal_arg PARD more_formal_arg 	{$$ = newMoreFormalArg(formal_more_formal, $2, $4);};  
		       |										{$$ = newMoreFormalArg(empty_more_decl, NULL, NULL);}; 


op: OR 			{$$ = newOP(or_);};
  | AND 		{$$ = newOP(and_);};
  | EQ 			{$$ = newOP(eq_);};
  | NE 			{$$ = newOP(ne_);};
  | LT 			{$$ = newOP(lt_);};
  | LE  		{$$ = newOP(le_);};
  | GT 			{$$ = newOP(gt_);};
  | GE 			{$$ = newOP(ge_);};
  | PLUS      	{$$ = newOP(plus_);};
  | MINUS 		{$$ = newOP(minus_);};
  | TIMES 		{$$ = newOP(times_);};
  | DIV 		{$$ = newOP(div_);} ;
  | MOD	 		{$$ = newOP(mod_);};
  | NOT  		{$$ = newOP(not_);};
  | INV 		{$$ = newOP(inv_);};


statementpar: PARE statement PARD          		{$$ = newStatementPar(par_statement, $2, NULL );};
			| PARRE more_statements PARRD 		{$$ = newStatementPar(more_statement, NULL, $2 );};
		 	| NIL 								{$$ = newStatementPar(nil, NULL, NULL );};			


statement: ASSIGN PARE ID NAME scope type PARD more_expressions  	{$$ = newStatement(assign, $5, $8, NULL, NULL, $4, NULL, $6);};
		 | WHILE more_expressions  statementpar  					{$$ = newStatement(while_, NULL, $2, $3, NULL, NULL, NULL, NULL);};
		 | IF more_expressions statementpar statementpar  			{$$ = newStatement(if_, NULL, $2, $3, $4, NULL, NULL, NULL);};
		 | CALL NAME more_expressions 	  							{$$ = newStatement(call_proc, NULL, $3, NULL, NULL, $2, NULL, NULL);};
		 | PRINT expression 										{$$ = newStatement(print, NULL, NULL, NULL, NULL, NULL, $2, NULL);};


more_statements:  statementpar PARE statement PARD                  {$$ = newMoreStatements(statement_statement, $1, $3,NULL);};
				| statementpar more_statements    				    {$$ = newMoreStatements(statement_more_statement, $1, NULL, $2);};	
    

expression2: expression 								    		{$$ = newExpression2(exp_, $1);}			
		   | 													    {$$ = newExpression2(empty_exp2, NULL);};


more_expressions: PARRE  expression expression2 PARRD 				{$$ = newMoreExpressions(exp_exp, $2, $3);};
				| expression  										{$$ = newMoreExpressions(m_exp, $1, NULL);};


expression: PARE op expression expression PARD TWODOT type 			{$$ = newExpression(op, $2, $3, NULL, $7, NULL, 0, 0.0, NULL, NULL, NULL, NULL, $4);};
		  | PARE INT_LITERAL INTEGER PARD TWODOT type  				{$$ = newExpression(int_literal, NULL, NULL, NULL, $6, NULL, $3, 0.0, NULL, NULL, NULL, NULL, NULL);};
		  | PARE REAL_LITERAL REAL PARD TWODOT type  				{$$ = newExpression(real_literal, NULL, NULL, NULL, $6, NULL, 0, $3, NULL, NULL, NULL, NULL, NULL);};
		  | PARE BOOL bool_val PARD TWODOT type   					{$$ = newExpression(bool_exp, NULL, NULL, NULL, $6, NULL, 0, 0.0, $3, NULL, NULL, NULL, NULL);};
		  | PARE ID NAME scope type PARD TWODOT type   				{$$ = newExpression(id, NULL, NULL, NULL, $5, $8, 0, 0.0, NULL, $4, NULL, $3, NULL);};
		  | PARE CALL NAME more_expressions PARD TWODOT type 		{$$ = newExpression(call_func, NULL, NULL, NULL, $7, NULL, 0, 0.0, NULL, NULL, $4, $3, NULL);};
		  | PARE TOREAL expression PARD TWODOT type  				{$$ = newExpression(toreal, NULL, $3, NULL, $6, NULL, 0, 0.0, NULL, NULL, NULL, NULL, NULL);};
		  | TOREAL expression  										{$$ = newExpression(toreal, NULL, $2, NULL, NULL, NULL, 0, 0.0, NULL, NULL, NULL, NULL, NULL);};
	 	

more_decl: PARE declaration PARD more_decl 							{$$ = newMoreDecl(more_gdecl, $2, $4);};
		 |  														{$$ = newMoreDecl(empty_more_decl, NULL, NULL);};
		 

declaration: scope NAME type NIL     								{$$ = newDeclaration(decl_nil, $1, $2, $3, NULL);};
		   | scope NAME type more_expressions  						{$$ = newDeclaration(decl_more_expressions, $1, $2, $3, $4);};
		   | 														{$$ = newDeclaration(empty_decl, NULL, NULL, NULL, NULL);};


bool_val: TRUE  													{$$ = newBoolVal(true_);};
		| FALSE 													{$$ = newBoolVal(false_);};
		

scope: LOCAL 														{$$ = newScope(local_scope);};
	 | VAR 															{$$ = newScope(var_scope);};
	 | ARG 															{$$ = newScope(arg_scope);};


type: INT  															{$$ = newType(int_type);};
	| BOOL 															{$$ = newType(bool_type);};
	| REAL 															{$$ = newType(real_type);};


%%

void yyerror(const char *msg){
	fprintf(stderr, "error: %s\n", msg);
}


int main(){
	return yyparse();
}

