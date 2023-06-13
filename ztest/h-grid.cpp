#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
#define mod 1000000007
char grid[N][N];

// https://atcoder.jp/contests/dp/tasks/dp_h

int getpaths(int n, int m)
{
    int dp[n + 1][m + 1] = {0};
    dp[n][m] = 1;

    for (int i = n; i > 0; i--)
    {
        for (int j = m; j > 0; j--)
        {
            if (i == n && j == m)
            {
                continue;
            }
            if (grid[i][j] == '#')
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i == n)
                {
                    dp[i][j] = dp[i][j + 1] % mod;
                }
                else if (j == m)
                {
                    dp[i][j] = dp[i + 1][j] % mod;
                }
                else
                {
                    dp[i][j] = (dp[i][j + 1] + dp[i + 1][j]) % mod;
                }
            }
        }
    }
    return dp[1][1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << getpaths(n, m);
    return 0;
}