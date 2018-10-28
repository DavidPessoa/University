void printGdeclpar(Gdeclpar *root);
void printMoreGdecl(More_Gdecl *root);
void printGdecl(Gdecl *root);
void printVar(Var *root);
void printFunction(Function *root);
void printBody(Body *root);
void printFormalArg(Formal_Arg *root);
void printMoreFormalArg(More_Formal_Arg *root);
void printOp(OP *root);
void printStatementpar(Statementpar *root);
void printStatement(Statement *root);
void printMoreStatements(More_Statements *root);
void printExpression2(Expression2 *root);
void printMoreExpressions(More_Expressions *root);
void printExpression(Expression *root);
void printMoreDecl(More_Decl *root);
void printDeclaration(Declaration *root);
void printBoolVal(Bool_Val *root);
void printScope(Scope *root);
void printType(Type *root);


void printGdeclpar(Gdeclpar *root){
	printf("%s\n", "Gdeclpar");
	if (root->enum_type == pare_gdecl){
		printGdecl(root->gdecl);
	}else if (root->enum_type == more_gdecl_){
		printMoreGdecl(root->more_gdecl);
	}
}


void printMoreGdecl(More_Gdecl *root){
	printf("%s\n", "More_Gdecl");
	printGdeclpar(root->gdeclpar);
	printGdecl(root->gdecl);
}


void printGdecl(Gdecl *root){
	printf("%s %d\n", "Gdecl", root->enum_type);
	if (root->enum_type == function){
		printFunction(root->function);
	}else if (root->enum_type == var){
		printVar(root->var);
	}
}


void printVar(Var *root){
	printf("Var %d\n", root->enum_type);
	printf("%s\n", root->name);
	if (root->enum_type == var_exp){
		printType(root->type);
		printMoreExpressions(root->more_expressions);

	}else if (root->enum_type == var_nil){
		printType(root->type);
		printf("NIL\n");
	}
}


void printFunction(Function *root){
	printf("%s\n", "Function");
	printf("%s\n", root->name);
	printMoreFormalArg(root->more_formal_arg);
	printMoreDecl(root->more_decl);
	printBody(root->body);
}


void printBody(Body *root){
	printf("%s %d\n", "Body", root->enum_type);
	if (root->enum_type == statement_expression){
		printStatementpar(root->statementpar);
		printMoreExpressions(root->more_expressions);

	}else if (root->enum_type == nil_expression){
		printf("%s\n", "NIL");
		printMoreExpressions(root->more_expressions);

	}else if (root->enum_type == statement_nil){
		printStatementpar(root->statementpar);
		printf("%s\n", "NIL");
	}
}


void printFormalArg(Formal_Arg *root){
	printf("%s\n", "Formal_Arg");
	printf("%s\n", root->name);
	printType(root->type);
}


void printMoreFormalArg(More_Formal_Arg *root){
	printf("%s %d\n", "More_Formal_Arg", root->enum_type);
	if (root->enum_type == formal_more_formal){
		printFormalArg(root->formal_arg);
		printMoreFormalArg(root->more_formal_arg);

	}else if (root->enum_type == empty){
		printf("%s\n", "Empty");
	}
}


void printOp(OP *root){
	if (root->enum_type == or_){
		printf("%s\n", "OR");
	}else if (root->enum_type == and_){
		printf("%s\n", "AND");
	}else if (root->enum_type == eq_){
		printf("%s\n", "EQ");
	}else if (root->enum_type == ne_){
		printf("%s\n", "NE");
	}else if (root->enum_type == lt_){
		printf("%s\n", "LT");
	}else if (root->enum_type == le_){
		printf("%s\n", "LE");
	}else if (root->enum_type == gt_){
		printf("%s\n", "GT");
	}else if (root->enum_type == ge_){
		printf("%s\n", "GE");
	}else if (root->enum_type == plus_){
		printf("%s\n", "PLUS");
	}else if (root->enum_type == minus_){
		printf("%s\n", "MINUS");
	}else if (root->enum_type == times_){
		printf("%s\n", "TIMES");
	}else if (root->enum_type == div_){
		printf("%s\n", "DIV");
	}else if (root->enum_type == mod_){
		printf("%s\n", "MOD");
	}else if (root->enum_type == not_){
		printf("%s\n", "NOT");
	}else if (root->enum_type == inv_){
		printf("%s\n", "INV");
	}
}


void printStatementpar(Statementpar *root){
	printf("%s %d\n", "Statementpar", root->enum_type);
	if (root->enum_type == par_statement){
		printStatement(root->statement);

	}else if (root->enum_type == more_statement){
		printMoreStatements(root->more_statements);

	}else if (root->enum_type == nil){
		printf("%s\n", "NIL");
	}
}


