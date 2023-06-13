#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++)
    {
        int cont = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i] >= a[j])
            {
                cont++;
            }
        }
        cout << cont << " ";
    }

    return 0;
}
