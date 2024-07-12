// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/Debug.h"
#else
#define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n; cin >> n;

    vector<ll> section(32, 0), pref(32, 0), start(32, 0);
    for (ll i = 1; i < 32; i++) {
        section[i] = (1LL << i);
        pref[i] = pref[i - 1] + section[i];
    }

    for (ll i = 1; i < 32 - 1; i++) {
        ll val = 1LL << (i - 1);
        start[i + 1] = start[i] + val;
    }

    string ans = "";
    int idx = 0;
    for (int i = 0; i < 32; i++) {
        if (pref[i] >= n) {
            idx = i;
            break;
        }
    }

    while (n != 0) {
        int val = n - pref[idx - 1];
        if (val % 2 == 0) ans += "B";
        else ans += "A";

        val = start[idx] + (val / 2) + (val % 2 == 1) - 1;
        n = val;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main(void) {
    efficient();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}