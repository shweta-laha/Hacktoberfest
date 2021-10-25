/**
 *
 * A disjoint set data structure (also called Union find or merge find set)
 * is a data structure that tracks a set of elements partitioned into a number
 * of disjoint (non-overlapping) subsets.
 * Some situations where disjoint sets can be used are-
 * to find connected components of a graph, kruskal's algorithm for finding
 * Minimum Spanning Tree etc.
 * There are two operation which we perform on disjoint sets -
 * 1) Union
 * 2) Find
 *
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> root;
vector<int> ranks;

/**
 *
 * Function to create a set
 * n is passed as parameter which is number of elements
 *
 */
void Create_set(int n)
{
    root.resize(n + 1);
    ranks.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
    }
}

/**
 *
 * Find operation takes a number x and returns the set to which this number
 * belongs to.
 * X is given as parameter
 * the function returns the set to which x belongs to
 *
 */
int Find(int x)
{
    if (root[x] == x)
    {
        return x;
    }
    return root[x] = Find(root[x]);
}

/**
 *
 * A utility function to check if x and y are from same set or not
 *
 */
bool SameCheckUnionCheck(int x, int y) { return Find(x) == Find(y); }

/**
 *
 * CheckUnion operation combines two disjoint sets to make a single set
 * in this CheckUnion function we pass two elements and check if they are
 * from different sets then combine those sets
 *
 */
void CheckUnion(int x, int y)
{
    int a = Find(x), b = Find(y);
    if (a != b)
    {
        if (ranks[a] < ranks[b])
        {
            root[a] = b;
        }
        else if (ranks[a] > ranks[b])
        {
            root[b] = a;
        }
        else
        {
            root[a] = b;
            ++ranks[b];
        }
    }
}

/** Main function */
int main()
{
    // Tests CreateSet & Find
    int n = 100;
    Create_set(n);
    for (int i = 1; i <= 100; ++i)
    {
        if (root[i] != i)
        {
            cout << "Fail" << endl;
            break;
        }
    }
    // tests SameCheckUnionCheck & CheckUnion
    cout << "1 and 2 are initially not in the same subset" << endl;
    if (SameCheckUnionCheck(1, 2))
    {
        cout << "Fail" << endl;
    }
    CheckUnion(1, 2);
    cout << "1 and 2 are now in the same subset" << endl;
    if (!SameCheckUnionCheck(1, 2))
    {
        cout << "Fail" << endl;
    }
    return 0;
}