#include "tradutor.h"
#include "linkedlist.h"
int temps = 0;
int floatings = 0;
int labels = 0;
int intPrintingFlag = 0;
int realPrintingFlag = 0;
int boolPrintingFlag = 0;
Node *funcArgs;
Node *funcVars;
Node *functionSavings;
int tempValues [10] = {-1};

void root(Function *root) {
	functionSavings = initializeNode();
	if (root->type != moreFuncs){
		printf("\t.data\n");
	}
	nodeFunction(root);
}

void nodeFunction(Function *root){
	
	if(root->type == moreFuncs){	
		nodeMoreFunctions(root->moreFunctions);
	}else{
		nodeMoreDeclarations(root->moreDeclarations);
	}
}

void nodeMoreDeclarations(MoreDeclarations *root){
	if(root->type == single){
		nodeDeclaration(root->declaration);
	}else{
		nodeDeclaration(root->declaration);
		nodeFunction(root->function);
	}
}

void nodeDeclaration(Declaration *root){
	
	if (root->type == fun){
		addElement(functionSavings, 0, root->name);
		Node *r = lookforNode(functionSavings, root->name);
		funcArgs = r->functionArgs;
		funcVars = r->functionVars;
		nodeDeclArgs(root->declArgs1, 0);
		nodeDeclArgs(root->declArgs2, 1);
		
	}else if(root->type == var){
		if (root->declType->type == int_){
			if(root->initialValue->type != empty_){
				printf("%s:\t.word %d\n", root->name+1, root->initialValue->num);	
			}else{
				printf("%s:\t.space 4\n", root->name+1);	
			}
		}else if (root->declType->type == realtype){
			if(root->initialValue->type != empty_){
				printf("%s:\t.word %f\n", root->name+1, root->initialValue->real);
			}else{
				printf("%s:\t.space 4\n", root->name+1);
			}
		}else if (root->declType->type == realtype){
			if(root->initialValue->type != empty_){
				printf("%s:\t.word %f\n", root->name+1, root->initialValue->real);
			}else{
				printf("%s:\t.space 4\n", root->name+1);
			}
		}
	}else if(root->type == boolVal_){
		if(root->boolVal->type != anotherEmpty){
			if (root->boolVal->type == true_){
				printf("%s:\t.word \t1\n", root->name+1);	
			}else{
				printf("%s:\t.word \t0\n", root->name+1);					
			}
		}else{
				printf("%s:\t.space 4\n", root->name+1);
			}
	}
}

void nodeDeclType(DeclType *root){
	printf("\n");
}

void nodeInitialValue (InitialValue *root){
	if (root->type == num_){
		printf("%d\n", root->num);
	}else if(root->type == real_){
		printf("%f\n", root->real);
	}
}

void nodeDeclArgs(DeclArgs *root, int flag){
	if (root->type == arguments_){
		nodeArguments(root->arguments, flag);
	}
}

void nodeArguments(Arguments *root, int flag){
	nodeMoreArgDecl(root->moreArgDecl, flag);
}

void nodeMoreArgDecl(MoreArgDecl *root, int flag){
	if (flag == 0){
		int x = (sizeList(funcArgs,0)+1)*4;
		addElement(funcArgs, x,root->name);
	}else{
		int x = (sizeList(funcVars,0)+1)*-4-4;
		addElement(funcVars, x, root->name);
	}
	if(root->type == complex){
		nodeArguments(root->arguments, flag);
	}
}

void nodeMoreFunctions(MoreFunctions *root){
//	printf("MoreFunctions\n");
	printMoreFunctions(root);
	printf("\n");
	printf("\t.text\n");
	if (strcmp(root->name,"@main")  == 0){
		printf("\t.globl main\n" );
	}
	printf("%s:\n", root->name+1);
	printf("\tsw\t$fp, -4($sp)\n");
	printf("\taddiu\t$fp, $sp, -4\n");
	printf("\tsw\t$ra, -4($fp)\n");
	if (root->type == simpleFunction_){
		Node *l = lookforNode(functionSavings,root->name);
		funcArgs = l->functionArgs;
		funcVars = l->functionVars;
		printf("\taddiu\t$sp, $fp, %d\n", -4 + sizeList(funcVars,0)*-4);
		nodeBody(root->body);
		printf("\tlw\t$ra, -4($fp)\n");
		printf("\taddiu\t$sp, $fp, %d\n", 4 + sizeList(funcArgs,0)*4);
		printf("\tlw\t$fp, 0($fp)\n");
		printf("\tjr\t$ra\n");
	}else{
		Node *l = lookforNode(functionSavings,root->name);
		funcArgs = l->functionArgs;
		funcVars = l->functionVars;
		printf("\taddiu\t$sp, $fp, %d\n", -4 + sizeList(funcVars,0)*-4);
		nodeBody(root->body);
		printf("\tlw\t$ra, -4($fp)\n");
		printf("\taddiu\t$sp, $fp, %d\n", 4 + sizeList(funcArgs,0)*4);
		printf("\tlw\t$fp, 0($fp)\n");
		printf("\tjr\t$ra\n");
		temps = 0;
		nodeFunction(root->function);
	}
}

