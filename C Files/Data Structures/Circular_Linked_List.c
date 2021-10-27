#include <stdio.h>
#include <stdlib.h>

// Struct to define to Node
typedef struct node
{
    int data;
    struct node *next;
} node;

// Struct to define Circular List
typedef struct circular_list
{
    struct node *last;
} circular_linked_list;

// to make new node
node *new_node(int data)
{
    node *z;
    z = (node *)malloc(sizeof(struct node));
    z->data = data;
    z->next = NULL;

    return z;
}

circular_linked_list *init_circular_linked_list(int key)
{
    node *z;
    z = new_node(key);
    z->next = z;

    circular_linked_list *c = (circular_linked_list *)malloc(sizeof(circular_linked_list));
    c->last = z;
    return c;
}

void insert_after(node *n, node *a)
{
    n->next = a->next;
    a->next = n;
}

void insert_at_last(circular_linked_list *l, node *n)
{
    n->next = l->last->next;
    l->last->next = n;
    l->last = n;
}

void deleteNode(circular_linked_list *l, node *n)
{
    node *temp = l->last;
    while (temp->next != n)
    {
        temp = temp->next;
    }
    if (n == l->last)
    { // last node
        if (n->next == n)
        { // only one node
            l->last = NULL;
        }
        else
        { // more than one node and last node
            temp->next = n->next;
            l->last = temp; // updating last pointer
        }
    }
    else
    { // not last node
        temp->next = n->next;
    }
    free(n);
}

void traversal(circular_linked_list *l)
{
    node *temp = l->last;
    printf("%d\t", temp->data);
    temp = temp->next;

    while (temp != l->last)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    circular_linked_list *l = init_circular_linked_list(10);

    node *a, *b, *c;
    a = new_node(20);
    b = new_node(30);
    c = new_node(40);

    l->last->next = a;
    a->next = b;
    b->next = c;
    c->next = l->last;

    printf("The Original List is:\n");
    traversal(l);

    printf("\nAfter Adding Nodes:\n");
    node *z;
    z = new_node(50);
    insert_after(z, c);
    z = new_node(25);
    insert_after(z, a);
    z = new_node(100);
    insert_at_last(l, z);

    printf("The Nodes in the List after adding operations are:\n");
    traversal(l);

    printf("\nAfter Delete Operations\n");
    deleteNode(l, l->last);
    deleteNode(l, b);
    printf("The Nodes in the List after Delete operations are:\n");
    traversal(l);

    return 0;
}