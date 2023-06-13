#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
int dp[N][N];

// https://atcoder.jp/contests/dp/tasks/dp_f

string getstr(string &s, string &t, int len)
{
    string ans;
    int i = 0;
    int j = 0;

    while (len > 0)
    {
        if (s[i] == t[j])
        {
            ans.push_back(s[i]);
            i++;
            j++;
            len--;
        }
        else
        {

            if (dp[i][j + 1] > dp[i + 1][j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    return ans;
}

int getlen(string &s, string &t, int i, int j)
{
    if (i >= s.length() || j >= t.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = 1 + getlen(s, t, i + 1, j + 1);
    }
    else
    {
        int op1 = getlen(s, t, i + 1, j);
        int op2 = getlen(s, t, i, j + 1);

        return dp[i][j] = max(op1, op2);
    }
}

string getans(string s, string t)
{
    memset(dp, -1, sizeof(dp));

    int len = getlen(s, t, 0, 0);
    // return len;
    string LCS = getstr(s, t, len);
    return LCS;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << getans(s, t);
    return 0;
}