#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum FunctionType
{
	moreFuncs,
	declaration
}FunctionType;

typedef enum MoreFunctionsType
{
	simpleFunction_,
	moreFunctions_
}MoreFunctionsType;

typedef enum ModeDeclarationsType
{
	single,
	more
}ModeDeclarationsType;

typedef enum DeclarationType
{
	fun,
	var,
	boolVal_
}DeclarationType;

typedef enum DeclTypeType
{
	int_,
	void_,
	realtype

}DeclTypeType;

typedef enum BoolValType
{
	true_, 
	false_,
	anotherEmpty

}BoolValType;

typedef enum InitialValueType
{
	num_,
	real_,
	empty_
}InitialValueType;

typedef enum DeclArgsType
{
	arguments_,
	empty__
}DeclArgsType;

typedef enum MoreArgDeclType
{
	simple,
	complex
}MoreArgDeclType;


typedef enum BodyType
{
	label,
	moreExpressions
}BodyType;

typedef enum ExpressionType
{
	op,
	cjump,
	jump,
	itor,
	complexReturn,
	complexCall,
	simpleReturn,
	simpleCall,
	print,
	not_,
	mod,
	simpleCallNoArgs,
	complexCallNoArgs

}ExpressionType;

typedef enum IdType
{
	temp, 
	floatingPoint,
	name
}IdType;

typedef enum ArgsType
{	
	simpleId,
	complexId,
	num, 
	real,
}ArgsType;


typedef enum OpType
{	
	sub,
	mul,
	add, 
	div_,
	lt,
	eq,
	lstore,
	astore,
	gstore,
	aload,
	gload,
	lload,
	value,
	copy,
	ne,
	le,
	inv

}OpType;



typedef enum JLabelType
{
	label_, 
	empty
}JLabelType ;

typedef enum TypeType
{
	i, 
	r, 
	b
}TypeType;


typedef struct Function Function ;
typedef struct MoreFunctions MoreFunctions;
typedef struct Body Body;
typedef struct MoreExpressions MoreExpressions;
typedef struct Expression Expression;
typedef struct BoolVal BoolVal ;
typedef struct Id Id;
typedef struct Args Args;
typedef struct Op Op;
typedef struct JLabel JLabel;
typedef struct Type Type;
typedef struct Declaration Declaration;
typedef struct DeclType DeclType;
typedef struct InitialValue InitialValue;
typedef struct DeclArgs DeclArgs;
typedef struct Arguments Arguments;
typedef struct MoreArgDecl MoreArgDecl;
typedef struct MoreDeclarations MoreDeclarations;

struct Function
{
	FunctionType type;
	MoreFunctions *moreFunctions;
	MoreDeclarations *moreDeclarations;
	char *name;
};

struct MoreDeclarations
{
	ModeDeclarationsType type;
	Declaration *declaration;
	Function *function;
};

struct Declaration
{
	DeclarationType type;
	char *name;
	DeclType *declType;
	DeclArgs *declArgs1;
	DeclArgs *declArgs2;
	InitialValue *initialValue;
	BoolVal *boolVal;
};

struct DeclType
{	
	DeclTypeType type;	
};

struct BoolVal
{	
	BoolValType type;	
};

struct InitialValue
{
	InitialValueType type;	
	int num;
	double real;
};

struct DeclArgs 
{
	DeclArgsType type;
	Arguments *arguments;
};

struct Arguments
{
	MoreArgDecl *moreArgDecl;
};

struct MoreArgDecl
{
	MoreArgDeclType type;
	DeclType *declType;
	char *name;
	Arguments *arguments;
};


struct MoreFunctions
{
	MoreFunctionsType type;
	char *name;
	Body *body;
	Function *function;
};


struct Body
{
	BodyType type;
	JLabel *jLabel;
	Expression *expression;
	MoreExpressions *moreExpressions;
};


struct MoreExpressions
{
	JLabel *jLabel;
	Expression *expression;
	Body *body;
};

struct Expression
{
	ExpressionType type;
	Id *id;
	Type *typeNode;
	Op *op;
	Args *args;
	int num1;
	int num2;
	char *name;
};

struct Id
{
	IdType type;
	int num;
	char *name;
};

struct Args
{
	ArgsType type;
	Id *id1;
	Id *id2;
	int num;
	double real;
	Args *args;
};

struct Op
{
	OpType type;
};

struct JLabel
{
	JLabelType type;
	int num;
};

struct Type
{
	TypeType type;
};


Function *newFunction(FunctionType type, MoreFunctions *moreFunctions, MoreDeclarations *moreDeclarations);
MoreDeclarations *newMoreDeclarations(ModeDeclarationsType type, Declaration *declaration, Function *function);
Declaration *newDeclaration(DeclarationType type, char *name, DeclType *declType, DeclArgs *declArgs1, DeclArgs *declArgs2, InitialValue *initialValue, BoolVal *boolVal);
DeclType *newDeclType(DeclTypeType type);
BoolVal *newBoolVal(BoolValType type);
InitialValue *newInitialValue(InitialValueType type, int num, double real);
DeclArgs *newDeclArgs(DeclArgsType type, Arguments *arguments);
Arguments *newArguments(MoreArgDecl *moreArgDecl);
MoreArgDecl *newMoreArgDecl(MoreArgDeclType type, DeclType *declType, char *name, Arguments *arguments);
MoreFunctions *newMoreFunctions(MoreFunctionsType type, Body *body, Function *function, char *name);
Body *newBody(BodyType type, JLabel *jLabel, Expression *expression, MoreExpressions *moreExpressions);
Expression *newExpression(ExpressionType type, Id *id, Type *typeNode, Op *op, Args *args, int num1, int num2, char *name);
MoreExpressions *newMoreExpressions(JLabel *jLabel, Expression *expression, Body *body);
Id *newId(IdType type, int num, char *name);
Args *newArgs(ArgsType type, Id *id1, Args *args, int num, double real);
Op *newOp(OpType type);
JLabel *newJLabel(JLabelType type, int num);
Type *newType(TypeType type);