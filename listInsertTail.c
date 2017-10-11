#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node newNode (int value);

void listInsertTail (List l, int val) {
	
	Node new = calloc(1,sizeof(node));
	Node temp = calloc(1,sizeof(node));
	Node before = calloc(1,sizeof(node));
	new -> value = val;
	
	temp = l -> head;
	if(l -> head == NULL) {
		l -> head = new;
	} else {
		while(temp != NULL) {
		
			before = temp;
			temp = temp -> next;
		}
		before -> next = new;
	}
	
}
Node newNode (int value) {
    Node new = calloc(1, sizeof(struct _node));
    new -> value = value;
    return new;
}
