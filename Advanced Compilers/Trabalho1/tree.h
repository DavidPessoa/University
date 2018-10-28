#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum Gdeclpar_Type{
	pare_gdecl,
	more_gdecl_
}Gdeclpar_Type;

typedef enum Gdecl_Type{
	function,
	var
}Gdecl_Type;

typedef enum Var_Type{
	var_exp,
	var_nil
}Var_Type;


typedef enum Body_Type{
	statement_expression,
	nil_expression,
	statement_nil
}Body_Type;

typedef enum More_formal_arg_Type{
	formal_more_formal,
	empty
}More_formal_arg_Type;



typedef enum OP_Type{
	or_,
	and_,
	eq_,
	ne_,
	lt_,
	le_,
	gt_,
	ge_,
	plus_,
	minus_,
	times_,
	div_,
	mod_,
	not_,
	inv_
}OP_Type;


typedef enum Statementpar_Type{
	par_statement,
	more_statement,
	nil
}Statementpar_Type;

typedef enum Statement_Type
{
	assign,
	while_,
	if_,
	call_proc,
	print
}Statement_Type;

typedef enum More_Statements_Type{
	statement_statement,
	statement_more_statement

}More_Statements_Type;


typedef enum Expression2_Type{
	exp_,
	empty_exp2
}Expression2_Type;


typedef enum Expression_Type{
	op,
	int_literal,
	real_literal,
	bool_exp,
	id,
	call_func,
	toreal
}Expression_Type;


typedef enum More_Expressions_Type{
	exp_exp,
	m_exp
}More_Expressions_Type;


typedef enum More_Decl_Type{
	more_gdecl,
	empty_more_decl
}More_Decl_Type;


typedef enum Declaration_Type{
	decl_nil,
	decl_more_expressions,
	empty_decl
}Declaration_Type;


typedef enum Bool_Val_Type{
	true_,
	false_
}Bool_Val_Type;


typedef enum Scope_Type{
	local_scope,
	var_scope,
	arg_scope
}Scope_Type;


typedef enum Type_Type{
	int_type,
	bool_type,
	real_type,
}Type_Type;


typedef struct Gdeclpar Gdeclpar ;
typedef struct More_Gdecl More_Gdecl;
typedef struct Gdecl Gdecl;
typedef struct Var Var;
typedef struct Function Function;
typedef struct Body Body;
typedef struct Formal_Arg Formal_Arg;
typedef struct More_Formal_Arg More_Formal_Arg;
typedef struct OP OP;
typedef struct Statementpar Statementpar;
typedef struct More_Statements More_Statements;
typedef struct Statement Statement;
typedef struct Expression2 Expression2;
typedef struct Expression Expression;
typedef struct More_Expressions More_Expressions;
typedef struct More_Decl More_Decl;
typedef struct Declaration Declaration;
typedef struct Bool_Val Bool_Val;
typedef struct Scope Scope;
typedef struct Type Type;


struct Gdeclpar
{
	Gdeclpar_Type enum_type;
	Gdecl *gdecl;
	More_Gdecl *more_gdecl; 
};


struct More_Gdecl
{
	Gdeclpar *gdeclpar;
	Gdecl *gdecl;
};

struct Gdecl
{
	Gdecl_Type enum_type;
	Function *function;
	Var *var;
};

struct Var
{
	Var_Type enum_type;
	char *name;
	Type *type;
	More_Expressions *more_expressions;

};

struct Function
{
	char *name; 
	More_Formal_Arg *more_formal_arg;
	More_Decl *more_decl;
	Body *body;
};

struct Body
{
	Body_Type enum_type;
	Statementpar *statementpar;
	More_Expressions *more_expressions;

};

struct Formal_Arg
{
	char *name;
	Type *type;
};

struct More_Formal_Arg
{
	More_formal_arg_Type enum_type;
	Formal_Arg *formal_arg;
	More_Formal_Arg *more_formal_arg;
};

