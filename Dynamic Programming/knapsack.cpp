#include <bits/stdc++.h>
using namespace std;

void knapsak(int n, int w, int wt[], int profit[]){
	int dp[n+1][w+1];
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			if(i==0 or j==0) dp[i][j] =0;
			else if(wt[i-1]>j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j-wt[i-1]]+profit[i-1], dp[i-1][j]);
		}
	}
	cout << "Answer: "<< dp[n][w];
}

int main()
{
	int wt[4]= {2,3,4,5};
	int profit[4]  = {10, 50,30,20};
	int W =5;
	knapsak(4,W,wt,profit);

	return 0;
}