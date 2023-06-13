#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n - 1; i += 2)
    {
        ans += min(a[i], a[i + 1]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(a, n);
    return 0;
}