#include "compiler.h"

int tempCounter = 0;
int floatingCounter = 0;
int labelCounter = 0;
int result[3] = {-1};

void resetResult(){
	result[0] = -1;
	result[1] = -1;
	result[2] = -1;
}

char typeCaller(int x){
	if(x == 2){
		return 'r';
	}
	return 'i';
	
}

char *resultingType(int x){
	if(x == 2){
		return "fp";
	}else{
		return "t";
	}
}

char scopeCaller(int x){
	if(x == 0){
		return 'l';
	}else if(x == 1){
		return 'g';
	}else{
		return 'a';
	}
}

int counterSelection( int x ){
	if (x == 2){
		return floatingCounter;
	}
	return tempCounter;

}

void counterIncrement( int x){
	if (x == 0){
		tempCounter++;
	}else if (x == 2){
		floatingCounter++;
	}

}

void resetVariables(){
	tempCounter = 0;
	floatingCounter = 0;
}

void root(Gdeclpar *root) {
	nodeGdeclpar(root);
}


/////FUNCTION TO CROSS THE TREE IN  PREORDER


void nodeGdeclpar(Gdeclpar *root){
	
	if (root->enum_type == pare_gdecl){
		nodeGdecl(root->gdecl);
	}else if (root->enum_type == more_gdecl_){
		nodeMoreGdecl(root->more_gdecl);
	}
}


void nodeMoreGdecl(More_Gdecl *root){	

	nodeGdeclpar(root->gdeclpar);
	nodeGdecl(root->gdecl);
}


void nodeGdecl(Gdecl *root){
	
	if (root->enum_type == function){
		nodeFunction(root->function);
	}else if (root->enum_type == var){
		nodeVar(root->var);
	}
}


void nodeVar(Var *root){

	printf("%s\n", root->name);
	if (root->enum_type == var_exp){
		nodeMoreExpressions(root->more_expressions);

	}else if (root->enum_type == var_nil){
		printf(" ");
	}
}


void nodeFunction(Function *root){

	resetVariables();
	printf("function @%s\n", root->name);
	nodeMoreFormalArg(root->more_formal_arg);
	nodeMoreDecl(root->more_decl);
	nodeBody(root->body);
}


void nodeBody(Body *root){
	if (root->enum_type == statement_expression){
		nodeStatementpar(root->statementpar);
		nodeMoreExpressions(root->more_expressions);
		if (root->more_expressions->expression->type->enum_type == int_type){
			printf("\ti_return t%d\n", result[0] );
		}else if (root->more_expressions->expression->type->enum_type == real_type){
			printf("\tr_return fp%d\n", result[0]);
		}else if (root->more_expressions->expression->type->enum_type == bool_type){
			printf("\tb_return t%d\n", result[0]);
		}


	}else if (root->enum_type == nil_expression){
		printf("%s\n", "NIL");
		nodeMoreExpressions(root->more_expressions);
		if (root->more_expressions->expression->type->enum_type == int_type){
			printf("\ti_return t%d\n", result[0] );
		}else if (root->more_expressions->expression->type->enum_type == real_type){
			printf("\tr_return fp%d\n", result[0]);
		}else if (root->more_expressions->expression->type->enum_type == bool_type){
			printf("\tb_return t%d\n", result[0]);
		}

	}else if (root->enum_type == statement_nil){
		nodeStatementpar(root->statementpar);
		printf("\treturn\n");
	}
	printf("\n");
}


void nodeFormalArg(Formal_Arg *root){
	printf(" ");
}


void nodeMoreFormalArg(More_Formal_Arg *root){
	if (root->enum_type == formal_more_formal){
		nodeFormalArg(root->formal_arg);
		nodeMoreFormalArg(root->more_formal_arg);

	}else if (root->enum_type == empty){
		printf(" ");
	}
}


