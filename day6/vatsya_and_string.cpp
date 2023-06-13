#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;

int solve(char x)
{
    int ans = INT_MIN;
    int count = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != x)
        {
            count++;
        }
        while (count > k && j <= i)
        {
            if (s[j] != x)
            {
                count--;
            }
            j++;
        }
        if (i - j + 1 > ans)
        {
            ans = i - j + 1;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    cin >> s;
    cout << max(solve('a'), solve('b'));
    return 0;
}
