#include <iostream>
using namespace std;
void mergesort(int*, int, int);
void merge(int*, int, int, int);
void printArray(int*, int);
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printArray(arr, n);
    mergesort(arr, 0, n-1);
    cout<<"\nAfter sorting : "<<endl;
    printArray(arr, n);
}
void mergesort(int arr[], int lb, int ub)
{
    int mid;
    if(lb<ub){
        mid = (lb+ub)/2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int arr[], int lb, int mid, int ub)
{
    int i=lb, j=mid+1, k=lb;
    int b[ub+1];
    while(i<=mid && j<=ub){
        if(arr[i]<arr[j]){
            b[k] = arr[i];
            i++;
        }
        else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k] = arr[j];
            j++; k++;
        }
    }
    else if(j>ub){
        while(i<=mid){
            b[k] = arr[i];
            i++; k++;
        }
    }
    for(k=lb;k<=ub;k++){
        arr[k] = b[k];
    }
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
