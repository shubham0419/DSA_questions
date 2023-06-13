#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

bool compare(pair<int, int> x, pair<int, int> y)
{
    return x.second < y.second;
}

int EassyCount(vector<pair<int, int>> &p, int sum, int avg, int mx)
{
    int count = 0;
    sort(p.begin(), p.end(), compare);

    for (int i = 0; i < n; i++)
    {
        if (p[i].first < mx)
        {
            // cout << p[i].first++;
            while (p[i].first < mx && sum < avg)
            {
                // cout << p[i].second << endl;
                p[i].first++;
                count += p[i].second;
                sum++;
            }
        }
    }
    return count;
}

int32_t main()
{
    int mx, avg;
    cin >> n >> mx >> avg;

    vector<pair<int, int>> p;
    avg = avg * n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        sum += x;
        if (sum >= avg)
        {
            cout << 0;
            return 0;
        }
        p.push_back({x, y});
    }

    cout << EassyCount(p, sum, avg, mx);
    return 0;
}
