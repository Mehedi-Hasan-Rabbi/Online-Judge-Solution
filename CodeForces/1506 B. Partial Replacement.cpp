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

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '*') {
            r = i;
            break;
        }
    }

    s[l] = 'x', s[r] = 'x';

    if (l == r) cout << 1 << endl;
    else {
        ll ans = 2;
        int cnt = 0, idx = l + 1;
        for (int i = l + 1; i < r; i++) {
            if (s[i] == '*') idx = max(i, idx);
            cnt++;
            if (cnt == k) {
                s[idx] = 'x';
                ans++;
                cnt = 0;
                i = idx;
            }
        }
        cout << ans << endl;
    }
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}