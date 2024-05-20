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
typedef pair<int, int> pii;
typedef vector<int> vi;

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
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> triple;
    for (int i = 0; i < n -  2; i ++) triple.push_back( {a[i], a[i+1], a[i+2]} );
    
    ll ans = 0;

    // Check last two number same
    map<pii, vi> last_two;
    for (auto u: triple) {
        pii last = {u[1], u[2]};
        int first = u[0];
        last_two[last].push_back(first);
    }

    for (auto &&[key, val]: last_two) {
        sort(val.begin(), val.end());
        int sz = val.size();
        for (int i = 0; i < sz; i++) {
            int idx = lower_bound(val.begin(), val.end(), (val[i] + 1) ) - val.begin();
            if (idx < sz) {
                ans += (sz - idx);
            }
            else break;
        }
    }
    // dbg(ans);

    // Check first two number same
    map<pii, vi> first_two;
    for (auto u: triple) {
        pii first = {u[0], u[1]};
        int last = u[2];
        first_two[first].push_back(last);
    }

    for (auto &&[key, val]: first_two) {
        sort(val.begin(), val.end());
        int sz = val.size();
        for (int i = 0; i < sz; i++) {
            int idx = lower_bound(val.begin(), val.end(), (val[i] + 1) ) - val.begin();
            if (idx < sz) {
                ans += (sz - idx);
            }
            else break;
        }
    }
    // dbg(ans);

    // Check Fisrt and last number same
    map<pii, vi> diff;
    for (auto u: triple) {
        pii first = {u[0], u[2]};
        int last = u[1];
        diff[first].push_back(last);
    }

    for (auto &&[key, val]: diff) {
        sort(val.begin(), val.end());
        int sz = val.size();
        for (int i = 0; i < sz; i++) {
            int idx = lower_bound(val.begin(), val.end(), (val[i] + 1) ) - val.begin();
            if (idx < sz) {
                ans += (sz - idx);
            }
            else break;
        }
    }
    // dbg(ans);

    cout << ans << endl;
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