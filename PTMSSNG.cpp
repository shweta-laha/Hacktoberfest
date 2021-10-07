/* https://www.codechef.com/problems/PTMSSNG */
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll res1=0,res2=0;
		// Check which duplicate value doesn't exist.
		for(int i=0;i<(4*n-1);i++){
			ll x,y;
			cin>>x>>y;
			res1^=x; // Xor operations
			res2^=y;
		}
		cout<<res1<<" "<<res2<<endl;
	}
}