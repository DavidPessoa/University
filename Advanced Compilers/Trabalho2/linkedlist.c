#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	struct Node *next;
	struct Node *functionVars;
	struct Node *functionArgs;
	int num;
	char *name;
	int temp;
};

Node *initializeNode(){
	Node *n = malloc(sizeof(Node));
	Node *s = malloc(sizeof(Node));
	Node *l = malloc(sizeof(Node));
	n->functionArgs = s;
	n->functionVars = l;
	return n;
}

int sizeList(Node *root, int startSize){
	if(root->name!= NULL){
		startSize++;
		if(root->next != NULL){
			startSize = sizeList(root->next, startSize);
		}
	}
	return startSize;
}


void addElement(Node *root, int value, char *name){
	if(root->name == NULL){
		root->name = name;
		root->num = value;
	}else if(root->next != NULL){
		addElement(root->next, value, name);
	}else if (root->next == NULL){
		root->next = initializeNode();
		root->next->num = value;
		root->next->name = name;
		return;
	}
}

Node *lookforNode(Node *root, char *name){
	Node *x = NULL;
	if (root->name != NULL){
		while(strcmp(root->name, name) !=0){
			if (root->next != NULL){
			   x = lookforNode(root->next, name);
			}
			return x;
		}
		return root;
	}
	return x;
}

int lookforChar(Node *root, char *name){
	int x = -1;
	if (root->name != NULL){
		while(strcmp(root->name, name) !=0){
			if (root->next != NULL){
			   x = lookforChar(root->next, name);
			}
			return x;
		}
		return root->num;
	}
	return x;
}

int lastElement(Node *root){
	int x = -1;
	if (root->next != NULL){
	   x = lastElement(root->next);
	}
	if (root->next == NULL)
	{
		x = root->num;
	}
	return x;
}


char *lookforNum(Node *root, int num){
	char *x = NULL;
		while(root->num != num){
			if (root->next != NULL){
			   x = lookforNum(root->next, num);
			}
			return x;
		}
		return root->name;
}


int contains(Node *root, int num){
	int result = 0;
	if (root->temp == num){
		return 1;
	
	}else if (root->next != NULL){
		result = contains(root->next, num);
		return result;
	}
	return 0;
}


void deleteAll(Node *root){
	while(root->next != NULL){
		deleteAll(root->next);
		free(root->next);
		free(root->functionArgs);
		free(root->functionVars);
		root->functionVars = NULL;
		root->functionArgs = NULL;
		root->next = NULL;
		root->name = NULL;
		root->num = 0;
		return;
	}
}


/*
int main(){
	
	Node *root = malloc(sizeof(Node));
	addElement (root, 4, "@b");
	addElement(root,8,"@c");
	addElement(root,9, "ld");
	//char *x = lookforNum(root, 4);
	int x =	contains(root, 8);
	printf("%d\n", x);
}*/