#include <bits/stdc++.h>
using namespace std;

int SoR(int arr[], int i, int j, int n){
	int dp[n];
	int k;
	dp[0] = arr[0];
	
	for(k=1;k<n;k++){
		dp[k] = arr[k]+dp[k-1];
	}

	if (i==0)
		return dp[j];
	else
		return dp[j] - dp[i-1];
}

int main()
{
	int arr[]={10,14,5,-10,3};
	int n =5;
	cout<<SoR(arr,2,4,n)<<endl;
	cout<<SoR(arr,1,3,n)<<endl;

	return 0;
}