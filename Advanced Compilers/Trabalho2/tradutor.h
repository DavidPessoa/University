#include <stdio.h>
#include <string.h>
#include "tree.h"


void root(Function *root);
void nodeFunction(Function *root);
void nodeMoreDeclarations(MoreDeclarations *root);
void nodeDeclaration(Declaration *root);
void nodeDeclType(DeclType *root);
void nodeInitialValue (InitialValue *root);
void nodeDeclArgs(DeclArgs *root, int flag);
void nodeArguments(Arguments *root, int flag);
void nodeMoreArgDecl(MoreArgDecl *root, int flag);
void nodeMoreFunctions(MoreFunctions *root);
void nodeBody(Body *root);
void nodeMoreExpressions(MoreExpressions *root);
void nodeExpression(Expression *root);
void nodeId(Id *root);
void nodeArgs(Args *root);
void nodeOp (Op *root);
void nodeJLabel(JLabel *root);
void nodeType(Type *root);
void printMoreFunctions(MoreFunctions *root);
void printBody(Body *root);
void printExpression (Expression *root);
void getIDs(Args *root);
int tempValueSearch(int val);
int containsId(Args *root, int val);