struct OP
{
	OP_Type enum_type;
};

struct Statementpar
{
	Statementpar_Type enum_type;
	Statement *statement;
	More_Statements *more_statements;

};

struct Statement
{
	Statement_Type enum_type;
	Scope *scope;
	More_Expressions *more_expressions;
	Statementpar *statementpar;
	Statementpar *statementpar2;
	char *name;
	Expression *expression;
	Type *type;

};


struct More_Statements
{
	More_Statements_Type enum_type;
	Statementpar *statementpar;
	Statement *statement;
	More_Statements *more_statements;

};


struct Expression2
{
	Expression2_Type enum_type;
	Expression *expression;
};

struct Expression
{
	Expression_Type enum_type;
	OP *op;
	Expression *expression;
	Expression *expression1;
	Expression *expression2;
	Type *type;
	Type *type2;
	int integer;
	double real;
	Bool_Val *bool_val;
	Scope *scope;
	More_Expressions *more_expressions;
	char *name;

};


struct More_Expressions
{
	More_Expressions_Type enum_type;
	Expression *expression;
	Expression2 *expression2;
};


struct More_Decl
{
	More_Decl_Type enum_type;
	Declaration *declaration;
	More_Decl *more_decl;
};


struct Declaration
{
	Declaration_Type enum_type;
	Scope *scope;
	char *name;
	Type *type;
	More_Expressions *more_expressions;
};


struct Bool_Val
{
	Bool_Val_Type enum_type;
};

struct Scope
{
	Scope_Type enum_type;
};

struct Type
{
	Type_Type enum_type;
};

Gdeclpar *newGdeclpar( Gdeclpar_Type enum_type ,Gdecl *gdecl, More_Gdecl *more_gdecl);
More_Gdecl *newMore_Gdecl(Gdeclpar *gdeclpar ,Gdecl *gdecl);
Gdecl *newGdecl(Gdecl_Type enum_type, Function *function, Var *var);
Var *newVar(Var_Type enum_type, char *name, Type *type, More_Expressions *more_expressions);
Function *newFunction (char *name, More_Formal_Arg *more_formal_arg, More_Decl *more_decl, Body *body);
Body *newBody(Body_Type enum_type, Statementpar *statementpar, More_Expressions *more_expressions);
Formal_Arg *newFormalArg(char *name, Type *type);
More_Formal_Arg *newMoreFormalArg(More_formal_arg_Type enum_type, Formal_Arg *formal_arg, More_Formal_Arg *more_formal_arg);
OP *newOP(OP_Type enum_type);
Statementpar *newStatementPar(Statementpar_Type enum_type, Statement *statement, More_Statements *more_statements);
Statement *newStatement(Statement_Type enum_type, Scope *scope, More_Expressions *more_expressions, Statementpar *statementpar, Statementpar *statementpar2, char *name, Expression *expression, Type *type);
More_Statements *newMoreStatements(More_Statements_Type enum_type, Statementpar *statementpar, Statement *statement, More_Statements *more_Statements);
Expression2 *newExpression2(Expression2_Type enum_type, Expression *expression);
Expression *newExpression(Expression_Type enum_type, OP *op ,Expression *expression ,Expression *expression2 ,Type *type, Type *type2, int integer , double real, Bool_Val *bool_val, Scope *scope, More_Expressions *more_expressions, char *name, Expression *expression1);
More_Expressions *newMoreExpressions(More_Expressions_Type enum_type, Expression *expression, Expression2 *expression2);
More_Decl *newMoreDecl(More_Expressions_Type enum_type, Declaration *declaration, More_Decl *more_decl);
Declaration *newDeclaration(Declaration_Type enum_type, Scope *scope, char *name, Type *type, More_Expressions *more_expressions);
Bool_Val *newBoolVal(Bool_Val_Type enum_type);
Scope *newScope(Scope_Type enum_type);
Type *newType(Type_Type enum_type); 	