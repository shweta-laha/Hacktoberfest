#include <iostream>
void swap(int *p1, int *p2)
{
int temp = *p1;
*p1 = *p2;
*p2 = temp;
}

void bSort(int arrnumbers[], int n)
{
int i, j;
bool check;
for (i = 0; i < n-1; i++)
{
check = false;
for (j = 0; j < n-i-1; j++)
{
if (arrnumbers[j] > arrnumbers[j+1])
{
swap(&arrnumbers[j], &arrnumbers[j+1]);
check = true;
}
}

if (check == false)
break;
}
}

void print(int arrnumbers[], int sizeofarray)
{
int i;
for (i=0; i < sizeofarray; i++)
printf("%d ", arrnumbers[i]);
}

int main()
{
int arrnumbers[] = {10,100,90,80,40,30,20,60,50,70};
int n = sizeof(arrnumbers)/sizeof(arrnumbers[0]);
bSort(arrnumbers, n);
printf("Sorted array: \n");
print(arrnumbers, n);
return 0;
}
