#include "tree.h"


Gdeclpar *newGdeclpar( Gdeclpar_Type enum_type ,Gdecl *gdecl, More_Gdecl *more_gdecl){
	Gdeclpar *s = malloc(sizeof(Gdeclpar));
	s->enum_type = enum_type;
	s->gdecl = gdecl;
	s->more_gdecl = more_gdecl;
	return s;
}

More_Gdecl *newMore_Gdecl(Gdeclpar *gdeclpar ,Gdecl *gdecl){
	More_Gdecl *s = malloc(sizeof(more_gdecl));
	s->gdeclpar = gdeclpar;
	s->gdecl = gdecl;
	return s;
}

Gdecl *newGdecl(Gdecl_Type enum_type, Function *function, Var *var){
	Gdecl *s = malloc(sizeof(Gdecl));
	s->enum_type = enum_type;
	s->function = function;
	s->var = var;
	return s;	
}

Var *newVar(Var_Type enum_type, char *name, Type *type, More_Expressions *more_expressions){
	Var *s = malloc(sizeof(Var));
	s->enum_type = enum_type;
	s->name = name;
	s->type = type;
	s->more_expressions = more_expressions;
	return s;
}

Function *newFunction (char *name, More_Formal_Arg *more_formal_arg, More_Decl *more_decl, Body *body){
	Function *s = malloc(sizeof(Function));
	s->name = name;
	s-> more_formal_arg = more_formal_arg;
	s->more_decl = more_decl;
	s->body = body;
	return s;
}

Body *newBody(Body_Type enum_type, Statementpar *statementpar, More_Expressions *more_expressions){
	Body *s = malloc(sizeof(Body));
	s->enum_type = enum_type;
	s->statementpar = statementpar;
	s->more_expressions = more_expressions;
	return s;
}


Formal_Arg *newFormalArg(char *name, Type *type){
	Formal_Arg *s = malloc(sizeof(Formal_Arg));
	s->name = name;
	s->type = type;
	return s;
}

More_Formal_Arg *newMoreFormalArg(More_formal_arg_Type enum_type, Formal_Arg *formal_arg, More_Formal_Arg *more_formal_arg){
	More_Formal_Arg *s = malloc(sizeof(More_Formal_Arg));
	s->enum_type = enum_type;
	s->formal_arg = formal_arg;
	s->more_formal_arg = more_formal_arg;
	return s;
}

OP *newOP(OP_Type enum_type){
	OP *s = malloc(sizeof(OP));
	s->enum_type = enum_type;
	return s;
}

Statementpar *newStatementPar(Statementpar_Type enum_type, Statement *statement, More_Statements *more_statements){
	Statementpar *s = malloc(sizeof(Statementpar));
	s->enum_type = enum_type;
	s->statement = statement;
	s->more_statements = more_statements;
	return s;
}

Statement *newStatement(Statement_Type enum_type, Scope *scope, More_Expressions *more_expressions, Statementpar *statementpar, Statementpar *statementpar2, char *name, Expression *expression, Type *type){
	Statement *s = malloc(sizeof(Statement));
	s->enum_type = enum_type;
	s->scope = scope;
    s->more_expressions = more_expressions;
    s->statementpar = statementpar;
    s->statementpar2 = statementpar2;
    s->name = name;
    s->expression = expression;
    s->type = type;
    return s;
}

More_Statements *newMoreStatements(More_Statements_Type enum_type, Statementpar *statementpar, Statement *statement, More_Statements *more_statements){
	More_Statements *s = malloc(sizeof(More_Statements));
	s->enum_type = enum_type;
	s->statementpar = statementpar;
	s->statement = statement;
	s->more_statements = more_statements;
	return s;
}

Expression2 *newExpression2(Expression2_Type enum_type, Expression *expression){
	Expression2 *s = malloc(sizeof(Expression2));
	s->enum_type = enum_type;
	s->expression = expression;
	return s;
}

Expression *newExpression(Expression_Type enum_type, OP *op, Expression *expression, Expression *expression2, Type *type, Type *type2, int integer , double real, Bool_Val *bool_val, Scope *scope, More_Expressions *more_expressions, char *name, Expression *expression1){
	Expression *s = malloc(sizeof(Expression));
	s->enum_type = enum_type;
	s->op = op;
	s->expression = expression;
	s->expression1 = expression1;
	s->expression2 = expression2;
	s->type = type;
	s->type2 = type2;
	s->integer = integer;
	s->real = real;
	s->bool_val = bool_val;
	s->scope = scope;
	s->more_expressions = more_expressions;
	s->name = name;
	return s;
}

More_Expressions *newMoreExpressions(More_Expressions_Type enum_type, Expression *expression, Expression2 *expression2){
	More_Expressions *s = malloc(sizeof(More_Expressions));
	s->enum_type = enum_type;
	s->expression = expression;
	s->expression2 = expression2;
	return s;
}

More_Decl *newMoreDecl(More_Expressions_Type enum_type, Declaration *declaration, More_Decl *more_decl){
	More_Decl *s = malloc(sizeof(More_Decl));
	s->enum_type = enum_type;
	s->declaration = declaration;
	s->more_decl = more_decl;
	return s;
}

Declaration *newDeclaration(Declaration_Type enum_type, Scope *scope, char *name, Type *type, More_Expressions *more_expressions){
	Declaration *s = malloc(sizeof(Declaration));
	s->enum_type = enum_type;
	s->scope = scope;
	s->name = name;
	s->type = type;
	s->more_expressions = more_expressions;
	return s;
}

Bool_Val *newBoolVal(Bool_Val_Type enum_type){
	Bool_Val *s = malloc(sizeof(Bool_Val));
	s->enum_type = enum_type;
	return s;
}


Scope *newScope(Scope_Type enum_type){
	Scope *s = malloc(sizeof(Scope));
	s->enum_type = enum_type;
	return s;
}

Type *newType(Type_Type enum_type){
	Type *s = malloc(sizeof(Type));
	s->enum_type = enum_type;
	return s;
}

