// https://codeforces.com/problemset/problem/296/C#:~:text=Problem%20%2D%20296C%20%2D%20Codeforces&text=Greg%20has%20an%20array%20a,i%20by%20value%20d%20i
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define size 100100

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int l[size] = {0}, r[size] = {0}, d[size] = {0};
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
    }

    int ope_count[size] = {0};
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        ope_count[x] += 1;
        ope_count[y + 1] -= 1;
    }

    for (int i = 1; i <= m; i++)
    {
        ope_count[i] += ope_count[i - 1];
    }

    int diff_sum[size] = {0};
    for (int i = 1; i < size; i++)
    {
        diff_sum[l[i]] += (ope_count[i] * d[i]);
        diff_sum[r[i] + 1] -= (ope_count[i] * d[i]);
    }

    for (int i = 1; i < size; i++)
    {
        diff_sum[i] += diff_sum[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] += diff_sum[i];
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
