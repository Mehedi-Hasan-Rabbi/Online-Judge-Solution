#include <bits/stdc++.h>
using namespace std;

#define int long long

int a, b, c;
void solve(void)
{
    cin >> a >> b >> c;
    int cp = 1, mn = 0, prb = 0, res = 1e18;
    for (int i = 0; i < 32; i++)
    {
        res = min(i * a + ((c / cp + (c % cp > 0)) * b), res);
        cp *= 2;
    }
    cout << res << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}