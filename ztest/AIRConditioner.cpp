#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
#define int long long
int a[N];
int l[N], r[N];

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, temp;
        cin >> n >> temp;
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> l[i] >> r[i];
        }

        int prev_temp = 0;
        int mn = temp;
        int mx = temp;

        for (int i = 0; i < n; i++)
        {
            mx += (a[i] - prev_temp);
            mn -= (a[i] - prev_temp);

            if (mx < l[i] || mn > r[i])
            {
                flag = 0;
                break;
            }

            mx = min(r[i], mx);
            mn = max(l[i], mn);

            prev_temp = a[i];
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
