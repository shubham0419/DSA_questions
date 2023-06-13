#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int preArr[n + 1] = {0};
    int l, r;
    cin >> l >> r;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        preArr[i] = sum;
    }

    if (l > 0)
    {
        cout << preArr[r] - preArr[l - 1];
    }
    else
    {
        cout << preArr[r];
    }
}
// 3 6 7  8  9  10 4  5
// 3 9 16 24 33 43 47 52
