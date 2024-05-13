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
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> monster(n);
    for (int i = 0; i < n; i++) cin >> monster[i].first;
    for (int i = 0; i < n; i++) cin >> monster[i].second;

    sort(monster.begin(), monster.end());
    if (n >= 2) {
        for (int i = n - 2; i >= 0; i--) 
            monster[i].second = min(monster[i].second, monster[i + 1].second);
    }

    vector<ll> h, p;
    for (auto u: monster) {
        h.push_back(u.first);
        p.push_back(u.second);
    }
    
    ll pow = k, idx = -1;
    while (true) {
        idx = upper_bound(h.begin(), h.end(), pow) - h.begin();

        if (idx == n or k < p[idx]) break;
        k = k - p[idx];
        pow += k;
        
    }

    if (idx == n) cout << "YES" << endl;
    else cout << "NO" << endl;
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