#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _node *Node;
typedef struct _list *List;

typedef struct _list {
    Node head;
} list;

typedef struct _node {
    int value;
    Node next;
} node;

#define FALSE 0
#define TRUE (!FALSE)

int listLength (List l);
Node newNode (int value);
void listPrint (List l);
int listGetNth (List l, int n);
int listContains (List l, int val);
void listInsertHead (List l, int val);
void listInsertTail (List l, int val);
void listDeleteHead (List l);
void listDeleteTail (List l);
Node Find(int k, Node pHead);
int listIsOrdered (List l);
void listDeleteNth (List l, int n);
void listInsertNth (List l, int n, int val);
int listGetMiddle (List l);
int listCountFavourite (List l);
int listIsOrdered (List l);

void listDeleteNth (List l, int n) {
	
	if(n == 0) {
	    
	    Node new = l -> head;
	    l -> head = new -> next;
	    free(new);
	    
	} else {
		
		Node pBefore,pAfter;
		pBefore = Find(n,l -> head);
		pAfter = pBefore -> next;
		pBefore -> next = pAfter -> next;
		free(pAfter);
	}
	
	
}

void listInsertNth (List l, int n, int val) {

	Node pBefore,pAfter,pNew;
	pNew = calloc(1,sizeof(node));
	
	if(n == 0) {
		
		listInsertHead(l,val);
	} else if(n >= 1) {

		pBefore = Find(n,l -> head);
		pNew -> value = val;
		pAfter = pBefore -> next;
		pBefore -> next = pNew;
		pNew -> next = pAfter;
	}
	
}

int listGetMiddle (List l) {
	
	Node temp = calloc(1,sizeof(node));
	temp = l -> head;
	
	int i = 0;
	int middle = listLength(l) / 2;
	
	if(temp -> next == NULL) {
		
		return temp -> value;
		
	} else {
		while(temp != NULL && i < middle) {
		
			temp = temp -> next;
			i++;
			
		}
		if(i == middle) {
		
			return temp -> value;
		}
	}
	
}

int listCountFavourite (List l) {
	int num = 17,count = 0;
	Node before = calloc(1,sizeof(node));
	Node temp = calloc(1,sizeof(node));
	temp = l -> head;
	
	if(l -> head == NULL) {
	
	    return count;
	    
	} else {
		while(temp != NULL) {
		
			if(temp -> value % num == 0 && temp -> value != 0) {
			
				count ++;
			}
			
			temp = temp -> next;
		}
	}
	return count;
}

int listIsOrdered (List l) {
	
	int max;
	Node before = calloc(1,sizeof(node));
	Node temp = calloc(1,sizeof(node));
	temp = l -> head;
	
	if(l -> head == NULL) {
	    return TRUE;
	    
	} else if(temp -> next == NULL) {
	    
	    return TRUE;
	} else {
	    
	    max = temp -> value;
	    while(temp != NULL) {
	        
		    if(temp -> value > max) {
		    
			    max = temp -> value;
		    }
		    
		    before = temp;
		    temp = temp -> next;
	    }
	
	    if (max > before -> value){
		    return FALSE;
	    } else if(max == before -> value) {
		    return TRUE;
	    }
	}
}

void listDeleteTail (List l) {
	
	int len;
	Node before = calloc(1,sizeof(node));
	Node End = calloc(1,sizeof(node));
	Node temp = calloc(1,sizeof(node));
	temp = l -> head;
	
	len = listLength(l);
	
	if(len == 0) {
		
	} else if (len == 1) {
		
		Node new = l -> head;
	    l -> head = new -> next;
	    free(new);
		
	} else {
		
		before = Find(len - 1,l -> head);
		End = Find(len,l -> head);
		before -> next = NULL;
		free(End);
		
	}
	
}

Node Find(int k, Node pHead) {
	
	Node temp = pHead;
	int i = 1;
	
	while(temp != NULL && i < k) {
		
		temp = temp -> next;
		i++;
	}
	
	if(i == k && temp != NULL) {
		
		return temp;
	} else {
		
		return NULL;
	}
}

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

void listInsertHead (List l, int val) {
	
	Node new = calloc(1,sizeof(node));
	new -> value = val;
	
	new -> next = l -> head;
	l -> head = new; 
}

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

Node newNode (int value) {
    Node new = calloc(1, sizeof(struct _node));
    new -> value = value;
    return new;
}

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


