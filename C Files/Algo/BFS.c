#include <stdio.h>
#include <stdlib.h>

// We define Color Enum to mark states of nodes
// as not discovered , discovered and Visited
enum color
{
    White,
    Gray,
    Black
};

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
    enum color colr;
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

node *new_node(int data)
{
    node *z;
    z = (node *)malloc(sizeof(node));
    z->data = data;
    z->head = NULL;
    z->colr = White;

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

// function to check of the node is in the head array of graph or not
int in_graph_head_list(graph *g, int data)
{
    int i;
    for (i = 0; i < g->number_of_vertices; i++)
    {
        if (g->heads[i].data == data)
            return 1;
    }
    return 0;
}

// function to add edge
void add_edge(graph *g, int source, int dest)
{
    // if source or edge is not in the graph, add it
    if (!in_graph_head_list(g, source))
    {
        add_node_to_graph(g, source);
    }
    if (!in_graph_head_list(g, dest))
    {
        add_node_to_graph(g, dest);
    }

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
}

void print_graph(graph *g)
{
    int i;
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

// Struct to define queue Node
// This will be a node which will be stored in Queue
typedef struct queue_node
{
    node *n;
    struct queue_node *next;
} queue_node;

// Struct for Queue
struct queue
{
    int count;
    queue_node *front;
    queue_node *rear;
};
typedef struct queue queue;

int is_empty_queue(queue *q)
{
    return !(q->count);
}

void enqueue(queue *q, node *n)
{
    queue_node *new_queue_node;
    new_queue_node = (queue_node *)malloc(sizeof(queue_node));
    new_queue_node->n = n;
    new_queue_node->next = NULL;
    if (!is_empty_queue(q))
    {
        q->rear->next = new_queue_node;
        q->rear = new_queue_node;
    }
    else
    {
        q->front = q->rear = new_queue_node;
    }
    q->count++;
}

queue_node *dequeue(queue *q)
{
    queue_node *tmp;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    return tmp;
}

queue *make_queue()
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void print_queue(queue *q)
{
    queue_node *tmp;
    tmp = q->front;
    while (tmp != NULL)
    {
        printf("%d\t", tmp->n->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void bfs(graph *g)
{
    // here, we are using first node as source
    node s = g->heads[0];
    int i;
    for (i = 0; i < g->number_of_vertices; i++)
    {
        g->heads[i].colr = White;
    }
    s.colr = Gray;

    queue *q = make_queue();
    enqueue(q, &s);
    printf("\nThe Nodes in the Graph in BFS Order Are:\n");
    while (!is_empty_queue(q))
    {
        // print_queue(q);
        queue_node *u = dequeue(q);
        list_node *temp;
        temp = u->n->head;
        while (temp != NULL)
        {
            if (g->heads[temp->index_of_item].colr == White)
            {
                g->heads[temp->index_of_item].colr = Gray;
                enqueue(q, &g->heads[temp->index_of_item]);
            }
            temp = temp->next;
        }
        u->n->colr = Black;
        printf("%d\t", u->n->data);
    }
    printf("\n");
}

int main()
{
    graph *g = new_graph(7);
    add_edge(g, 1, 2);
    add_edge(g, 1, 5);
    add_edge(g, 1, 3);
    add_edge(g, 2, 6);
    add_edge(g, 2, 4);
    add_edge(g, 5, 4);
    add_edge(g, 3, 4);
    add_edge(g, 3, 7);
    bfs(g);
    return 0;
}