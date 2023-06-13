#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n, m;
    cin >> n >> m;

    int a[n];
    int freq[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        freq[a - 1]++;
        freq[b]--;
    }

    for (int i = 0; i < n; i++)
    {
        freq[i] = (i == 0 ? freq[i] : (freq[i] + freq[i - 1]));
    }

    sort(a, a + n);
    sort(freq, freq + n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += (freq[i] * a[i]);
    }
    cout << ans;

    return 0;
}
