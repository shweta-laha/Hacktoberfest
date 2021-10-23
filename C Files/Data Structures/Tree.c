#include <stdio.h>
#include <stdlib.h>

// Struct to define structure of nodes of a tree
// In general A tree node will have a parent , a data
// and It might have children
typedef struct tree_node
{
    char data;
    struct tree_node *right;
    struct tree_node *left;
    struct tree_node *parent;
} tree_node;

// Initializing Tree Node with Data
tree_node *new_tree_node(char data)
{
    tree_node *n = (tree_node *)malloc(sizeof(tree_node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    n->parent = NULL;

    return n;
}

// Structure of the Tree
// In Genral we will only define the root of the tree
// the root will be a tree_node so it will contain all the properties of Tree_Node
typedef struct tree
{
    tree_node *root;
} tree;

// Initializing A new tree with root
tree *new_tree(tree_node *n)
{
    tree *t = (tree *)malloc(sizeof(tree));
    t->root = n;

    return t;
}

// Inorder Style of Traversal on a tree
void inorder(tree_node *n)
{
    if (n != NULL)
    {
        inorder(n->left);
        printf(" %c ", n->data);
        inorder(n->right);
    }
}

// Main Function
int main()
{
    /*

             D
            / \
           /   \
          /     \
         A       F
        / \     / \
       /   \   /   \
      E     B R     T
     / \     /     / \
    G   Q   V     J   L
    */

    tree_node *d, *a, *f, *e, *b, *r, *t1, *g, *q, *v, *j, *l;
    d = new_tree_node('D');
    a = new_tree_node('A');
    f = new_tree_node('F');
    e = new_tree_node('E');
    b = new_tree_node('B');
    r = new_tree_node('R');
    t1 = new_tree_node('T');
    g = new_tree_node('G');
    q = new_tree_node('Q');
    v = new_tree_node('V');
    j = new_tree_node('J');
    l = new_tree_node('L');

    tree *t = new_tree(d);

    t->root->right = f;
    t->root->left = a;

    /*

           D
          / \
         /   \
        /     \
       A       F
    */

    a->right = b;
    a->left = e;

    f->right = t1;
    f->left = r;

    e->right = q;
    e->left = g;

    r->left = v;

    t1->right = l;
    t1->left = j;

    printf("\nNodes of the tree are:\n");
    inorder(t->root);
    printf("\n");

    return 0;
}