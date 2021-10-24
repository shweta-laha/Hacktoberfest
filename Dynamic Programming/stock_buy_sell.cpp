#include <bits/stdc++.h>
using namespace std;

int sbs(int a[],int n){
	int dp[n];
	dp[0]=a[0];
	for(int i=1;i<n;i++)
		dp[i] = min(a[i],dp[i-1]);
	int max = a[0] - dp[0];

	for(int i=1;i<n;i++)
		if (max < a[i]-dp[i])
		{
			max = a[i]-dp[i];
		}
	return max;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n;i++)
		cin>>a[i];
	cout << sbs(a,n);
	return 0;
}