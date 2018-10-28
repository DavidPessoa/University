#include "tree.h"



Function *newFunction(FunctionType type, MoreFunctions *moreFunctions, MoreDeclarations *moreDeclarations){
	Function *s = malloc(sizeof(Function));
	s->type = type;
	s->moreFunctions = moreFunctions;
	s->moreDeclarations = moreDeclarations;
	return s;
}

MoreDeclarations *newMoreDeclarations(ModeDeclarationsType type, Declaration *declaration, Function *function){
	MoreDeclarations *s = malloc(sizeof(MoreDeclarations));
	s->type = type;
	s->declaration = declaration;
	s->function = function;
	return s;
}

Declaration *newDeclaration(DeclarationType type, char *name, DeclType *declType, DeclArgs *declArgs1, DeclArgs *declArgs2, InitialValue *initialValue, BoolVal *boolVal){
	Declaration *s = malloc(sizeof(Declaration));
	s->type = type;
	s->name = name;
	s->declType = declType;
	s->declArgs1 = declArgs1;
	s->declArgs2 = declArgs2;
	s->initialValue = initialValue;
	s->boolVal = boolVal;
	return s;
}

DeclType *newDeclType(DeclTypeType type){
	DeclType *s = malloc(sizeof(DeclType));
	s->type = type;
	return s;
}

BoolVal *newBoolVal(BoolValType type){
	BoolVal *s = malloc(sizeof(BoolVal));
	s->type = type;
	return s;
}

InitialValue *newInitialValue(InitialValueType type, int num, double real){
	InitialValue *s = malloc(sizeof(InitialValue));
	s->type = type;
	s->num = num;
	s->real = real;
	return s;
}

DeclArgs *newDeclArgs(DeclArgsType type, Arguments *arguments){
	DeclArgs *s = malloc(sizeof(DeclArgs));
	s->type = type;
	s->arguments = arguments;
	return s;
}

Arguments *newArguments(MoreArgDecl *moreArgDecl){
	Arguments *s = malloc(sizeof(Arguments));
	s->moreArgDecl = moreArgDecl;
	return s;
}

MoreArgDecl *newMoreArgDecl(MoreArgDeclType type, DeclType *declType, char *name, Arguments *arguments){
	MoreArgDecl *s = malloc(sizeof(MoreArgDecl));
	s->type = type;
	s->declType = declType;
	s->name = name;
	s->arguments = arguments;
	return s;
}


MoreFunctions *newMoreFunctions(MoreFunctionsType type, Body *body, Function *function, char *name){
	MoreFunctions *s = malloc(sizeof(MoreFunctions));
	s->type = type;
	s->body = body;
	s->function = function;
	s->name = name;
	return s;
}

Body *newBody(BodyType type, JLabel *jLabel, Expression *expression, MoreExpressions *moreExpressions){
	Body *s = malloc(sizeof(Body));
	s->type = type;
	s->jLabel = jLabel;
	s->expression = expression;
	s->moreExpressions = moreExpressions;
	return s;
}

MoreExpressions *newMoreExpressions(JLabel *jLabel, Expression *expression, Body *body){
	MoreExpressions *s = malloc(sizeof(MoreExpressions));
	s->jLabel = jLabel;
	s->expression = expression;
	s->body = body;
	return s;
}

Expression *newExpression(ExpressionType type, Id *id, Type *typeNode, Op *op, Args *args, int num1, int num2, char *name){
	Expression *s = malloc(sizeof(Expression));
	s->type = type;
	s->id = id;
	s->typeNode = typeNode;
	s->op = op;
	s->args = args;
	s->num1 = num1;
	s->num2 = num2;
	s->name = name;
	return s;
}

Id *newId(IdType type, int num, char *name){
	Id *s = malloc(sizeof(Id));
	s->type = type;
	s->num = num;
	s->name = name;
	return s;
}

Args *newArgs(ArgsType type, Id *id1, Args *args, int num, double real){
	Args *s = malloc(sizeof(Args));
	s-> type = type;
	s->id1 = id1;
	s->num = num;
	s->real = real;
	s->args = args; 
	return s;
}

Op *newOp(OpType type){
	Op *s = malloc(sizeof(Op));
	s->type = type;
	return s;
}

JLabel *newJLabel(JLabelType type, int num){
	JLabel *s = malloc(sizeof(JLabel));
	s->type = type;
	s->num = num;
	return s;
}

Type *newType(TypeType type){
	Type *s = malloc(sizeof(Type));
	s->type = type;
	return s;
}