void printStatement(Statement *root){
	printf("%s %d\n", "Statement", root->enum_type);
	if (root->enum_type == assign){
		printf("%s\n", root->name);
		printScope(root->scope);
		printType(root->type);
		printMoreExpressions(root->more_expressions);

	}else if (root->enum_type == while_){
		printMoreExpressions(root->more_expressions);
		printStatementpar(root->statementpar);

	}else if (root->enum_type == if_){
		printMoreExpressions(root->more_expressions);
		printStatementpar(root->statementpar);
		printStatementpar(root->statementpar2);

	}else if (root->enum_type == call_proc){
		printf("%s\n", root->name);
		printMoreExpressions(root->more_expressions);

	}else if (root->enum_type == print){
		printExpression(root->expression);
	}
}


void printMoreStatements(More_Statements *root){
	printf("%s %d\n", "More_Statements", root->enum_type);
	if (root->enum_type == statement_statement){
		printStatementpar(root->statementpar);
		printStatement(root->statement);

	}else if (root->enum_type == statement_more_statement){
		printStatementpar(root->statementpar);
		printMoreStatements(root->more_statements);
	}
}


void printExpression2(Expression2 *root){
	printf("%s %d\n", "Expression2", root->enum_type);
	if (root->enum_type == exp_){
		printExpression(root->expression);
	}else if (root->enum_type == empty_exp2){
		printf("%s\n", "Empty");
	}
}


void printMoreExpressions(More_Expressions *root){
	printf("%s %d\n", "More_Expressions", root->enum_type);
	if (root->enum_type == exp_exp){
		printExpression(root->expression);
		printExpression2(root->expression2);

	}else if (root->enum_type == m_exp){
		printExpression(root->expression);
	}
}


void printExpression(Expression *root){
	printf("%s %d\n", "Expression", root->enum_type);
	if (root->enum_type == op){
		printOp(root->op);
		printExpression(root->expression);
		printExpression(root->expression1);
		printType(root->type);

	}else if (root->enum_type == int_literal){
		printf("int_literal %d\n",root->integer);
		printType(root->type);

	}else if (root->enum_type == real_literal){
		printf("real_literal %f\n" ,root->real);
		printType(root->type);

	}else if (root->enum_type == bool_exp){
		printf("bool_literal");
		printBoolVal(root->bool_val);
		printType(root->type);

	}else if (root->enum_type == id){
		printf("%s\n", root->name);
		printScope(root->scope);
		printType(root->type);
		printType(root->type2);

	}else if (root->enum_type == call_func){
		printf("%s\n", root->name);
		printMoreExpressions(root->more_expressions);
		printType(root->type);

	}else if (root->enum_type == toreal){
		printExpression(root->expression);
		printType(root->type);
	}
}


void printMoreDecl(More_Decl *root){
	printf("%s %d\n", "More_Decl", root->enum_type);
	if (root->enum_type == more_gdecl){
		printDeclaration(root->declaration);
		printMoreDecl(root->more_decl);

	}else if (root->enum_type == empty_more_decl){
		printf("Empty\n" );
	}
}


void printDeclaration(Declaration *root){
	printf("%s %d\n", "Declaration", root->enum_type);
	if (root->enum_type == decl_nil){
		printScope(root->scope);
		printf("%s\n", root->name);
		printType(root->type);
		printf("NIL\n");

	}else if (root->enum_type == decl_more_expressions){
		printScope(root->scope);
		printf("%s\n", root->name);
		printType(root->type);
		printMoreExpressions(root->more_expressions);

	}else if (root->enum_type == empty_decl){
		printf("Empty\n");
	}
}


void printBoolVal(Bool_Val *root){
	printf("%s\n", "Bool_Val");
	if (root->enum_type == true_){
		printf("True\n");
	}else if (root->enum_type == false_){
		printf("False\n");
	}
}


void printScope(Scope *root){
	printf("%s\n", "Scope");
	if (root->enum_type == local_scope){
		printf("Local\n");
	}else if (root->enum_type == var_scope){
		printf("Var\n");
	}else if (root->enum_type == arg_scope){
		printf("Arg\n");
	}
}


void printType(Type *root){
	printf("%s\n", "Type");
	if (root->enum_type == int_type){
		printf("Int\n");
	}else if (root->enum_type == bool_type){
		printf("Bool\n");
	}else if (root->enum_type == real_type){
		printf("Real\n");
	}
}
