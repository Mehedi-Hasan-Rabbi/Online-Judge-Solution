#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, c, k; cin >> a >> b >> c >> k;
    ll l = 0, r = 100000;
    ll x = 100000;

    while (l <= r) {
        ll mid = l + (r - l) / 2LL;
        ll val = (a * mid * mid) + (b * mid) + c;

        if (val == k) {
            x = mid;
            break;
        }
        else if (val < k) l = mid + 1;
        else {
            r = mid - 1;
            x = min(x, mid);
        }
    }
    
    cout << x << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}