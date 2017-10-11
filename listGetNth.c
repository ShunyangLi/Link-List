#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int listGetNth (List l, int n) {

	int i = 0;
	Node temp = calloc(1,sizeof(node));
	
	if(l -> head == NULL) {
		return 0;
	} else {
		temp = l -> head;
		while(temp != NULL) {
			
			if(n == i) {
				return temp -> value;
			}
			
			i++;
			temp = temp -> next;
		}
	}
}

