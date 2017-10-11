#include <stdio.h>
#include <stdlib.h>

typedef struct _node *Node;
typedef struct _list *List;

typedef struct _list {
    Node head;
} list;

typedef struct _node {
    int value;
    Node next;
} node;

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


int main(int argc, char *argv[]) {
	
	Node first = newNode(1);
    Node second = newNode(3);
    Node third = newNode(5);
    Node fourth = newNode(7);
    Node temp = calloc(1,sizeof(node));
    
	first -> next = second;
    second -> next = third;
    first -> next -> next = third;
    first -> next -> next -> next = fourth;
    first -> next -> next -> next -> next = NULL;
    
    List list = calloc(1, sizeof(struct _list));
    list -> head = first;
    
    int len = listLength(list);
    printf("The length of this list is: %d\n",len);
    
    listPrint(list);
    
    for(int x = 0; x < len; x ++) {
    	
    	int value = listGetNth(list,x);
    	printf("The No %d value is: %d\n",x+1, value);
    }
    printf("\n");
    
    for(int x = 0; x < 9; x ++) {
    	if(listContains(list,x)) {
    	
    		printf("This is list has the value: %d\n",x);
    	} else {
    		printf("This is list does not have the value: %d\n",x);
    	}
    }
    printf("\n");
    
    printf("Put a new elements in the header: %d\n",0);
    listInsertHead(list,0);
    listPrint(list);
    printf("Put another new elements in the header: %d\n",5);
    listInsertHead(list,5);
    listPrint(list);
    len = listLength(list);
    printf("Now the length of this list is: %d\n\n",len);
    
    
    printf("Put a new elements in the end: %d\n",10);
    listInsertTail(list,10);
    listPrint(list);
    len = listLength(list);
    printf("Now the length of this list is: %d\n\n",len);
    
    printf("Delete an element from the header.\n");
    listDeleteHead(list);
    listPrint(list);
    len = listLength(list);
    printf("Now the length of this list is: %d\n\n",len);
    
	printf("Delete an element from the end.\n");
	listDeleteTail(list);
    listPrint(list);
    len = listLength(list);
    printf("Now the length of this list is: %d\n\n",len);
    
    if(listIsOrdered(list)) {
    	printf("This is in order.\n\n");
    } else {
    	printf("This is not in order.\n\n");
    }
    
    printf("Delete the 1st element from the list.\n");
    listDeleteNth(list,4);
    listPrint(list);
    len = listLength(list);
    printf("Now the length of this list is: %d\n\n",len);
    
    printf("Add a element into the list.\n");
    listInsertNth(list,0,1);
    listPrint(list);
    len = listLength(list);
    printf("Now the length of this list is: %d\n\n",len);
    
    
    int num = listGetMiddle(list);
    printf("The middle value of the list is: %d\n\n",num);
    
    if(listCountFavourite(list)) {
    	
    	printf("There are favourite number\n\n");
    } else {
    	
    	printf("There are not favourite number.\n\n");
    }
    
    printf("This is the test of list insert head:\n");
    Node new = calloc(1,sizeof(node));
    new = NULL;
    list -> head = new;
    listInsertHead(list,1);
    listPrint(list);
    printf("%p\n",list -> head);
    printf("%p\n", new);
    printf("\n");
    
    printf("This is the test of list insert tail\n");
    listInsertTail(list,2);
    listPrint(list);

    printf("This is the test of list insert tail if it is NULL:\n");
    listDeleteHead(list);
    listDeleteHead(list);
    listInsertTail(list,2);
    listPrint(list);

    Node new1 = calloc(1,sizeof(node));
    new1 = newNode(3);
    list -> head = new1;

    printf("This is the list before delete:\n");
    listPrint(list);
    printf("This is the test after delete from the head:\n");
    listDeleteHead(list);
    listPrint(list);
    printf("%p\n",list -> head);

}

