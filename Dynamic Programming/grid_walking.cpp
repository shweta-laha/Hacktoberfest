#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gwalk(ll m , ll n){
	ll dp[m][n];
	ll i,j;
	for(i=0;i<m;i++){
		dp[i][n-1] = 1;
	}
	for(j=0;j<n;j++){
		dp[m-1][j] =1;			
	}
	for (i = m-2; i>=0; i--)
	{
		for(j=n-2; j>=0; j--){
			dp[i][j] = dp[i+1][j] + dp[i][j+1];
		}
	}
	return dp[0][0];
}

int main()
{
	ll m,n;
	cin>>m>>n;
	cout << gwalk(m,n);
	return 0;
}