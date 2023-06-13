#include <bits/stdc++.h>
using namespace std;
#define int long long
int cont = 0;
int combine(string &s)
{
    int ans = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 's')
        {
            count++;
        }
        else
        {
            ans = ans + count;
        }
    }
    return ans;
}

bool compare(string &s, string &t)
{

    string s1 = s + t;
    string s2 = t + s;

    int opt1 = combine(s1);
    int opt2 = combine(s2);
    cont += max(opt1, opt2);
    return opt1 > opt2;
}

int32_t main()
{
    int n;
    cin >> n;

    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n, compare);
    cout << cont;
}