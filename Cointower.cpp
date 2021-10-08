#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
if (x > y)
{
swap(x, y);
}
bool *dp = new bool[n + 1];
for (int i = 1; i <= n; ++i)
{
if (i == 1 || i == x || i == y)
{
dp[i] = true;
}
else if (i < x)
{
dp[i] = !dp[i - 1];
}
else if (i < y)
{
dp[i] = !(dp[i - x] && dp[i - 1]);
}
else
    {
dp[i] = !(dp[i - x] && dp[i - y] && dp[i - 1]);
}
}
bool result = dp[n];
delete[] dp;
if (result)
{
return "Beerus";
}
else
{
return "Whis";
}
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}
