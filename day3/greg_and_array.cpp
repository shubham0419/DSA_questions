// https://codeforces.com/problemset/problem/295/A/
#include <bits/stdc++.h>
using namespace std;
#define size 100100

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int l[size] = {0}, r[size] = {0}, d[size] = {0};

    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
    }

    int ope[size] = {0};

    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        ope[x] += 1;
        ope[y + 1] -= 1;
    }
    for (int i = 1; i <= m; i++)
    {
        ope[i] += ope[i - 1];
    }

    int pref[size] = {0};
    for (int i = 1; i < size; i++)
    {
        pref[l[i]] += ope[i] * d[i];
        pref[r[i] + 1] -= ope[i] * d[i];
    }
    for (int i = 1; i < size; i++)
    {
        pref[i] += pref[i - 1];
    }

    for (int i = 1; i < size; i++)
    {
        a[i] += pref[i];
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
