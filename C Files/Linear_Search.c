#include <iostream>
using namespace std;

//Linear Search Function 
int linear_search(int arr[], int n, int search_item)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == search_item)
            return i;
    return -1;
}
 
//Printing Output
void print(int result)
{
    if(result == -1)
    {
        cout << "Search Element is not present in array";
    }        
    else
    {
        cout << "Search Element is present at index: " << result;
    }
}
// Driver code
int main(void)
{
    int arr[] = { 50, 76, 49, 42, 16,10,64,9 };// array where item is to be searched
    int search_item = 16;// item to be searched
    int n = sizeof(arr) / sizeof(arr[0]);//finding the size of array
       
    int result = linear_search(arr, n, search_item);// Function call
    print(result);
    return 0;
}