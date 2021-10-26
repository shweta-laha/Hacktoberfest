#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, m;
int dx1[] = {1, 1, 0, 0};
int dy1[] = {0, 0, 1, 1};
int dx2[] = {1, 0, 1, 0};
int dy2[] = {0, 1, 0, 1};
int dp[105][105][105];
char c[105][105];
int solve(int x1, int y1, int x2, int y2) {
	if ( x1 > n or y1 > m or x2 > n or y2 > m or c[x1][y1] == '#' or c[x2][y2] == '#')
		return INT_MIN;
	if (x1 == n and y1 == m)
		return (c[x1][y1] == '*');
	if (dp[x1][x2][y1] != -1)
		return dp[x1][x2][y1];
	int res = INT_MIN;
	for (int i = 0; i < 4; i++) {
		res = max(res, solve(x1 + dx1[i], y1 + dy1[i], x2 + dx2[i], y2 + dy2[i]));
	}
	res += (c[x1][y1] == '*');
	res += (c[x2][y2] == '*');
	if ( x1 == x2 and y1 == y2 and c[x1][y1] == '*')
		res--;
	return dp[x1][x2][y1] = res;
}
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(x) {
		memset(dp, -1, sizeof(dp));
		cin >> m >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c[i][j];
			}
		}
		cout << solve(1, 1, 1, 1) << "\n";
	}

}

int32_t main()
{
	c_p_c();
	return 0;
}