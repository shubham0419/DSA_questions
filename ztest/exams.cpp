#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isExam(int n, int m, const vector<int> ExamDayMap[], int *prepDays, int days)
{
    vector<pair<int, int>> p;

    for (int i = 1; i <= m; i++)
    {

        auto it = upper_bound(ExamDayMap[i].begin(), ExamDayMap[i].end(), days);

        if (it == ExamDayMap[i].begin())
        {
            return false;
        }

        p.push_back(make_pair(*(--it), i));
    }

    sort(p.begin(), p.end());

    int lastExamDay = 0, bufferDay = 0, availableDays = 0, prep = 0;

    for (auto x : p)
    {
        int sub = x.second;
        int examDay = x.first;
        availableDays = examDay + bufferDay - lastExamDay;
        prep = prepDays[sub] + 1;

        if (prep > availableDays)
        {
            return false;
        }
        bufferDay = availableDays - prep;
        lastExamDay = examDay;
    }
    return true;
}

int minDay(int n, int m, const vector<int> ExamDayMap[], int *prepDays)
{
    int s = 1;
    int e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isExam(n, m, ExamDayMap, prepDays, mid))
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    int *date = new int[n + 1];
    int *prepDays = new int[m + 1];

    vector<int> ExamDayMap[100002];

    for (int i = 1; i <= n; i++)
    {
        cin >> date[i];
        if (date[i] == 0)
        {
            continue;
        }
        ExamDayMap[date[i]].push_back(i);
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> prepDays[i];
    }

    int ans = minDay(n, m, ExamDayMap, prepDays);
    if (ans > 0)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
    return 0;
}