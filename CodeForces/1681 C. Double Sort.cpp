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
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<pair<int, int>> p;
    p.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        p.push_back({a[i], b[i]});
    }

    int ans = 0;
    vector<pair<int, int>> idx;

    for (int i = 1; i <= n; i++) {
        int mn_idx = min_element(p.begin() + i, p.end()) - p.begin();

        if (mn_idx != i) {
            swap(p[i], p[mn_idx]);
            ans++;
            idx.push_back({i, mn_idx});
        }
    }

    for (int i = 1; i <= n; i++) {
        a[i] = p[i].first;
        b[i] = p[i].second;
    }

    if (is_sorted(a.begin(), a.end()) and is_sorted(b.begin(), b.end())) {
        cout << ans << endl;
        if (ans != 0) {
            for (auto u: idx) 
                cout << u.first << " " << u.second << endl;
            cout << endl;
        }
    }
    else cout << -1 << endl;
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