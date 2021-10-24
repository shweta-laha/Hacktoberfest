#include <bits/stdc++.h>
using namespace std;

int coin_cha(int coin[], int amount, int n){
	int dp[n+1][amount+1];
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=amount;j++){

			if (i==0 and j!=0)
				dp[i][j]=0;
			else if(j==0) dp[i][j]=1;
			else{
				if(j<coin[i-1])
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j]=dp[i][j-coin[i-1]]+ dp[i-1][j];
			}
		}
	}
	return dp[n][amount];
}

int main()
{
	int coin[] = {5,3,2};
	int amount = 15;
	cout << coin_cha(coin,amount,3)<<endl;
	return 0;
}