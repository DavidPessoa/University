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

Node *initializeNode();
Node *lookforNode(Node *root, char *name);
int sizeList(Node *root, int startSize);
void addElement(Node *root, int value, char *name);
int lookforChar(Node *root, char *name);
char *lookforNum(Node *root, int num);
void deleteAll(Node *root);
int contains(Node *root, int num);