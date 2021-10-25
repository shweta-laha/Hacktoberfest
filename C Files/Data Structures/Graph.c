#include <stdio.h>
#include <stdlib.h>

/*
Node for linked list of adjacent elements.
This will contain a pointer for next node.
It will not contain the real element but the index of
element of the array containing all the vertices V.
*/
typedef struct list_node
{
    int index_of_item;
    struct list_node *next;
} list_node;

/*
Node to store the real element.
Contain data and pointer to the
first element (head) of the adjacency list.
*/
typedef struct node
{
    int data;
    list_node *head;
} node;

/*
Graph will contain number of vertices and
an array containing all the nodes (V).
*/
typedef struct graph
{
    int number_of_vertices;
    node heads[]; // array of nodes to store the list of first nodes of each adjacency list
} graph;

/*
array heads      Adjacency list. contain index and next
contain data
and head of
adjacency list
____            ____    ____    ____
|node|    ----> |list|->|    |->|    |
|____|          |node|  |____|  |____|
____            ____    ____    ____
|    |    ----> |    |->|    |->|    |
|____|          |____|  |____|  |____|
____            ____    ____    ____
|    |    ----> |    |->|    |->|    |
|____|          |____|  |____|  |____|
____            ____    ____    ____
|    |    ----> |    |->|    |->|    |
|____|          |____|  |____|  |____|

*/

node *new_node(int data)
{
    node *z;
    z = (node *)malloc(sizeof(node));
    z->data = data;
    z->head = NULL;

    return z;
}

list_node *new_list_node(int item_index)
{
    list_node *z;
    z = (list_node *)malloc(sizeof(list_node));
    z->index_of_item = item_index;
    z->next = NULL;

    return z;
}

// make a new graph
graph *new_graph(int number_of_vertices)
{
    // number_of_vertices*sizeof(node) is the size of the array heads
    graph *g = (graph *)malloc(sizeof(graph) + (number_of_vertices * sizeof(node)));
    g->number_of_vertices = number_of_vertices;

    // making elements of all head null i.e.,
    // their data -1 and next null
    int i;
    for (i = 0; i < number_of_vertices; i++)
    {
        node *z = new_node(-1); //*z is pointer of node. z stores address of node
        g->heads[i] = *z;       //*z is the value at the address z
    }

    return g;
}

// function to add new node to graph
void add_node_to_graph(graph *g, int data)
{
    // creating a new node;
    node *z = new_node(data);
    // this node will be added into the heads array of the graph g
    int i;
    for (i = 0; i < g->number_of_vertices; i++)
    {
        // we will add node when the data in the node is -1
        if (g->heads[i].data < 0)
        {
            g->heads[i] = *z; //*z is the value at the address z
            break;            // node is added
        }
    }
}

// function to add edge
void add_edge(graph *g, int source, int dest)
{
    int i, j;
    // iterating over heads array to find the source node
    for (i = 0; i < g->number_of_vertices; i++)
    {
        if (g->heads[i].data == source)
        { // source node found

            int dest_index; // index of destination element in array heads
            // iterating over heads array to find node containg destination element
            for (j = 0; j < g->number_of_vertices; j++)
            {
                if (g->heads[j].data == dest)
                { // destination found
                    dest_index = j;
                    break;
                }
            }

            list_node *n = new_list_node(dest_index); // new adjacency list node with destination index
            if (g->heads[i].head == NULL)
            { // no head, first element in adjaceny list
                g->heads[i].head = n;
            }
            else
            { // there is head which is pointer by the node in the head array
                list_node *temp;
                temp = g->heads[i].head;

                // iterating over adjaceny list to insert new list_node at last
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = n;
            }
            break;
        }
    }

    // if the graph is undirected, there will also be edge from dest to source
    for (i = 0; i < g->number_of_vertices; i++)
    {
        if (g->heads[i].data == dest)
        {

            int source_index;

            for (j = 0; j < g->number_of_vertices; j++)
            {
                if (g->heads[j].data == source)
                {
                    source_index = j;
                    break;
                }
            }

            list_node *n = new_list_node(source_index);
            if (g->heads[i].head == NULL)
            {
                g->heads[i].head = n;
            }
            else
            {
                list_node *temp;
                temp = g->heads[i].head;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = n;
            }
            break;
        }
    }
}

void print_graph(graph *g)
{
    int i;
    printf("The Graph Nodes are:\n");
    for (i = 0; i < g->number_of_vertices; i++)
    {
        list_node *temp;
        temp = g->heads[i].head;
        printf("%d\t", g->heads[i].data);
        while (temp != NULL)
        {
            printf("%d\t", g->heads[temp->index_of_item].data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main Function
int main()
{
    graph *g = new_graph(4);
    add_node_to_graph(g, 1);
    add_node_to_graph(g, 2);
    add_node_to_graph(g, 3);
    add_node_to_graph(g, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 2);
    print_graph(g);
    return 0;
}