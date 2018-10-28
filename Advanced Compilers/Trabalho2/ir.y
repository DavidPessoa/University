	%{
	#include <stdio.h>
	#include <stdlib.h>
  #include "tradutor.h"

	extern int yylineno;
	int yylex(void);				
	void yyerror(const char *);		
%}

%error-verbose  

%union{
	int num;
  char *name;
  double real;
  struct Function *function;
  struct MoreFunctions *moreFunctions;
  struct Body *body;
  struct MoreExpressions *moreExpressions;
  struct Expression *expression;
  struct Id *id;
  struct Args *args;
  struct Op *op;
  struct JLabel *jLabel;
  struct Type *type;
  struct Declaration *declaration;
  struct DeclType *declType;
  struct DeclArgs *declArgs;
  struct InitialValue *initialValue;
  struct Arguments *arguments;
  struct MoreArgDecl *moreArgDecl;
  struct MoreDeclarations *moreDeclarations;
  struct BoolVal *boolVal;

}


%token <num> NUM
%token <real> REAL
%token <name> NAME
%token FUNCTION
%token AT
%token TEMP
%token ARROW
%token COMMA
%token JUMP
%token RETURN
%token FP
%token A
%token G 
%token L
%token PARRE
%token PARRD
%token VALUE
%token LSTORE
%token ASTORE
%token GSTORE
%token LLOAD
%token ALOAD
%token GLOAD
%token MUL 
%token SUB
%token ADD
%token DIV
%token MOD
%token INV
%token EQ
%token LT
%token ITOR
%token NOT
%token COPY
%token CJUMP
%token CALL
%token I
%token T
%token R
%token TWODOT
%token PRINT  
%token FUN
%token VOID
%token ID
%token INT
%token VAR
%token PARD
%token PARE
%token REALTYPE
%token B
%token BOOL
%token TRUE
%token FALSE
%token NE
%token LE

%type <function> function
%type <moreFunctions> moreFunctions
%type <body> body
%type <moreExpressions> moreExpressions
%type <expression> expression
%type <id> id
%type <args> args
%type <op> op
%type <jLabel> jLabel
%type <type> type
%type <declaration> declaration
%type <declType> declType
%type <declArgs> declArgs
%type <initialValue> initialValue
%type <arguments> arguments
%type <moreArgDecl> moreArgDecl
%type <moreDeclarations> moreDeclarations
%type <boolVal> boolVal


%% 

program: function   {root($1);};
       
function: moreFunctions {$$ = newFunction(moreFuncs, $1, NULL);};
        | moreDeclarations   {$$ = newFunction(declaration, NULL , $1);};
;

moreDeclarations: PARE declaration PARD             {$$ = newMoreDeclarations(single, $2 , NULL);};
                | PARE declaration PARD function    {$$ = newMoreDeclarations(more, $2 , $4);};

declaration:  ID NAME FUN declType PARRE declArgs PARRD PARRE declArgs PARRD    {$$ = newDeclaration(fun, $2, $4, $6, $9, NULL, NULL);};
           |  ID NAME VAR declType initialValue                            {$$ = newDeclaration(var, $2, $4, NULL, NULL, $5, NULL);};
           |  ID NAME VAR BOOL boolVal                                    {$$ = newDeclaration(boolVal_, $2, NULL, NULL, NULL, NULL, $5);};
;


declType: INT                     {$$ = newDeclType(int_);};
        | VOID                    {$$ = newDeclType(void_);};
        | REALTYPE                {$$ = newDeclType(realtype);}; 
;

boolVal: TRUE                    {$$ = newBoolVal(true_);}; 
        | FALSE                  {$$ = newBoolVal(false_);};
        |                        {$$ = newBoolVal(anotherEmpty);}; 

initialValue: NUM                 {$$ = newInitialValue(num_,$1, 0.0);};
            | REAL                {$$ = newInitialValue(real_, 0, $1);};
            |                     {$$ = newInitialValue(empty_, 0, 0.0);};
;

declArgs: arguments               {$$ = newDeclArgs(arguments_, $1);};
        |                         {$$ = newDeclArgs(empty__, NULL);};
        ;

arguments: PARE moreArgDecl   {$$ = newArguments($2);};

moreArgDecl:  declType NAME PARD               {$$ = newMoreArgDecl(simple, $1, $2, NULL);};
            | declType NAME PARD arguments       {$$ = newMoreArgDecl(complex, $1, $2, $4);};
            ;



