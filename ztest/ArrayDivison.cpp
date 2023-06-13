#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2 == 1)
    {
        cout << Yes;
        return 0;
    }

    sum = sum / 2;

    int p[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        p[i] = (i == 0 ? a[i] : a[i] + a[i - 1]);
        if (a[p[i] - sum])
    }

    return 0;
}
