#include <bits/stdc++.h>
using namespace std;
#define N 1001
#define mod 1000000007
int n, m;
int grid[N][N] = {0};

int getans()
{
    if (grid[1][1] == 1 or grid[n][m] == 1)
        return 0;

    int dp[n + 1][m + 1] = {0};
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;

            if (grid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i == 1)
                {
                    dp[i][j] = dp[i][j - 1] % mod;
                }
                else if (j == 1)
                {
                    dp[i][j] = dp[i - 1][j] % mod;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                }
            }
        }
    }
    return dp[n][m];
}

int main()
{
    // your code goes here
    cin >> n >> m;
    int t;
    cin >> t;
    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        grid[x][y] = 1;
    }

    cout << getans();

    return 0;
}
