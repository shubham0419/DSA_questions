#include <bits/stdc++.h>
#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    vector<int> ans;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            ans.push_back(a[i++]);
        }
        else
        {
            ans.push_back(b[j++]);
        }
    }
    while (j < m)
    {
        ans.push_back(b[j++]);
    }
    while (i < n)
    {
        ans.push_back(a[i++]);
    }

    double med = 0;

    if (ans.size() % 2 == 1)
    {
        med = ans[ans.size() / 2];
    }
    else
    {
        double sum = (ans[ans.size() / 2] + ans[(ans.size() / 2) - 1]);
        med = sum / 2;
    }
    return med;
}

int main()
{
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};

    cout << findMedianSortedArrays(a, b);
    return 0;
}