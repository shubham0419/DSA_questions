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
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int freqArr[max + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        freqArr[arr[i]] += 1;
    }

    for (int i = 0; i < max + 1; i++)
    {
        if (freqArr[i] > 0)
        {
            cout << "frequency of " << i << " is " << freqArr[i] << endl;
        }
    }
    for (int i = 0; i < max + 1; i++)
    {
        cout << freqArr[i] << " ";
    }
    return 0;
}