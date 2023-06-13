#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> &a, int k, int x)
{
    vector<int> ans;
    int i = 0, j;
    for (auto it : a)
    {
        if (it > x)
            break;
        i++;
    }
    cout << i << endl;
    j = i;
    i--;
    while (k && i >= 0 && j < a.size())
    {
        if (abs(a[i] - x) > abs(a[j] - x))
        {
            k--;
            ans.push_back(a[j]);
            j++;
        }
        else
        {
            k--;
            ans.push_back(a[i]);
            i--;
        }
    }
    while (k && i >= 0)
    {
        ans.push_back(a[i]);
        k--;
        i--;
    }
    while (k && j < a.size())
    {
        ans.push_back(a[j]);
        k--;
        j++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> v = {0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
    vector<int> ans = findClosestElements(v, 3, 5);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}