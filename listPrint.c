#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void listPrint (List l) {

	int i = 0;
	Node temp = calloc(1,sizeof(node));
	
	if(l -> head == NULL) {
		printf("X");
	} else {
	
		temp = l -> head;
		while(temp != NULL) {
		
			printf("%d -> ",temp -> value);
			temp = temp -> next;
		}
		
		printf("X");
	}
	printf("\n");
	
}
