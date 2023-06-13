#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int ans = 0;

    while (x != 0)
    {
        ans = ((ans * 10) + x % 10);
        x /= 10;
    }
    return ans;
}
int main()
{
    cout << reverse(-123);
    return 0;
}