void nodeBody(Body *root){
//	printf("Body\n");
	if (root->type == label){
		nodeJLabel(root->jLabel);
		nodeExpression(root->expression);
	}else{
		nodeMoreExpressions(root->moreExpressions);
	}
}

void nodeMoreExpressions(MoreExpressions *root){
//	printf("MoreExpressions \n");
	nodeJLabel(root->jLabel);
	nodeExpression(root->expression);
	nodeBody(root->body);
}

void nodeExpression(Expression *root){
	if (root->type == op){
		if(root->op->type == sub){
			if (root->args->type==complexId){
					if(root->args->id1->num < root->args->args->id1->num){
						printf("\tsubu\t$t%d, $t%d, $t%d\n", temps-2, temps-2, temps-1);			
					}else{
						printf("\tsubu\t$t%d, $t%d, $t%d\n", temps-2, temps-1, temps-2);	
					}
				}
			tempValues[temps-2] = root->id->num;
			temps--;

		}else if (root->op->type == mul){
			printf("\tmult\t$t%d, $t%d\n", temps-2, temps-1);
			printf("\tmflo\t$t%d\n", temps-2);
			tempValues[temps-2] = root->id->num;
			temps--;
		
		}else if (root->op->type == add){
			if (root->args->type==complexId){
				if(root->args->id1->num < root->args->args->id1->num){
					printf("\taddu\t$t%d, $t%d, $t%d\n", temps-2, temps-2, temps-1);			
				}else{
					printf("\taddu\t$t%d, $t%d, $t%d\n", temps-2, temps-1, temps-2);	
				}
			}
			tempValues[temps-2] = root->id->num;
			temps--;

		}else if (root->op->type == div_){
			if (root->args->type==complexId){
				if(root->args->id1->num < root->args->args->id1->num){
					printf("\tdiv\t$t%d, $t%d\n", temps-2, temps-1);
					printf("\tmflo\t$t%d\n", temps-2);
				}else{
					printf("\tdiv\t$t%d, $t%d\n", temps-1, temps-2);
					printf("\tmflo\t$t%d\n", temps-2);	
				}
			}
			tempValues[temps-2] = root->id->num;
			temps--;
		}else if (root->op->type == lt){
				if (root->args->type==complexId){
					if(root->args->id1->num < root->args->args->id1->num){
						printf("\tslt\t$t%d, $t%d, $t%d\n", temps-2, temps-2, temps-1);			
					}else{
						printf("\tslt\t$t%d, $t%d, $t%d\n", temps-2, temps-1, temps-2);	
					}
				}
				tempValues[temps-2] = root->id->num;
				temps--;
				
		}else if (root->op->type == eq){
			printf("\tsubu\t$t%d, $t%d, $t%d\n", temps-2, temps-2, temps-1);			
			printf("\tsltiu\t$t%d, $t%d, 1\n", temps-2, temps-2);			
			temps--;

		}else if (root->op->type == lstore){
				printf("\tsw\t$t%d, %d($fp)\n", temps-1, lookforChar(funcVars, root->id->name));
				temps--;

		}else if (root->op->type == astore){
				printf("\tsw\t$t%d, %d($fp)\n", temps-1, lookforChar(funcArgs, root->id->name));
				temps--;
		}else if (root->op->type == gstore){
			
			printf("\tla\t$at, %s\n",root->id->name+1);
			printf("\tsw\t$t%d, 0($at)\n", temps-1);
			temps--;


		}else if (root->op->type == aload){
				if (root->id->type == temp){	
					Node *n = lookforNode(funcArgs, root->args->id1->name);	
					n->temp = temps;
					printf("\tlw\t$t%d, %d($fp)\n", temps, n->num);
					tempValues[temps] = root->id->num;
					temps++;
				}

		}else if (root->op->type == gload){
				printf("\tla\t$t%d, %s\n", temps,root->args->id1->name+1);
				printf("\tlw\t$t%d, 0($t%d)\n", temps, temps);
				tempValues[temps] = root->id->num;
				temps++;

		}else if (root->op->type == lload){
				if (root->id->type == temp){		
					Node *n = lookforNode(funcVars, root->args->id1->name);	
					n->temp = temps;
					printf("\tlw\t$t%d, %d($fp)\n", temps, n->num);
					tempValues[temps] = root->id->num;
					temps++;
				}

		}else if (root->op->type == value){
				if (root->id->type == temp){
					if (root->args->num > 65536){    //2¹⁵
					 	printf("\tlui\t%d\n", root->args->num);
					 	printf("\tori\t$t%d, $0, %d\n", temps, root->args->num);	
					}else{
						printf("\tori\t$t%d, $0, %d\n", temps, root->args->num);
					} 
					tempValues[temps] = root->id->num;
					temps++;
				}
				
		}else if (root->op->type == copy){
				nodeId(root->id);
				printf(", ");
				nodeArgs(root->args);
				printf("\n");
		
		}else if (root->op->type == ne){
			printf("\tsubu\t$t%d, $t%d, $t%d\n", temps-2, temps-2, temps-1);			
			printf("\tsltiu\t$t%d, $0, $t%d\n", temps-2, temps-2);			
			temps--;

		}else if (root->op->type == le){
			if(root->args->id1->num < root->args->args->id1->num){
				printf("\tslt\t$t%d, $t%d, $t%d\n", temps-2, temps-1, temps-2);			
			}else{
				printf("\tslt\t$t%d, $t%d, $t%d\n", temps-2, temps-2, temps-1);	
			}		
			printf("\txori\t$t%d, $t%d, 1\n", temps-2, temps-2);			
			temps--;

		}else if (root->op->type == inv){
			printf("\tsubu\t$t%d, $0, $t%d\n", temps-1, temps-1);				
		}

	}else if (root->type == cjump){
		printf("\tbeq\t$t%d, $0, l$%d\n", temps-1, root->num2);
		printf("\tj\tl$%d\n", root->num1);	
		temps--;

	}else if (root->type == jump){
		printf("\tj\tl$%d\n", root->num1);
		
	}else if (root->type == itor){
		printf("\tmtc1\t$t%d, fp%d\n", temps-1, floatings);
		printf("\tcvt.d.w\t$fp%d, fp%d\n", floatings, floatings);

	}else if (root->type == not_){
		printf("\txori\t$t%d, $t%d, 1\n", temps-1, temps-1);			
	
	}else if (root->type == complexReturn){
		printf("\tor\t$v0, $0, $t%d\n", temps-1);
		
	}else if (root->type == complexCall){
		//TEM DE IMPRIMIR UM SW POR CADA ARG
		int l = 0;
		int i = 0;
		int counter = 0;
		
		while(l<temps && !containsId(root->args, l)){	
			printf("\taddiu,\t$sp, $sp, -4\n");
			printf("\tsw\t$t%d, 0($sp)\n", l);
			l++;
			counter++;
		}
		getIDs(root->args);
		temps = 0;	
		printf("\tjal\t%s\n", root->name+1);
		printf("\tor\t$t%d, $0, $v0\n", counter);
		int x = counter-1;
		while (i<counter){
			printf("\tlw\t$t%d, 0($sp)\n", x);
			printf("\taddiu,\t$sp, $sp, 4\n");
			i++;
			x--;
			temps++;
		}
		

		tempValues[temps] = root->id->num;
		temps++;

	}else if (root->type == simpleCall){
		
		int l = 0;
		int i = 0;
		int counter = 0;
		
		while(l<temps && !containsId(root->args, l)){	
			printf("\taddiu,\t$sp, $sp, -4\n");
			printf("\tsw\t$t%d, 0($sp)\n", l);
			l++;
			counter++;
		}

		getIDs(root->args);
		temps = 0;	
		printf("\tjal\t%s\n", root->name+1);
		while (i<counter){
			printf("\tlw\t$t%d, 0($sp)\n", temp);
			printf("\taddiu,\t$sp, $sp, 4\n");
			i++;
			temps++;
		}
		

		
	}else if (root->type == simpleCallNoArgs){
		
		int l = 0;
		int i = 0;
		int counter = 0;
		
		while(l<temps && !containsId(root->args, l)){	
			printf("\taddiu,\t$sp, $sp, -4\n");
			printf("\tsw\t$t%d, 0($sp)\n", l);
			l++;
			counter++;
		}
		
		temps = 0;	
		printf("\tjal\t%s\n", root->name+1);
		while (i<counter){
			printf("\tlw\t$t%d, 0($sp)\n", temp);
			printf("\taddiu,\t$sp, $sp, 4\n");
			i++;
			temps++;
		}
		

		
	}else if (root->type == print){
		if(root->typeNode->type == i){
			printf("\ti_print$ $t%d\n", temps-1);
			temps--;
		}else if (root->typeNode->type == i){
			printf("\tr_print$ $t%d\n", temps-1);
			temps--;
		}else{
			printf("\tb_print$ $t%d\n", temps-1);
			temps--;
		}
	}else if (root->type == mod){
			if (root->args->type==complexId){
				if(root->args->id1->num < root->args->args->id1->num){
					printf("\tdiv\t$t%d, $t%d\n", temps-2, temps-1);
					printf("\tmfhi\t$t%d\n", temps-2);
				}else{
					printf("\tdiv\t$t%d, $t%d\n", temps-1, temps-2);
					printf("\tmfhi\t$t%d\n", temps-2);	
				}
			}
			tempValues[temps-2] = root->id->num;
			temps--;
		}
}


