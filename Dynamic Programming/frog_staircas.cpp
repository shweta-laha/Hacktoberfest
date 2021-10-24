#include <bits/stdc++.h>
using namespace std;

int frog(int n){
	int a[n];
	a[0]=1;
	a[1]=1;
	for (int i = 2; i <=n; ++i)
	{
		a[i] = a[i-1]+a[i-2];
	}
	return a[n];
}

int main()
{
	int n;
	cin>>n;
	cout<< frog(n);
	return 0;
}