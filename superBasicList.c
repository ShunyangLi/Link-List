// Basic linked list demo
// Andrew Bennett <andrew.bennett@unsw.edu.au>
// 2017-10-09

#include <stdio.h>
#include <stdlib.h>


// We need to typedef this first
typedef struct _node *Node;
typedef struct _list *List;

// The list struct -- holds a pointer to the "head" of the list
// (the first node).
typedef struct _list {
    Node head;
} list;

// The node struct -- holds some value, and a pointer to the next
// node in the list.
typedef struct _node {
    int value;
    Node next;
} node;

Node newNode (int value);

int main (int argc, char *argv[]) {
    // What might we want to do?

    // Create a new node.
    
    // ( 8 )      ( 42 )
    Node first = newNode(8);
    Node second = newNode(42);
    Node third = newNode(17);
    Node fourth = newNode(12345);
    
    // ( 8 )  ->  ( 42 )
    first->next = second;
    
    // ( 8 )  ->  ( 42 )  ->  ( 17 )
    second->next = third;
    first->next->next = third;
    first->next->next->next = fourth;
    first->next->next->next->next = NULL;
    
    // Create a new list.
    List list = calloc(1, sizeof(struct _list));
    
    
    // [  ] -> ( 8 )  ->  ( 42 )  ->  ( 17 )  ->  ( 12345 )  ->  X
    list -> head = first;
    
    
    // Print out a list?
    
    int array[5] = {8, 42, 17, 12345, 1};
    int i = 0;
    printf("the array contains: ");
    while (i < 5) {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    
    //  list                           curr
    //   v                               v
    // [  ] -> ( 8 )  ->  ( 42 )  ->  ( 17 )  ->  ( 12345 )  ->  X
    printf("the list contains: ");
    Node curr = list->head;

    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr -> next;
    } 
    printf("\n");
    
    // Insert a node at the start of a list.
    
    // 1. allocate a new node
    Node new = newNode(3);
    // 2. make its next be the head of the list
    new -> next = list -> head;
    // 3. make the list's head be the new node
    list -> head = new;
    
    printf("the list contains: ");
    curr = list->head;

    while (curr != NULL) {
        printf("%d ", curr -> value);
        curr = curr -> next;
    } 
    printf("\n");
    
    // [  ] -> ( 3 ) -> ( 8 )  ->  ( 42 )  ->  ( 17 )  ->  ( 12345 )  ->  X
    // 17:     list->head->next->next->next
    // 42:     list->head->next->next
    
    // Insert a node at the end of a list.
    Node seventeen = list->head->next->next->next;
    Node fourtyTwo = list->head->next->next;
    
    fourtyTwo -> next = seventeen -> next;
    
    printf("the list contains: ");
    curr = list -> head;

    while (curr != NULL) {
    
        printf("%d ", curr->value);
        curr = curr -> next;
        
    } 
    printf("\n");


    // Find a certain node in the list?
    // Determine the length of the list?
    // Calculate the sum of all values in the list?


    // Destroy a node. ("each alloc must have an equal and opposite free")
    free(first);
    
    // Destroy a list.
    free(list);


    return EXIT_SUCCESS;
}



Node newNode (int value) {
    Node new = calloc(1, sizeof(struct _node));
    new -> value = value;
    return new;
}

void nothing() {
    Node third = calloc(1, sizeof(struct _node));
    third -> value = 17;
    
    Node fourth = calloc(1, sizeof(struct _node));
    fourth -> value = 12345;
}