void nodeId(Id *root){
//	printf("Id\n");
	if (root->type == temp){
		printf("$t%d", root->num);

	}else if(root->type == floatingPoint){
		printf("$f%d", root->num);

	}else if(root->type == name){
		printf("%s", root->name+1);
	}

}

void nodeArgs(Args *root){
	if (root->type == simpleId){
		nodeId(root->id1);

	}else if(root->type == complexId){
		nodeId(root->id1);
		printf(", ");
		nodeArgs(root->args);
		
	}else if(root->type == num){
		printf("%d", root->num);

	}else if(root->type == real){
		printf("%lf", root->real);
	}
}

void nodeOp (Op *root){
	printf("Op %d\n", root->type);
}

void nodeJLabel(JLabel *root){
//	printf("jLabel \n");
	if (root->type == label_){
		printf("l$%d:", root->num);

	}else if (root->type == empty){
	//	printf("Empty\n");
	}
}

void nodeType(Type *root){
//	printf("NodeType\n");
	printf("%d\n", root->type);
}


//PRINT FUNCTIONS ARE MADE TO CHECK IF ANY FUNCTION CONTAINS A PRINT ON HIS BODY

void printMoreFunctions(MoreFunctions *root){
	if (root->type == simpleFunction_){
		printBody(root->body);
	}else{
		printBody(root->body);
		printMoreFunctions(root->function->moreFunctions);
	}
}

