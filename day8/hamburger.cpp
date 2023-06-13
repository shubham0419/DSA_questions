#include <bits/stdc++.h>
using namespace std;
#define val 100000100
string a;
int nb, nc, ns, pb, pc, ps, r;

int solve()
{
    int ans = -1;
    int s = 0, e = val;
    int sb = 0, ss = 0, sc = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == 'B')
        {
            sb++;
        }
        else if (a[i] == 'S')
        {
            ss++;
        }
        else
        {
            sc++;
        }
    }
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int tb = (((mid * sb) - nb) * pb) < 0 ? 0 : (((mid * sb) - nb) * pb);
        int ts = (((mid * ss) - ns) * ps) < 0 ? 0 : (((mid * ss) - ns) * ps);
        int tc = (((mid * sc) - nc) * pc) < 0 ? 0 : (((mid * sc) - nc) * pc);

        int total = tb + tc + ts;

        if (total <= r)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    cin >> a;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    cout << solve();
    return 0;
}
