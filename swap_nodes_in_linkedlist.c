#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *insert(node *);
node *swap(node *);
node *output(node *);

int main() {
    node *head;
    int n, i;
    printf("\nEnter the number of elements of the node: ");
    scanf("%d", &n);
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
    for (i = 0; i < n; i++) {
        head = insert(head);
    }
    head = swap(head);
    head = output(head);
    return 0;
}

node* insert(node* head) {
    node *temp, *root = head;
    while(head->next) {
        head = head->next;
    }
    printf("\nEnter the element of the node: ");
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->next = NULL;
    head->next = temp;
    return root;
}

node* output(node* head) {
    node *root = head;
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    return root;
}

node* swap(node* head) {
    head = head->next;
    node *temp1, *temp2, *root = head->next;
    while(head && head->next) {
        temp1 = head->next;
        temp2 = temp1->next;
        if(temp2==NULL) {
            temp1->next = head;
            head->next = NULL;
            break;
        }
        if(temp2->next==NULL) {
            temp1->next = head;
            head->next = temp2;
            break;
        }
        temp1->next = head;
        head->next = temp2->next;
        head = temp2;
    }
    return root;
}