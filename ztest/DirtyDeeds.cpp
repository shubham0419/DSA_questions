#include <bits/stdc++.h>
using namespace std;
#define int long long

bool compare(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y)
{
    return x.second.first < y.second.first;
}

bool compare1(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y)
{
    return x.first < y.first;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> a, b;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
        {
            a.push_back({x, {y, i + 1}});
        }
        else
        {
            b.push_back({x, {y, i + 1}});
        }
    }

    if (a.size() > b.size())
    {
        sort(a.begin(), a.end(), compare);
        cout << a.size() << endl;
        for (auto x : a)
        {
            pair<int, int> p = x.second;
            cout << p.second << " ";
        }
    }
    else
    {
        sort(b.begin(), b.end(), compare1);
        cout << b.size() << endl;
        for (auto x : b)
        {
            pair<int, int> p = x.second;
            cout << p.second << " ";
        }
    }

    return 0;
}
