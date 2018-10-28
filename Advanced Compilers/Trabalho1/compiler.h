#include <stdio.h>
#include <string.h>
#include "tree.h"


void root(Gdeclpar *root);

void nodeGdeclpar(Gdeclpar *root);
void nodeMoreGdecl(More_Gdecl *root);
void nodeGdecl(Gdecl *root);
void nodeVar(Var *root);
void nodeFunction(Function *root);
void nodeBody(Body *root);
void nodeFormalArg(Formal_Arg *root);
void nodeMoreFormalArg(More_Formal_Arg *root);
void nodeOp(OP *root);
void nodeStatementpar(Statementpar *root);
void nodeStatement(Statement *root);
void nodeMoreStatements(More_Statements *root);
void nodeExpression2(Expression2 *root);
void nodeMoreExpressions(More_Expressions *root);
void nodeExpression(Expression *root);
void nodeMoreDecl(More_Decl *root);
void nodeDeclaration(Declaration *root);
void nodeBoolVal(Bool_Val *root);
void nodeScope(Scope *root);
void nodeType(Type *root);