moreFunctions: FUNCTION NAME body   {$$ = newMoreFunctions(simpleFunction_, $3, NULL, $2);};
              | FUNCTION NAME body function {$$ = newMoreFunctions(moreFunctions_, $3, $4, $2);};

body: jLabel expression {$$ = newBody(label, $1, $2, NULL);};
    | moreExpressions {$$ = newBody(moreExpressions, NULL, NULL, $1);};
;

moreExpressions: jLabel expression body {$$ = newMoreExpressions($1, $2, $3);};

expression: id ARROW type op args                             {$$ = newExpression(op, $1, $3, $4, $5, 0, 0, NULL);};
          | CJUMP id COMMA L NUM COMMA L NUM                  {$$ = newExpression(cjump, $2, NULL, NULL, NULL, $5, $8, NULL);};
          | JUMP L NUM                                        {$$ = newExpression(jump, NULL, NULL, NULL, NULL, $3, 0, NULL);};
          | id ARROW ITOR args                                {$$ = newExpression(itor, $1, NULL, NULL, $4, 0, 0, NULL);};
          | id ARROW NOT args                                 {$$ = newExpression(not_, $1, NULL, NULL, $4, 0, 0, NULL);};
          | type RETURN args                                  {$$ = newExpression(complexReturn, NULL, $1, NULL, $3, 0, 0, NULL);};
          | id ARROW type CALL NAME COMMA PARRE args PARRD    {$$ = newExpression(complexCall, $1, $3, NULL, $8, 0, 0, $5);};
          | RETURN                                            {$$ = newExpression(simpleReturn, NULL, NULL, NULL, NULL, 0, 0, NULL);};
          | CALL NAME COMMA PARRE args PARRD                  {$$ = newExpression(simpleCall, NULL, NULL, NULL, $5, 0, 0, $2);};
          | type PRINT args                                   {$$ = newExpression(print, NULL, $1, NULL, $3, 0, 0, NULL);};
          | id ARROW MOD args                             {$$ = newExpression(mod, $1, NULL, NULL, $4, 0, 0, NULL);};
          | CALL NAME COMMA PARRE  PARRD                  {$$ = newExpression(simpleCallNoArgs, NULL, NULL, NULL, NULL, 0, 0, $2);};
          | id ARROW type CALL NAME COMMA PARRE PARRD    {$$ = newExpression(complexCall, $1, $3, NULL, NULL, 0, 0, $5);};

          ;

id: T NUM    {$$ = newId(temp, $2, NULL);};
  | FP NUM   {$$ = newId(floatingPoint, $2, NULL);};
  | NAME     {$$ = newId(name, 0, $1);};
;

args: id              {$$ = newArgs(simpleId, $1, NULL, 0, 0);};
    | id COMMA args    {$$ = newArgs(complexId, $1, $3, 0, 0);};
    | NUM             {$$ = newArgs(num, NULL, NULL, $1, 0);};
    | REAL            {$$ = newArgs(real, NULL, NULL, 0, $1);};
;

op: SUB        {$$ = newOp(sub);};
   | MUL       {$$ = newOp(mul);};
   | ADD       {$$ = newOp(add);};
   | DIV       {$$ = newOp(div_);};
   | LT        {$$ = newOp(lt);};
   | EQ        {$$ = newOp(eq);};
   | LSTORE    {$$ = newOp(lstore);};
   | ASTORE    {$$ = newOp(astore);};
   | GSTORE    {$$ = newOp(gstore);};
   | ALOAD     {$$ = newOp(aload);};
   | GLOAD     {$$ = newOp(gload);};
   | LLOAD     {$$ = newOp(lload);};
   | VALUE     {$$ = newOp(value);};
   | COPY      {$$ = newOp(copy);};
   | NE        {$$ = newOp(ne);};
   | LE        {$$ = newOp(le);};
   | INV        {$$ = newOp(inv);};
   ;



jLabel: L NUM TWODOT    {$$ = newJLabel(label_, $2);};
      |                 {$$ = newJLabel(empty, 0);};
      ;
          
type: I     {$$ = newType(i);};
    | R     {$$ = newType(r);};
    | B     {$$ = newType(b);};
;


%%

void yyerror(const char *msg){
	fprintf(stderr, "error: %s\n", msg);
}


int main(){
	return yyparse();
}

