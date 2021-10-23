#include <stdio.h>
#include <stdlib.h>

int tree_size = 20;
int heap_size = 0;
const int INF = 100000;

// Swap Function
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

// function to get right child of a node of a tree
int get_right_child(int A[], int index)
{
    if ((((2 * index) + 1) < tree_size) && (index >= 1))
        return (2 * index) + 1;
    return -1;
}

// function to get left child of a node of a tree
int get_left_child(int A[], int index)
{
    if (((2 * index) < tree_size) && (index >= 1))
        return 2 * index;
    return -1;
}

// function to get the parent of a node of a tree
int get_parent(int A[], int index)
{
    if ((index > 1) && (index < tree_size))
    {
        return index / 2;
    }
    return -1;
}

// Max Heapify function
// Whenever we remove a element is removed or inserted from heap
// This function will heapify the mean which means all the nodes will be arranged
// in such a way that the children of that node are smaller the the parent node
void max_heapify(int A[], int index)
{
    int left_child_index = get_left_child(A, index);
    int right_child_index = get_right_child(A, index);

    // finding largest among index, left child and right child
    int largest = index;

    if ((left_child_index <= heap_size) && (left_child_index > 0))
    {
        if (A[left_child_index] > A[largest])
        {
            largest = left_child_index;
        }
    }

    if ((right_child_index <= heap_size && (right_child_index > 0)))
    {
        if (A[right_child_index] > A[largest])
        {
            largest = right_child_index;
        }
    }

    // largest is not the node, node is not a heap
    if (largest != index)
    {
        swap(&A[index], &A[largest]);
        max_heapify(A, largest);
    }
}

// Function to build Max Heap
void build_max_heap(int A[])
{
    int i;
    for (i = heap_size / 2; i >= 1; i--)
    {
        max_heapify(A, i);
    }
}

// In a Maximum Heap
// The topmost element on the top is maximum
// this function will return the maximum element
//  but it won't remove it from the heap
int maximum(int A[])
{
    return A[1];
}

// This function will return the maximum element
// and remove it from the heap as well
int extract_max(int A[])
{
    int maxm = A[1];
    A[1] = A[heap_size];
    heap_size--;
    max_heapify(A, 1);
    return maxm;
}

// Function to increase the key
void key_increase(int A[], int index, int key)
{
    A[index] = key;
    while ((index > 1) && (A[get_parent(A, index)] < A[index]))
    {
        swap(&A[index], &A[get_parent(A, index)]);
        index = get_parent(A, index);
    }
}

// Function to Decrease the key
void key_decrease(int A[], int index, int key)
{
    A[index] = key;
    max_heapify(A, index);
}

// Function to add new key in Heap
void insert(int A[], int key)
{
    heap_size++;
    A[heap_size] = -1 * INF;
    key_increase(A, heap_size, key);
}

// Print Heap
void print_heap(int A[])
{
    int i;
    printf("The Elements in Heap are\n");
    for (i = 1; i <= heap_size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[tree_size];
    insert(A, 20);
    insert(A, 15);
    insert(A, 8);
    insert(A, 10);
    insert(A, 5);
    insert(A, 7);
    insert(A, 6);
    insert(A, 2);
    insert(A, 9);
    insert(A, 1);

    print_heap(A);

    key_increase(A, 5, 22);

    key_decrease(A, 1, 13);
    print_heap(A);

    printf("The Maximum Element in Heap is:\n");
    printf("%d\n\n", maximum(A));

    print_heap(A);

    printf("Extracting Maximum Elements:\n");
    printf("%d ", extract_max(A));
    printf("%d ", extract_max(A));
    printf("%d ", extract_max(A));
    printf("%d ", extract_max(A));
    printf("%d ", extract_max(A));
    printf("%d ", extract_max(A));
    printf("%d ", extract_max(A));
    printf("%d ", extract_max(A));
    printf("%d ", extract_max(A));
    printf("\n");
    return 0;
}