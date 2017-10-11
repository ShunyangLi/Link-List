#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void listDeleteHead (List l) {

	Node pNow;
	pNow = calloc(1,sizeof(node));
	
	if(l -> head == NULL) {
		
	} else {
		pNow = l -> head;
		l -> head = pNow -> next;
		free(pNow);
	}
}
