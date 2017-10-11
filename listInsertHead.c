#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void listInsertHead (List l, int val) {
	
	Node new = calloc(1,sizeof(node));
	new -> value = val;
	
	new -> next = l -> head;
	l -> head = new; 
}

