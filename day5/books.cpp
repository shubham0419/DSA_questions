// https://codeforces.com/problemset/problem/279/B
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int t_count = 0;
    int book = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        t_count += a[i];
        book++;
        if (t_count > t)
        {
            t_count -= a[j];
            j++;
            book--;
        }
    }
    cout << book;
    return 0;
}