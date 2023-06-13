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

    int prefixArrOper[n + 1] = {0};

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, z;
        cin >> l >> r >> z;
        prefixArrOper[l] += z;
        prefixArrOper[r + 1] -= z;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += prefixArrOper[i];
        prefixArrOper[i] = sum;
    }

    cout << "Array :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        arr[i] += prefixArrOper[i];
    }

    cout << "Array after operation: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}