void printBody(Body *root){
	if(root->type == label){
		printExpression(root->expression);
	}else{
		printExpression(root->moreExpressions->expression);
		printBody(root->moreExpressions->body);
	}
}

void printExpression (Expression *root){
	if (root->type == print){
		if (root->typeNode->type == i && intPrintingFlag == 0){
			intPrintingFlag = 1;
			printf("\n");
			printf("\t# print an integer\n\t.macro i_print$ (int)\n\tor\t$a0, $0, int\n\tori\t$v0, $0, 1\n\tsyscall\n\tori\t$a0, $0, ’n’\n\tori\t$v0, $0, 11\n\tsyscall\n\t.end_macro\n\n");
		}else if (root->typeNode->type == b && boolPrintingFlag == 0){
			boolPrintingFlag = 1;
			printf("\n");
			printf("\t.data\ntrue\t.asciiz true \nfalse:\t.asciiz false\n\t.word false true\n\t# print a boolean value\n\n\t.macro b_print$ (bool)\n\tla\t$a0, bool$\n\tsll\t$v0, bool, 2\n\taddu\t$a0, $a0, $v0\n\tlw\t$a0, 0($a0)\n\tori\t$v0, $0, 4\n\tsyscall\n\t.end_macro\n\n");
		}else if(root->typeNode->type == r && realPrintingFlag == 0){
			realPrintingFlag = 1;
			printf("\n");
			printf("# print a (double precision) real\n\t.macro r_print$ (real)\n\tmov.d $f12, real\n\tori\t$v0, $0, 3\n\tsyscall\n\tori\t$a0, $0, ’\n’\n\tori\t$v0, $0, 11\n\tsyscall\n\t.end_macro\n\n");
		}
	}
} 

void getIDs(Args *root){
	if(root->type == simpleId){
		int x = tempValueSearch(root->id1->num);
		printf("\taddiu,\t$sp, $sp, -4\n");
		printf("\tsw\t$t%d, 0($sp)\n", x);
	}else if(root->type == complexId){
		int x = tempValueSearch(root->id1->num);
		getIDs(root->args);
		printf("\taddiu,\t$sp, $sp, -4\n");
		printf("\tsw\t$t%d, 0($sp)\n", x);
	}
}


int tempValueSearch(int val){
	int i;
	for(i=0; i<10;  i++){
		if(tempValues[i] == val){
			return i;
		}
	}
	return -1;
}

int containsId(Args *root, int val){
	int result = 0;
	int x = tempValueSearch(root->id1->num);
	if(root->type == simpleId){
		if(x == val){
			return 1;
		}
	}else if(root->type == complexId){
		if(x == val){
			return 1;
		}
		result = containsId(root->args, val);
	}
	return result;
}