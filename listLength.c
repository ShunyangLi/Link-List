#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int listLength (List l) {
	
	int i = 0;
	Node temp = calloc(1,sizeof(node));
	
	if(l -> head == NULL) {
		return 0;
	} else {
		temp = l -> head;
		while(temp != NULL) {
			i++;
			temp = temp -> next;
		}
	}
	
	return i;
}
