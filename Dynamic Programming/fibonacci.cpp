#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fib(ll n){
	ll dp[n];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}

int main()
{
	ll n;
	cin>>n;
	cout<<"Fibonacci of n is: "<< fib(n)<<endl;
	return 0;
}