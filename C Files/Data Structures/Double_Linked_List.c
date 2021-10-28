#include <stdio.h>
#include <stdlib.h>

// Struct to define Node
// A node struct contains a data
// and two node pointers next and prev
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

// Struct to define Linked List
typedef struct linked_list
{
    struct node *head;
} linked_list;

// to make new node
node *new_node(int data)
{
    node *z;
    z = (node *)malloc(sizeof(struct node));
    z->data = data;
    z->next = NULL;
    z->prev = NULL;

    return z;
}

// to make a new linked list
linked_list *new_linked_list(int data)
{
    node *a; // new node for head of linked list
    a = new_node(data);

    linked_list *l = (linked_list *)malloc(sizeof(linked_list)); // linked list
    l->head = a;

    return l;
}

void traversal(linked_list *l)
{
    node *temp = l->head; // temporary pointer to point to head

    while (temp != NULL)
    { // iterating over linked list
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// new node before head
void insert_at_front(linked_list *l, node *n)
{
    n->next = l->head;
    l->head->prev = n;
    l->head = n;
}

// insert new node at last
void insert_at_tail(linked_list *l, node *n)
{
    node *temp = l->head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

// function to insert a node after a node
void insert_after(node *n, node *a)
{
    n->next = a->next;
    a->next->prev = n;
    a->next = n;
    n->prev = a;
}

// function to delete
void del(linked_list *l, node *a)
{
    if (a->prev != NULL)
    { // node is not head
        a->prev->next = a->next;
    }
    else
    { // node a is head
        l->head = a->next;
    }

    if (a->next != NULL)
    {
        a->next->prev = a->prev;
    }
    free(a);
}

int main()
{
    linked_list *l = new_linked_list(10);

    node *a, *b, *c; // new nodes to insert in linekd list
    a = new_node(20);
    b = new_node(50);
    c = new_node(60);

    // connecting to linked list
    /*
       ----     ----     ----     ----
      |head|-->| a  |-->|  b |-->|  c |-->NULL
      |____|   |____|   |____|   |____|
    */
    l->head->next = a;
    a->next = b;
    b->next = c;

    printf("The Nodes of the List are before adding More Nodes is:\n");
    traversal(l);

    node *z;

    z = new_node(0);
    insert_at_front(l, z);
    z = new_node(-10);
    insert_at_front(l, z);

    z = new_node(100);
    insert_at_tail(l, z);

    z = new_node(30);
    insert_after(z, a);
    z = new_node(40);
    insert_after(z, a->next);
    z = new_node(500);
    insert_after(z, a->next->next);

    printf("The Nodes of the List are:\n");
    traversal(l);

    printf("The Nodes of the list after Traversal are:\n");
    del(l, l->head);
    del(l, z);
    traversal(l);

    return 0;
}