#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	int  ele,j,i;
	for (i = 1; i < n; i++)
	{
		ele = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > ele)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = ele;
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 22, 1, 13, 51, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array before sorting: \n";
	printArray(arr, n);
    cout<<"Array after Sorting: \n";
    insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}

