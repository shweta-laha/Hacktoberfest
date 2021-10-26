// AVL tree is a Self balancing tree
/* AVL (Adelson-Velskii and Landis) trees are also binary search trees
which are pretty good balanced. AVL trees use different rules to achieve that balance.

AVL trees use balance factor to get a balanced tree.
 Balance factor of any node is defined as height(left subtree) - height(right subtree).*/

#include <stdio.h>
#include <stdlib.h>

// Struct to define Structure of AVL_NODE
// The Height Parameter in avl_node helps in
// defining the height of the current node
// With the height of node we will be able to rotate the node
// If the Balance Factor become > 1 or < -1
typedef struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
    struct avl_node *parent;
    int height;
} avl_node;

// General Struct of AVL_TREE
// It only has a avl_node which will be
// the root of the tree
typedef struct avl_tree
{
    avl_node *root;
} avl_tree;

// Used to initialize the AVL Node of the tree
avl_node *new_avl_node(int data)
{
    avl_node *n = (avl_node *)malloc(sizeof(avl_node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    n->height = 0;

    return n;
}

// Function to initialize AVL_TREE
avl_tree *new_avl_tree()
{
    avl_tree *t = (avl_tree *)malloc(sizeof(avl_tree));
    t->root = NULL;

    return t;
}

// To return maximum of two values
int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

// Function to return THe height of the Node
int height(avl_node *n)
{
    if (n == NULL)
        return -1;
    return n->height;
}

// To return the minimum node in our tree
avl_node *minimum(avl_tree *t, avl_node *x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}

// Function to rotate Left
void left_rotate(avl_tree *t, avl_node *x)
{
    avl_node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    { // x is root
        t->root = y;
    }
    else if (x == x->parent->left)
    { // x is left child
        x->parent->left = y;
    }
    else
    { // x is right child
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
}

// Function to rotate right
void right_rotate(avl_tree *t, avl_node *x)
{
    avl_node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    { // x is root
        t->root = y;
    }
    else if (x == x->parent->right)
    { // x is left child
        x->parent->right = y;
    }
    else
    { // x is right child
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
}

int balance_factor(avl_node *n)
{
    if (n == NULL)
        return 0;
    return (height(n->left) - height(n->right));
}

// Function to insert the node in the tree
// It takes to parameters
// A pointer to the tree
// and then a node
void insert(avl_tree *t, avl_node *n)
{
    avl_node *y = NULL;
    avl_node *temp = t->root;
    while (temp != NULL)
    {
        y = temp;
        if (n->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    n->parent = y;

    if (y == NULL) // newly added node is root
        t->root = n;
    else if (n->data < y->data)
        y->left = n;
    else
        y->right = n;

    avl_node *z = n;

    while (y != NULL)
    {
        y->height = 1 + max(height(y->left), height(y->right));

        avl_node *x = y->parent;

        if (balance_factor(x) <= -2 || balance_factor(x) >= 2)
        { // grandparent is unbalanced
            if (y == x->left)
            {
                if (z == x->left->left) // case 1
                    right_rotate(t, x);

                else if (z == x->left->right)
                { // case 3
                    left_rotate(t, y);
                    right_rotate(t, x);
                }
            }
            else if (y == x->right)
            {
                if (z == x->right->right) // case 2
                    left_rotate(t, x);

                else if (z == x->right->left)
                { // case 4
                    right_rotate(t, y);
                    left_rotate(t, x);
                }
            }
            break;
        }
        y = y->parent;
        z = z->parent;
    }
}

void transplant(avl_tree *t, avl_node *u, avl_node *v)
{
    if (u->parent == NULL) // u is root
        t->root = v;
    else if (u == u->parent->left) // u is left child
        u->parent->left = v;
    else // u is right child
        u->parent->right = v;

    if (v != NULL)
        v->parent = u->parent;
}

// This function is necessary so that when a node is deleted
// And the balance factor changes
// This Function will Rotate the nodes
// To maintain the balance Factor
void avl_delete_fixup(avl_tree *t, avl_node *n)
{
    avl_node *p = n;

    while (p != NULL)
    {
        p->height = 1 + max(height(p->left), height(p->right));

        if (balance_factor(p) <= -2 || balance_factor(p) >= 2)
        { // grandparent is unbalanced
            avl_node *x, *y, *z;
            x = p;

            // taller child of x will be y
            if (x->left->height > x->right->height)
                y = x->left;
            else
                y = x->right;

            // taller child of y will be z
            if (y->left->height > y->right->height)
            {
                z = y->left;
            }
            else if (y->left->height < y->right->height)
            {
                z = y->right;
            }
            else
            { // same height, go for single rotation
                if (y == x->left)
                    z = y->left;
                else
                    z = y->right;
            }

            if (y == x->left)
            {
                if (z == x->left->left) // case 1
                    right_rotate(t, x);

                else if (z == x->left->right)
                { // case 3
                    left_rotate(t, y);
                    right_rotate(t, x);
                }
            }
            else if (y == x->right)
            {
                if (z == x->right->right) // case 2
                    left_rotate(t, x);

                else if (z == x->right->left)
                { // case 4
                    right_rotate(t, y);
                    left_rotate(t, x);
                }
            }
        }
        p = p->parent;
    }
}

// Function to Delete a node From the tree
void avl_delete(avl_tree *t, avl_node *z)
{
    if (z->left == NULL)
    {
        transplant(t, z, z->right);
        if (z->right != NULL)
            avl_delete_fixup(t, z->right);
        free(z);
    }
    else if (z->right == NULL)
    {
        transplant(t, z, z->left);
        if (z->left != NULL)
            avl_delete_fixup(t, z->left);
        free(z);
    }
    else
    {
        avl_node *y = minimum(t, z->right); // minimum element in right subtree
        if (y->parent != z)
        {
            transplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
        if (y != NULL)
            avl_delete_fixup(t, y);
        free(z);
    }
}

// To print nodes of the tree in an Inorder Fashion
void inorder(avl_tree *t, avl_node *n)
{
    if (n != NULL)
    {
        inorder(t, n->left);
        printf("%d ", n->data);
        inorder(t, n->right);
    }
}

// Main Function
int main()
{
    // AVL tree Initialized
    avl_tree *t = new_avl_tree();

    // Differennt AVL Nodes Initialized
    avl_node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

    // Initialzing Nodes with Different Values
    a = new_avl_node(10);
    b = new_avl_node(20);
    c = new_avl_node(30);
    d = new_avl_node(100);
    e = new_avl_node(90);
    f = new_avl_node(40);
    g = new_avl_node(50);
    h = new_avl_node(60);
    i = new_avl_node(70);
    j = new_avl_node(80);
    k = new_avl_node(150);
    l = new_avl_node(110);
    m = new_avl_node(120);

    // Inserting Nodes in the tree;
    // If the tree_node is null
    // We have Designed This Function in such a way
    // Then the first node to be inserted will become the Root
    // By Default
    insert(t, a);
    insert(t, b);
    insert(t, c);
    insert(t, d);
    insert(t, e);
    insert(t, f);
    insert(t, g);
    insert(t, h);
    insert(t, i);
    insert(t, j);
    insert(t, k);
    insert(t, l);
    insert(t, m);

    avl_delete(t, a);
    avl_delete(t, m);

    printf("The Nodes of the Tree Are: \n");
    // Function to return Nodes in Inorder Fashion
    inorder(t, t->root);
    printf("\n");

    return 0;
}