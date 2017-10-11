#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int listContains (List l, int val) {
	
	Node temp = calloc(1,sizeof(node));
	
	if(l -> head == NULL) {
		return 0;
	} else {
		temp = l -> head;
		while(temp != NULL) {
			
			if(temp -> value == val) {
				return TRUE;
			}
			temp = temp -> next;
		}
		
		return FALSE;
	}
	
}