void nodeOp(OP *root){
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


void nodeStatementpar(Statementpar *root){

	if (root->enum_type == par_statement){
		nodeStatement(root->statement);

	}else if (root->enum_type == more_statement){
		nodeMoreStatements(root->more_statements);

	}else if (root->enum_type == nil){
		printf(" ");
	}
}


void nodeStatement(Statement *root){

	if (root->enum_type == assign){
		
		nodeMoreExpressions(root->more_expressions);
		char t = typeCaller(root->type->enum_type);
		char s = scopeCaller(root->scope->enum_type);
		char *resultType = resultingType(root->type->enum_type);
		printf("\t@%s <- %c_%cstore %s%d\n",root->name, t, s, resultType, result[0]);
		
	}else if (root->enum_type == while_){
		printf("l%d:", labelCounter);
		labelCounter++;
		nodeMoreExpressions(root->more_expressions);
		printf("\tcjump t%d, l%d, l%d\n", tempCounter-1, labelCounter, labelCounter+1);
		printf("l%d:", labelCounter);
		labelCounter++;
		nodeStatementpar(root->statementpar);
		printf("\tjump l%d\n", labelCounter-2 );
		printf("l%d:", labelCounter);
		labelCounter++;

	}else if (root->enum_type == if_){
		nodeMoreExpressions(root->more_expressions);
		printf("\tcjump t%d, l%d, l%d\n", tempCounter-1, labelCounter, labelCounter+1);
		printf("l%d:", labelCounter);
		labelCounter++;
		nodeStatementpar(root->statementpar);
		printf("\tjump l%d\n", labelCounter+1 );
		printf("l%d:", labelCounter);
		labelCounter++;
		nodeStatementpar(root->statementpar2);
		printf("l%d:", labelCounter);

	}else if (root->enum_type == call_proc){
		nodeMoreExpressions(root->more_expressions);
		printf("\tcall @%s, []\n", root->name);

	}else if (root->enum_type == print){
		nodeExpression(root->expression);
		char t = typeCaller(root->expression->type->enum_type);
		char *resultType = resultingType(root->expression->type->enum_type);
		printf("\t%c_print %s%d\n", t, resultType, result[0]);
	}
}


void nodeMoreStatements(More_Statements *root){

	if (root->enum_type == statement_statement){
		nodeStatementpar(root->statementpar);
		nodeStatement(root->statement);

	}else if (root->enum_type == statement_more_statement){
		nodeStatementpar(root->statementpar);
		nodeMoreStatements(root->more_statements);
	}
}


void nodeExpression2(Expression2 *root){
	
	if (root->enum_type == exp_){
		nodeExpression(root->expression);
	}else if (root->enum_type == empty_exp2){
		printf(" "); 
	}
}


void nodeMoreExpressions(More_Expressions *root){
	
	if (root->enum_type == exp_exp){
		nodeExpression(root->expression);
		nodeExpression2(root->expression2);

	}else if (root->enum_type == m_exp){
		nodeExpression(root->expression);
	}
}

void nodeExpression (Expression *root){
	
	
	if (root->enum_type == op){								
		int op = root->op->enum_type;
		int opType = root->type->enum_type;
		
		
		if(op == or_){ 
			nodeExpression(root->expression);
			int firstresult= result[0];
			printf("\tcjump t%d, l%d, l%d\n",  tempCounter-1, labelCounter, labelCounter+1);
			printf("l%d", labelCounter+1);
			nodeExpression(root->expression1);
			printf("\tt%d <- i_copy t%d\n", firstresult, result[0]);
			printf("l%d", labelCounter);
			labelCounter++;
			labelCounter++;
			resetResult();
			result[0] = firstresult;
		}else if(op == and_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			printf("\n");
		}else if(op == eq_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			if (opType == int_type || opType == bool_type){
				printf("\tt%d <- i_eq t%d, t%d\n", tempCounter, tempCounter-2, tempCounter-1);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			} else if(opType == real_type){
				printf("\tfp%d <- r_eq fp%d, fp%d\n", floatingCounter, floatingCounter-2, floatingCounter-1);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}		

		}else if(op == ne_){ 
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			printf("\n");
		}else if(op == lt_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			opType = root->expression->type->enum_type;
			if (opType == int_type){
				printf("\tt%d <- i_lt t%d, t%d\n", tempCounter, tempCounter-2, tempCounter-1);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			} else if(opType == real_type){
				printf("\tfp%d <- r_lt fp%d, fp%d\n", floatingCounter, floatingCounter-2, floatingCounter-1);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}	

		}else if(op == le_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			printf("\n");
		}else if(op == gt_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			opType = root->expression->type->enum_type;
			if (opType == int_type){
				printf("\tt%d <- i_lt t%d, t%d\n", tempCounter, tempCounter-1,  tempCounter-2);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			} else if(opType == real_type){
				printf("\tfp%d <- r_lt fp%d, fp%d\n", floatingCounter, floatingCounter-1,  tempCounter-2);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}	
		}else if(op == ge_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			opType = root->expression->type->enum_type;
			if (opType == int_type){
				printf("\tt%d <- i_lt t%d, t%d\n", tempCounter, tempCounter-2, tempCounter-1);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			} else if(opType == real_type){
				printf("\tfp%d <- r_lt fp%d, fp%d\n", floatingCounter, floatingCounter-2, floatingCounter-1);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}	

		}else if(op == plus_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			if (opType == int_type){
				printf("\tt%d <- i_add t%d, t%d\n", tempCounter, tempCounter-2, tempCounter-1);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			} else if(opType == real_type){
				printf("\tfp%d <- r_add fp%d, fp%d\n", floatingCounter, floatingCounter-2, floatingCounter-1);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}		

		} else if(op == minus_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			if (opType == int_type){
				printf("\tt%d <- i_sub t%d, t%d\n", tempCounter, tempCounter-2, tempCounter-1);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			} else if(opType == real_type){
				printf("\tfp%d <- r_sub fp%d, fp%d\n", floatingCounter, floatingCounter-2, floatingCounter-1);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}

		} else if(op == times_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			if (opType == int_type){
				printf("\tt%d <- i_mul t%d, t%d\n", tempCounter, tempCounter-2, tempCounter-1);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			} else if(opType == real_type){
				printf("\tfp%d <- r_mul fp%d, fp%d\n", floatingCounter, floatingCounter-2, floatingCounter-1);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}

		} else if(op == div_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			if (opType == int_type){
				printf("\tt%d <- i_div t%d, t%d\n", tempCounter, tempCounter-2, tempCounter-1);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			} else if(opType == real_type){
				printf("\tfp%d <- r_div fp%d, fp%d\n", floatingCounter, floatingCounter-2, floatingCounter-1);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}

		} else if(op == mod_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			printf("\n");
		} else if(op == not_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			printf("\n");
		} else if(op == inv_){
			nodeExpression(root->expression);
			nodeExpression(root->expression1);
			printf("\n");
		}

	
		

	}else if (root->enum_type == int_literal){ 						
	
		printf("\tt%d <- i_value %d\n", tempCounter, root->integer);
		resetResult();
		result[0] = tempCounter;
		tempCounter++;
		
	

	}else if (root->enum_type == real_literal){						
		printf("\tfp%d <- r_value %f\n", floatingCounter, root->real);
		floatingCounter++;
	
	

	}else if (root->enum_type == bool_exp){						

		nodeBoolVal(root->bool_val);
		
		

	}else if (root->enum_type == id){                               
	
		int scopeType = root->scope->enum_type;
		int varType = root->type->enum_type;

		if(varType == int_type) { 				
			if (scopeType == local_scope){
				printf("\tt%d <- i_lload @%s\n", tempCounter, root->name);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			}else if(scopeType == var_scope){
				printf("\tt%d <- i_gload @%s\n", tempCounter, root->name);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			}else if(scopeType == arg_scope){
				printf("\tt%d <- i_aload @%s\n", tempCounter, root->name);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			}

		}else if (varType == bool_type){
			if (scopeType == local_scope){
				printf("\tt%d <- i_lload @%s\n", tempCounter, root->name);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			}else if(scopeType == var_scope){
				printf("\tt%d <- i_gload @%s\n", tempCounter, root->name);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			}else if(scopeType == arg_scope){
				printf("\tt%d <- i_aload @%s\n", tempCounter, root->name);
				resetResult();
				result[0] = tempCounter;
				tempCounter++;
			}

		}else if (varType == real_type){
			if (scopeType == local_scope){
				printf("\tfp%d <- r_lload @%s\n", floatingCounter, root->name);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}else if(scopeType == var_scope){
				printf("\tfp%d <- r_gload @%s\n", floatingCounter, root->name);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}else if(scopeType == arg_scope){
				printf("\tfp%d <- r_aload @%s\n", floatingCounter, root->name);
				resetResult();
				result[0] = floatingCounter;
				floatingCounter++;
			}
		}
	

	}else if (root->enum_type == call_func){   							
		
		
		nodeMoreExpressions(root->more_expressions);
		char t = typeCaller(root->type->enum_type);
		char *r = resultingType(t);
		int index = counterSelection(root->type->enum_type);
		printf("\t%s%d <- %c_call @%s, []\n", r, index, t, root->name);
		counterIncrement(root->type->enum_type);
		

	}else if (root->enum_type == toreal){ 							
		nodeExpression(root->expression);
		printf("\tfp%d <- itor t%d\n", floatingCounter, tempCounter-1);
		resetResult();
		result[0]=floatingCounter;
		floatingCounter++;
		
	}
}


void nodeMoreDecl(More_Decl *root){

	if (root->enum_type == more_gdecl){
		nodeDeclaration(root->declaration);
		nodeMoreDecl(root->more_decl);

	}else if (root->enum_type == empty_more_decl){
		printf(" " );
	}
}


void nodeDeclaration(Declaration *root){

	if (root->enum_type == decl_more_expressions){
		nodeMoreExpressions(root->more_expressions);
		char t = typeCaller(root->type->enum_type);
		char s = scopeCaller(root->scope->enum_type);
		int index = counterSelection(root->type->enum_type);
		char *tempType = resultingType(root->type->enum_type);
		printf("\t@%s <- %c_%cstore %s%d\n",root->name, t, s, tempType ,index-1);
	}
}


void nodeBoolVal(Bool_Val *root){

	if (root->enum_type == true_){
		printf("True\n");
	}else if (root->enum_type == false_){
		printf("False\n");
	}
}


void nodeScope(Scope *root){

	if (root->enum_type == local_scope){
		printf("Local\n");
	}else if (root->enum_type == var_scope){
		printf("Var\n");
	}else if (root->enum_type == arg_scope){
		printf("Arg\n");
	}
}


void nodeType(Type *root){

	if (root->enum_type == int_type){
		printf("Int\n");
	}else if (root->enum_type == bool_type){
		printf("Bool\n");
	}else if (root->enum_type == real_type){
		printf("Real\n");
	}
}
