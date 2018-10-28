#include "linkedlist.h"


int counter = 0;


LinkedList *newLinkedList(char *s){
	LinkedList *l = malloc(sizeof(LinkedList));
	LinkedNode *head = malloc(sizeof(LinkedNode));
	l->head = head;
	l->head->s = s;
	l->head->next = NULL;
}

void add(LinkedList l, char *s){
	
	LinkedNode *next = malloc(sizeof(ListNode));
	next->s = s;
	next->next = NULL;
	ListNode *currentNode = l->head;
	while(currentNode->next != NULL){
		currentNode = currentNode-> next;
	}
	currentNode->next = next;
}

void printList(LinkedList l){
	ListNode *currentNode = l -> head;
	while(currentNode != NULL){
		printf("%s\n", currentNode-> s);
		currentNode = currentNode-> next;
	}
}