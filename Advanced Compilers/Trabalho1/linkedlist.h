#include <stdio.h>
#include <string.h>

typedef struct LinkedList LinkedList ;
typedef struct ListNode	ListNode;


struct ListNode
{
	char *s;
	struct ListNode *next;
};


struct LinkedList
{
	ListNode *head;
};